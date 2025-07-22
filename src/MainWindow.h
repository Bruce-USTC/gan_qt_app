#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QCloseEvent>
#include "RknnProcessor.h"

// 前向声明 Ui::MainWindow
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // 重写窗口关闭事件
    void closeEvent(QCloseEvent *event) override;

private slots:
    // --- UI控件的槽函数 (由 uic 自动连接) ---
    void on_selectButton_clicked();
    void on_runButton_clicked();
    void on_saveButton_clicked();

    // --- 处理 RknnProcessor 信号的槽函数 ---
    void handleInitResult(bool success, const QString &message);
    void handleInferenceResult(const QImage &resultImage, const QString &message);
    void handleError(const QString &errorMessage);

signals:
    // --- 用于触发工作线程任务的信号 ---
    void startInitialization(const QString &modelPath);
    void startInference(const QString &imagePath);

private:
    // 指向由 uic 生成的 UI 类
    Ui::MainWindow *ui;

    // 工作线程和处理器
    QThread workerThread_;
    RknnProcessor *processor_;

    // 存储路径和结果
    QString inputImagePath_;
    QImage outputImage_;
};
#endif // MAINWINDOW_H
