//
// Created by 曾立 on 2023/8/2.
//

#ifndef PDFTOWORD_MAINWINDOW_H
#define PDFTOWORD_MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <QFileDialog>
#include <QIcon>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    std::string Qstring2string(const QString& qstring);
    void paintEvent(QPaintEvent *);
    ~MainWindow() override;

signals:
    void SendPath(std::string& pdf, std::string& scrip);
public slots:

    void StartConvert();
    void RecvDocx(std::string docx);
private:
    Ui::MainWindow *ui;
    //ConvertThread child_thread;
    QString file_path;
    std::string scrip_path;
    std::string docx_path;
};


#endif //PDFTOWORD_MAINWINDOW_H
