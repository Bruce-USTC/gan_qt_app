/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *topFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_1;
    QPushButton *selectButton;
    QPushButton *runButton;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *imageFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inputImageLabel;
    QLabel *outputImageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 680);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"/* ---- \345\205\250\345\261\200\346\240\267\345\274\217 ---- */\n"
"#MainWindow {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(27, 38, 59, 255), stop:1 rgba(13, 19, 31, 255));\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: rgba(27, 38, 59, 0.8);\n"
"    color: #9FB6D9;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolTip {\n"
"    background-color: #1B263B;\n"
"    color: #EAEAEA;\n"
"    border: 1px solid #40E0D0;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        topFrame = new QFrame(centralwidget);
        topFrame->setObjectName(QString::fromUtf8("topFrame"));
        topFrame->setFrameShape(QFrame::NoFrame);
        topFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(topFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        selectButton = new QPushButton(topFrame);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setMinimumSize(QSize(160, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        selectButton->setFont(font);
        selectButton->setCursor(QCursor(Qt::PointingHandCursor));
        selectButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #EAEAEA;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 129, 255, 150), stop:1 rgba(0, 255, 255, 180));\n"
"    border: 1px solid #00FFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 129, 255, 200), stop:1 rgba(0, 255, 255, 220));\n"
"    border: 1px solid #99FFFF;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 100, 200, 255), stop:1 rgba(0, 200, 200, 255));\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #555;\n"
"    color: #888;\n"
"    border: 1px solid #666;\n"
"}"));

        horizontalLayout->addWidget(selectButton);

        runButton = new QPushButton(topFrame);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setMinimumSize(QSize(160, 50));
        runButton->setFont(font);
        runButton->setCursor(QCursor(Qt::PointingHandCursor));
        runButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 127, 180), stop:1 rgba(0, 200, 200, 200));\n"
"    border: 1px solid #00FF7F;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 127, 220), stop:1 rgba(0, 200, 200, 240));\n"
"    border: 1px solid #80FFBF;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 200, 100, 255), stop:1 rgba(0, 150, 150, 255));\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #555;\n"
"    color: #888;\n"
"    border: 1px solid #666;\n"
"}"));

        horizontalLayout->addWidget(runButton);

        saveButton = new QPushButton(topFrame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(160, 50));
        saveButton->setFont(font);
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 165, 0, 180), stop:1 rgba(255, 69, 0, 200));\n"
"    border: 1px solid #FFA500;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 165, 0, 220), stop:1 rgba(255, 69, 0, 240));\n"
"    border: 1px solid #FFC04D;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 132, 0, 255), stop:1 rgba(204, 55, 0, 255));\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #555;\n"
"    color: #888;\n"
"    border: 1px solid #666;\n"
"}"));

        horizontalLayout->addWidget(saveButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(topFrame);

        imageFrame = new QFrame(centralwidget);
        imageFrame->setObjectName(QString::fromUtf8("imageFrame"));
        imageFrame->setFrameShape(QFrame::NoFrame);
        imageFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(imageFrame);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputImageLabel = new QLabel(imageFrame);
        inputImageLabel->setObjectName(QString::fromUtf8("inputImageLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        inputImageLabel->setFont(font1);
        inputImageLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(0, 0, 0, 0.4);\n"
"    border: 2px dashed #4A5A73;\n"
"    border-radius: 12px;\n"
"    color: rgba(127, 140, 141, 0.7);\n"
"}\n"
"QLabel:hover {\n"
"    border: 2px dashed #40E0D0;\n"
"}"));
        inputImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(inputImageLabel);

        outputImageLabel = new QLabel(imageFrame);
        outputImageLabel->setObjectName(QString::fromUtf8("outputImageLabel"));
        outputImageLabel->setFont(font1);
        outputImageLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(0, 0, 0, 0.4);\n"
"    border: 2px dashed #4A5A73;\n"
"    border-radius: 12px;\n"
"    color: rgba(127, 140, 141, 0.7);\n"
"}"));
        outputImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(outputImageLabel);


        verticalLayout->addWidget(imageFrame);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"    background-color: #1B263B;\n"
"    color: #EAEAEA;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #3498db;\n"
"}"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SpecGAN: \345\205\211\350\260\261\345\233\276\345\203\217\350\275\254\346\215\242\345\267\245\345\205\267", nullptr));
#if QT_CONFIG(tooltip)
        selectButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\273\216\346\234\254\345\234\260\347\243\201\347\233\230\351\200\211\346\213\251\344\270\200\345\274\240\345\233\276\347\211\207\344\275\234\344\270\272\350\276\223\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
        selectButton->setText(QCoreApplication::translate("MainWindow", "\342\221\240 \351\200\211\346\213\251\345\233\276\345\203\217", nullptr));
#if QT_CONFIG(tooltip)
        runButton->setToolTip(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250NPU\357\274\214\345\274\200\345\247\213\346\211\247\350\241\214\345\233\276\345\203\217\350\275\254\346\215\242", nullptr));
#endif // QT_CONFIG(tooltip)
        runButton->setText(QCoreApplication::translate("MainWindow", "\342\221\241 \345\274\200\345\247\213\350\275\254\346\215\242", nullptr));
#if QT_CONFIG(tooltip)
        saveButton->setToolTip(QCoreApplication::translate("MainWindow", "\345\260\206\345\217\263\344\276\247\347\224\237\346\210\220\347\232\204\345\233\276\347\211\207\344\277\235\345\255\230\345\210\260\346\234\254\345\234\260", nullptr));
#endif // QT_CONFIG(tooltip)
        saveButton->setText(QCoreApplication::translate("MainWindow", "\342\221\242 \344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        inputImageLabel->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        outputImageLabel->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
