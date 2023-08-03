/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edit_path;
    QPushButton *btn_open;
    QTextEdit *text_info;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_start;
    QPushButton *btn_docx;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(522, 411);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        edit_path = new QLineEdit(widget);
        edit_path->setObjectName("edit_path");
        edit_path->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        horizontalLayout->addWidget(edit_path);

        btn_open = new QPushButton(widget);
        btn_open->setObjectName("btn_open");
        btn_open->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        horizontalLayout->addWidget(btn_open);


        verticalLayout->addWidget(widget);

        text_info = new QTextEdit(centralwidget);
        text_info->setObjectName("text_info");
        text_info->setContextMenuPolicy(Qt::NoContextMenu);
        text_info->setLayoutDirection(Qt::LeftToRight);
        text_info->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 2);"));
        text_info->setFrameShape(QFrame::Panel);
        text_info->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(text_info);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_start = new QPushButton(widget_2);
        btn_start->setObjectName("btn_start");
        btn_start->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        horizontalLayout_2->addWidget(btn_start);

        btn_docx = new QPushButton(widget_2);
        btn_docx->setObjectName("btn_docx");
        btn_docx->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));

        horizontalLayout_2->addWidget(btn_docx);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 522, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        edit_path->setText(QString());
        btn_open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btn_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btn_docx->setText(QCoreApplication::translate("MainWindow", "open-docx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
