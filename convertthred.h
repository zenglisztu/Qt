//
// Created by 曾立 on 2023/8/2.
//

#ifndef PDFTOWORD_CONVERTTHRED_H
#define PDFTOWORD_CONVERTTHRED_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <cstdlib>
#include <cstring>

class ConvertThread : public QThread {
Q_OBJECT

public:
    explicit ConvertThread(QObject *parent = nullptr);

    ~ConvertThread() override;

public slots:
    void RecvDate(std::string& pdf, std::string& scrip);
signals:
    void SendDoxc(std::string docx_p);
private:
    std::string pdf_path;
    std::string scrip_path;
    std::string docx_path;
protected:
    void run() override;
};

class OpenThread : public QThread {
Q_OBJECT

public:
    explicit OpenThread(QObject *parent = nullptr);

    ~OpenThread() override;

public slots:
    void RecvDocx(std::string& docx);
signals:
    //void SendDoxc(std::string docx_p);
private:
    std::string docx_path;
protected:
    void run() override;
};

#endif //PDFTOWORD_CONVERTTHRED_H
