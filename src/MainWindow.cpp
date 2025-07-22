#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QFile> // 需要包含这个头文件来检查文件是否存在

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    processor_ = new RknnProcessor;
    processor_->moveToThread(&workerThread_);

    connect(this, &MainWindow::startInitialization, processor_, &RknnProcessor::initialize);
    connect(this, &MainWindow::startInference, processor_, &RknnProcessor::runInference);
    connect(processor_, &RknnProcessor::initReady, this, &MainWindow::handleInitResult);
    connect(processor_, &RknnProcessor::inferenceFinished, this, &MainWindow::handleInferenceResult);
    connect(processor_, &RknnProcessor::errorOccurred, this, &MainWindow::handleError);
    connect(&workerThread_, &QThread::finished, processor_, &QObject::deleteLater);
    
    // 3. 启动线程
    workerThread_.start();

    // --- 动态寻找模型文件的路径 ---
    QString modelFileName = "wo_scatter_norm_10_pix2pix.rknn";
    QString modelPath;

    // 路径1: 检查当前工作目录下的 "models" 文件夹 (用于开发环境)
    QString devPath = "models/" + modelFileName;
    if (QFile::exists(devPath)) {
        modelPath = devPath;
    } else {
        // 路径2: 检查系统安装路径 (用于安装后的环境)
        QString installPath = "/usr/local/share/SpecGAN/models/" + modelFileName;
        if (QFile::exists(installPath)) {
            modelPath = installPath;
        }
    }

    // 检查是否成功找到模型
    if (modelPath.isEmpty()) {
        // 如果两个地方都没找到，就报错
        QMessageBox::critical(this, "严重错误", "找不到模型文件！\n请确保 'models' 文件夹存在，或程序已正确安装。");
        ui->selectButton->setEnabled(false);
        ui->runButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        statusBar()->showMessage("错误：模型文件丢失！");
    } else {
        // 如果找到了，就触发初始化
        emit startInitialization(modelPath);
        // 初始化UI状态
        ui->runButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        statusBar()->showMessage("正在初始化NPU环境...");
    }
}

MainWindow::~MainWindow()
{
    workerThread_.quit();
    workerThread_.wait();
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "退出程序",
                                                                "您确定要退出吗？",
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::on_selectButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择一张图片", "", "图片文件 (*.png *.jpg *.jpeg *.bmp)");
    if (!filePath.isEmpty()) {
        inputImagePath_ = filePath;
        QPixmap pixmap(filePath);
        ui->inputImageLabel->setPixmap(pixmap.scaled(ui->inputImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        
        ui->outputImageLabel->clear();
        ui->outputImageLabel->setText("输出图片预览");
        
        ui->runButton->setEnabled(true);
        ui->saveButton->setEnabled(false);
        statusBar()->showMessage("已选择图片: " + QFileInfo(filePath).fileName());
    }
}

void MainWindow::on_runButton_clicked()
{
    if (inputImagePath_.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先选择一张图片！");
        return;
    }

    ui->selectButton->setEnabled(false);
    ui->runButton->setEnabled(false);
    statusBar()->showMessage("正在转换中，请稍候...");

    emit startInference(inputImagePath_);
}

void MainWindow::on_saveButton_clicked()
{
    if (outputImage_.isNull()) {
        QMessageBox::warning(this, "提示", "没有可以保存的图片！");
        return;
    }

    QString filter = "PNG 文件 (*.png);;JPEG 文件 (*.jpg)";
    QString selectedFilter;

    QString savePath = QFileDialog::getSaveFileName(this, "保存图片", "", filter, &selectedFilter);

    if (!savePath.isEmpty()) {
        QFileInfo fileInfo(savePath);
        if (fileInfo.suffix().isEmpty()) {
            if (selectedFilter == "PNG 文件 (*.png)") {
                savePath.append(".png");
            } else if (selectedFilter == "JPEG 文件 (*.jpg)") {
                savePath.append(".jpg");
            }
        }

        if (outputImage_.save(savePath)) {
            QMessageBox::information(this, "成功", "图片已成功保存！");
            statusBar()->showMessage("图片已保存到: " + savePath);
        } else {
            QMessageBox::critical(this, "失败", QString("图片保存失败！\n路径: %1").arg(savePath));
        }
    }
}

void MainWindow::handleInitResult(bool success, const QString &message)
{
    statusBar()->showMessage(message);
    if (!success) {
        QMessageBox::critical(this, "初始化失败", message);
        ui->selectButton->setEnabled(false);
        ui->runButton->setEnabled(false);
    }
}

void MainWindow::handleInferenceResult(const QImage &resultImage, const QString &message)
{
    outputImage_ = resultImage;
    ui->outputImageLabel->setPixmap(QPixmap::fromImage(outputImage_).scaled(
        ui->outputImageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation
    ));
    statusBar()->showMessage(message);

    ui->selectButton->setEnabled(true);
    ui->runButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
}

void MainWindow::handleError(const QString &errorMessage)
{
    QMessageBox::critical(this, "发生错误", errorMessage);
    statusBar()->showMessage("操作失败！");

    ui->selectButton->setEnabled(true);
    ui->runButton->setEnabled(true);
}
