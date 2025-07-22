#ifndef RKNNPROCESSOR_H
#define RKNNPROCESSOR_H

#include <QObject>
#include <QString>
#include <QImage>

// 引入 RKNN C API 头文件
// 确保你的 include 路径设置正确
#include "rknn_api.h"

class RknnProcessor : public QObject
{
    Q_OBJECT

public:
    explicit RknnProcessor(QObject *parent = nullptr);
    ~RknnProcessor();

signals:
    // --- 信号：用于从工作线程通知主线程 ---

    // 初始化任务完成时发出
    void initReady(bool success, const QString &message);
    
    // 推理任务完成时发出，携带结果图片和状态信息
    void inferenceFinished(const QImage &resultImage, const QString &message);
    
    // 发生错误时发出
    void errorOccurred(const QString &errorMessage);

public slots:
    // --- 槽：由主线程调用以启动在工作线程中的任务 ---

    // 初始化 RKNN 环境和模型
    void initialize(const QString &modelPath);
    
    // 对指定的图片文件执行推理
    void runInference(const QString &imagePath);

private:
    // RKNN 模型上下文句柄
    rknn_context rknn_ctx_ = 0;
    
    // 模型输入输出属性
    rknn_input_output_num io_num_;
    rknn_tensor_attr* input_attrs_ = nullptr;
    rknn_tensor_attr* output_attrs_ = nullptr;

    // 模型是否初始化成功
    bool is_initialized_ = false;
};

#endif // RKNNPROCESSOR_H
