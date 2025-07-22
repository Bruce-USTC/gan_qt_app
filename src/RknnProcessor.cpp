#include "RknnProcessor.h"
#include <QFile>
#include <QDebug>
#include <QElapsedTimer>
#include <vector>
#include <opencv2/opencv.hpp>

// 辅助函数：读取文件内容 (无变化)
static unsigned char* load_file(const char* filename, int* model_size) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file:" << filename;
        return nullptr;
    }
    *model_size = file.size();
    unsigned char* model_data = (unsigned char*)malloc(*model_size);
    if (!model_data) {
        qWarning() << "Failed to allocate memory for model.";
        file.close();
        return nullptr;
    }
    file.read((char*)model_data, *model_size);
    file.close();
    return model_data;
}

RknnProcessor::RknnProcessor(QObject *parent) : QObject(parent) {}

RknnProcessor::~RknnProcessor() {
    if (input_attrs_) delete[] input_attrs_;
    if (output_attrs_) delete[] output_attrs_;
    if (rknn_ctx_) {
        rknn_destroy(rknn_ctx_);
    }
}

void RknnProcessor::initialize(const QString &modelPath) {
    // ... 此部分无变化 ...
    qDebug() << "Initializing RKNN with model:" << modelPath;

    int model_data_size = 0;
    unsigned char* model_data = load_file(modelPath.toStdString().c_str(), &model_data_size);
    if (!model_data) {
        emit initReady(false, "错误：无法加载RKNN模型文件！");
        return;
    }

    int ret = rknn_init(&rknn_ctx_, model_data, model_data_size, 0, nullptr);
    free(model_data);

    if (ret < 0) {
        emit initReady(false, QString("错误：rknn_init 失败! ret=%1").arg(ret));
        return;
    }

    ret = rknn_query(rknn_ctx_, RKNN_QUERY_IN_OUT_NUM, &io_num_, sizeof(io_num_));
    if (ret < 0) {
        emit initReady(false, QString("错误：rknn_query(IO_NUM) 失败! ret=%1").arg(ret));
        return;
    }

    input_attrs_ = new rknn_tensor_attr[io_num_.n_input];
    output_attrs_ = new rknn_tensor_attr[io_num_.n_output];
    
    for (uint32_t i = 0; i < io_num_.n_input; i++) {
        input_attrs_[i].index = i;
        rknn_query(rknn_ctx_, RKNN_QUERY_INPUT_ATTR, &(input_attrs_[i]), sizeof(rknn_tensor_attr));
    }
    for (uint32_t i = 0; i < io_num_.n_output; i++) {
        output_attrs_[i].index = i;
        rknn_query(rknn_ctx_, RKNN_QUERY_OUTPUT_ATTR, &(output_attrs_[i]), sizeof(rknn_tensor_attr));
    }
    
    is_initialized_ = true;
    emit initReady(true, "NPU初始化成功，请选择图片。");
}

