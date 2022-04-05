/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_plus;
    QPushButton *btn_sub;
    QPushButton *btn_mul;
    QPushButton *btn_div;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_jin;
    QPushButton *btn_and;
    QPushButton *btn_or;
    QPushButton *btn_mis;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_sum;
    QPushButton *btn_clear;
    QPushButton *btn_left;
    QPushButton *btn_right;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(515, 574);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 12, 481, 491));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setContextMenuPolicy(Qt::CustomContextMenu);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 127);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_1 = new QPushButton(widget);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        sizePolicy.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy);
        btn_1->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout->addWidget(btn_1);

        btn_2 = new QPushButton(widget);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        sizePolicy.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy);
        btn_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout->addWidget(btn_2);

        btn_3 = new QPushButton(widget);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy);
        btn_3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout->addWidget(btn_3);

        btn_4 = new QPushButton(widget);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        sizePolicy.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy);
        btn_4->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout->addWidget(btn_4);

        btn_5 = new QPushButton(widget);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        sizePolicy.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy);
        btn_5->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout->addWidget(btn_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_6 = new QPushButton(widget);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        sizePolicy.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy);
        btn_6->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_2->addWidget(btn_6);

        btn_7 = new QPushButton(widget);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        sizePolicy.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy);
        btn_7->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_2->addWidget(btn_7);

        btn_8 = new QPushButton(widget);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        sizePolicy.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy);
        btn_8->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_2->addWidget(btn_8);

        btn_9 = new QPushButton(widget);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        sizePolicy.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy);
        btn_9->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_2->addWidget(btn_9);

        btn_0 = new QPushButton(widget);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        sizePolicy.setHeightForWidth(btn_0->sizePolicy().hasHeightForWidth());
        btn_0->setSizePolicy(sizePolicy);
        btn_0->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_2->addWidget(btn_0);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_plus = new QPushButton(widget);
        btn_plus->setObjectName(QString::fromUtf8("btn_plus"));
        sizePolicy.setHeightForWidth(btn_plus->sizePolicy().hasHeightForWidth());
        btn_plus->setSizePolicy(sizePolicy);
        btn_plus->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_3->addWidget(btn_plus);

        btn_sub = new QPushButton(widget);
        btn_sub->setObjectName(QString::fromUtf8("btn_sub"));
        sizePolicy.setHeightForWidth(btn_sub->sizePolicy().hasHeightForWidth());
        btn_sub->setSizePolicy(sizePolicy);
        btn_sub->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_3->addWidget(btn_sub);

        btn_mul = new QPushButton(widget);
        btn_mul->setObjectName(QString::fromUtf8("btn_mul"));
        sizePolicy.setHeightForWidth(btn_mul->sizePolicy().hasHeightForWidth());
        btn_mul->setSizePolicy(sizePolicy);
        btn_mul->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_3->addWidget(btn_mul);

        btn_div = new QPushButton(widget);
        btn_div->setObjectName(QString::fromUtf8("btn_div"));
        sizePolicy.setHeightForWidth(btn_div->sizePolicy().hasHeightForWidth());
        btn_div->setSizePolicy(sizePolicy);
        btn_div->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_3->addWidget(btn_div);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_jin = new QPushButton(widget);
        btn_jin->setObjectName(QString::fromUtf8("btn_jin"));
        sizePolicy.setHeightForWidth(btn_jin->sizePolicy().hasHeightForWidth());
        btn_jin->setSizePolicy(sizePolicy);
        btn_jin->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_4->addWidget(btn_jin);

        btn_and = new QPushButton(widget);
        btn_and->setObjectName(QString::fromUtf8("btn_and"));
        sizePolicy.setHeightForWidth(btn_and->sizePolicy().hasHeightForWidth());
        btn_and->setSizePolicy(sizePolicy);
        btn_and->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_4->addWidget(btn_and);

        btn_or = new QPushButton(widget);
        btn_or->setObjectName(QString::fromUtf8("btn_or"));
        sizePolicy.setHeightForWidth(btn_or->sizePolicy().hasHeightForWidth());
        btn_or->setSizePolicy(sizePolicy);
        btn_or->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_4->addWidget(btn_or);

        btn_mis = new QPushButton(widget);
        btn_mis->setObjectName(QString::fromUtf8("btn_mis"));
        sizePolicy.setHeightForWidth(btn_mis->sizePolicy().hasHeightForWidth());
        btn_mis->setSizePolicy(sizePolicy);
        btn_mis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_4->addWidget(btn_mis);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btn_sum = new QPushButton(widget);
        btn_sum->setObjectName(QString::fromUtf8("btn_sum"));
        sizePolicy.setHeightForWidth(btn_sum->sizePolicy().hasHeightForWidth());
        btn_sum->setSizePolicy(sizePolicy);
        btn_sum->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_5->addWidget(btn_sum);

        btn_clear = new QPushButton(widget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_clear->sizePolicy().hasHeightForWidth());
        btn_clear->setSizePolicy(sizePolicy);
        btn_clear->setMaximumSize(QSize(93, 90));
        btn_clear->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));
        btn_clear->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(btn_clear);

        btn_left = new QPushButton(widget);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        sizePolicy.setHeightForWidth(btn_left->sizePolicy().hasHeightForWidth());
        btn_left->setSizePolicy(sizePolicy);
        btn_left->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_5->addWidget(btn_left);

        btn_right = new QPushButton(widget);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        sizePolicy.setHeightForWidth(btn_right->sizePolicy().hasHeightForWidth());
        btn_right->setSizePolicy(sizePolicy);
        btn_right->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 85, 255);"));

        horizontalLayout_5->addWidget(btn_right);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 515, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">0</span></p></body></html>", nullptr));
        btn_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        btn_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        btn_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        btn_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        btn_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        btn_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        btn_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        btn_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        btn_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        btn_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        btn_plus->setText(QApplication::translate("MainWindow", "+", nullptr));
        btn_sub->setText(QApplication::translate("MainWindow", "-", nullptr));
        btn_mul->setText(QApplication::translate("MainWindow", "*", nullptr));
        btn_div->setText(QApplication::translate("MainWindow", "/", nullptr));
        btn_jin->setText(QApplication::translate("MainWindow", "#", nullptr));
        btn_and->setText(QApplication::translate("MainWindow", "&&", nullptr));
        btn_or->setText(QApplication::translate("MainWindow", "||", nullptr));
        btn_mis->setText(QApplication::translate("MainWindow", "!", nullptr));
        btn_sum->setText(QApplication::translate("MainWindow", "=", nullptr));
        btn_clear->setText(QApplication::translate("MainWindow", "clear", nullptr));
        btn_left->setText(QApplication::translate("MainWindow", "(", nullptr));
        btn_right->setText(QApplication::translate("MainWindow", ")", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
