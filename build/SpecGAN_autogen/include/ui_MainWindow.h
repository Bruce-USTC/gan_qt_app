/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
        MainWindow->resize(850, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topFrame = new QFrame(centralwidget);
        topFrame->setObjectName(QString::fromUtf8("topFrame"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(topFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        selectButton = new QPushButton(topFrame);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setMinimumSize(QSize(120, 40));
        QFont font;
        font.setPointSize(12);
        selectButton->setFont(font);

        horizontalLayout->addWidget(selectButton);

        runButton = new QPushButton(topFrame);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setMinimumSize(QSize(120, 40));
        runButton->setFont(font);

        horizontalLayout->addWidget(runButton);

        saveButton = new QPushButton(topFrame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(120, 40));
        saveButton->setFont(font);

        horizontalLayout->addWidget(saveButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(topFrame);

        imageFrame = new QFrame(centralwidget);
        imageFrame->setObjectName(QString::fromUtf8("imageFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageFrame->sizePolicy().hasHeightForWidth());
        imageFrame->setSizePolicy(sizePolicy);
        imageFrame->setFrameShape(QFrame::StyledPanel);
        imageFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(imageFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputImageLabel = new QLabel(imageFrame);
        inputImageLabel->setObjectName(QString::fromUtf8("inputImageLabel"));
        inputImageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        inputImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(inputImageLabel);

        outputImageLabel = new QLabel(imageFrame);
        outputImageLabel->setObjectName(QString::fromUtf8("outputImageLabel"));
        outputImageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        outputImageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(outputImageLabel);


        verticalLayout->addWidget(imageFrame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RKNN GAN \345\244\204\347\220\206\345\267\245\345\205\267 (C++/Qt)", nullptr));
        selectButton->setText(QApplication::translate("MainWindow", "1. \351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        runButton->setText(QApplication::translate("MainWindow", "2. \345\274\200\345\247\213\350\275\254\346\215\242", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "3. \344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        inputImageLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\233\276\347\211\207\351\242\204\350\247\210", nullptr));
        outputImageLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\347\211\207\351\242\204\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