void RknnProcessor::runInference(const QString &imagePath) {
    if (!is_initialized_) {
        emit errorOccurred("错误：RKNN环境未初始化！");
        return;
    }

    QElapsedTimer timer;
    timer.start();

    // 1. 预处理 (无变化)
    cv::Mat orig_img = cv::imread(imagePath.toStdString());
    if (orig_img.empty()) {
        emit errorOccurred("错误：无法读取图片: " + imagePath);
        return;
    }
    cv::Mat img_resized;
    cv::resize(orig_img, img_resized, cv::Size(input_attrs_[0].dims[2], input_attrs_[0].dims[1]));
    cv::Mat img_rgb;
    cv::cvtColor(img_resized, img_rgb, cv::COLOR_BGR2RGB);

    // 2. 设置输入并推理 (无变化)
    rknn_input inputs[1];
    memset(inputs, 0, sizeof(inputs));
    inputs[0].index = 0;
    inputs[0].type = RKNN_TENSOR_UINT8;
    inputs[0].size = img_rgb.cols * img_rgb.rows * img_rgb.channels();
    inputs[0].fmt = RKNN_TENSOR_NHWC;
    inputs[0].buf = img_rgb.data;

    int ret = rknn_inputs_set(rknn_ctx_, io_num_.n_input, inputs);
    if (ret < 0) {
        emit errorOccurred(QString("错误：rknn_inputs_set 失败! ret=%1").arg(ret));
        return;
    }

    ret = rknn_run(rknn_ctx_, nullptr);
    if (ret < 0) {
        emit errorOccurred(QString("错误：rknn_run 失败! ret=%1").arg(ret));
        return;
    }

    // 3. 获取输出 (请求浮点数)
    rknn_output outputs[1];
    memset(outputs, 0, sizeof(outputs));
    outputs[0].want_float = 1; 

    ret = rknn_outputs_get(rknn_ctx_, io_num_.n_output, outputs, nullptr);
    if (ret < 0) {
        emit errorOccurred(QString("错误：rknn_outputs_get 失败! ret=%1").arg(ret));
        return;
    }

    // 4. 后处理 (重写)
    if (io_num_.n_output > 0) {
        // ======================= 关键修正部分 =======================
        cv::Mat resultMat; // 最终用于显示的 uint8 图像
        
        // 打印调试信息，确认模型输出格式
        qDebug() << "Output Tensor Format (0=NCHW, 1=NHWC):" << output_attrs_[0].fmt;

        // 判断维度顺序
        if (output_attrs_[0].fmt == RKNN_TENSOR_NCHW) {
            // 如果是 NCHW (1, C, H, W)
            qDebug() << "Handling NCHW format.";
            int c = output_attrs_[0].dims[1];
            int h = output_attrs_[0].dims[2];
            int w = output_attrs_[0].dims[3];

            // 将连续的内存数据看作一个 (C, H*W) 的2D矩阵
            cv::Mat floatMat(c, h * w, CV_32F, (float*)outputs[0].buf);
            
            std::vector<cv::Mat> channels;
            // 逐个提取每个通道 (每个通道是1行)，并恢复其 HxW 的形状
            for(int i = 0; i < c; ++i) {
                channels.push_back(floatMat.row(i).reshape(1, h));
            }

            // 将分离的通道合并成一个 HWC 格式的图像
            cv::Mat hwcMat;
            cv::merge(channels, hwcMat);

            // 对维度顺序正确的图像进行反归一化
            hwcMat.convertTo(resultMat, CV_8UC3, 127.5, 127.5);

        } else { // 假设是 NHWC (1, H, W, C)
            qDebug() << "Handling NHWC format.";
            int h = output_attrs_[0].dims[1];
            int w = output_attrs_[0].dims[2];
            int c = output_attrs_[0].dims[3];

            // 直接创建一个指向内存的 Mat，它已经是 HWC 格式
            cv::Mat floatMat(h, w, CV_32FC3, (float*)outputs[0].buf);
            
            // 对其进行反归一化
            floatMat.convertTo(resultMat, CV_8UC3, 127.5, 127.5);
        }

        if (resultMat.empty()) {
            emit errorOccurred("错误: 后处理结果为空图像!");
            rknn_outputs_release(rknn_ctx_, io_num_.n_output, outputs);
            return;
        }
        
        // 将 cv::Mat (RGB) 转换为 QImage 以便在UI中显示
        QImage resultImage(resultMat.data, resultMat.cols, resultMat.rows, resultMat.step, QImage::Format_RGB888);
        // =======================================================

        rknn_outputs_release(rknn_ctx_, io_num_.n_output, outputs);

        QString message = QString("转换成功！耗时: %1 ms").arg(timer.elapsed());
        emit inferenceFinished(resultImage.copy(), message);
    } else {
        emit errorOccurred("错误：模型没有输出！");
    }
}
