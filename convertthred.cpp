//
// Created by 曾立 on 2023/8/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ConvertThred.h" resolved

#include "convertthred.h"

ConvertThread::ConvertThread(QObject *parent) : QThread(parent)
{

}

void ConvertThread::RecvDate(std::string& pdf, std::string& scrip)
{
    this->pdf_path = pdf;
    this->scrip_path = scrip;

}

void ConvertThread::run()
{
    std::string cmd = "python " + this->scrip_path + " \"" + this->pdf_path + "\"";
    FILE *pipe = _popen(cmd.c_str(), "r");
    if (!pipe)
    {
        return;
    }

    char buffer[128] = {0};
    std::string result = "";
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        result += buffer;
    }

    _pclose(pipe);

    emit SendDoxc(result);

}

ConvertThread::~ConvertThread() {

}

OpenThread::OpenThread(QObject *parent) : QThread (parent)
{

}
void OpenThread::run()
{
    std::system(this->docx_path.c_str());
}

void OpenThread::RecvDocx(std::string& docx)
{
    this->docx_path = docx;
}

OpenThread::~OpenThread() noexcept
{

}