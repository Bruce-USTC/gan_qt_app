#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 创建 QApplication 实例
    QApplication a(argc, argv);

    // 创建并显示主窗口
    MainWindow w;
    w.show();

    // 进入 Qt 的事件循环
    return a.exec();
}
