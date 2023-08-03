//
// Created by 曾立 on 2023/8/2.
//
// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "convertthred.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PdfToWord");
    this->setFixedSize(630, 520);
    this->setWindowIcon(QIcon("../src/matplotlib.png"));
    this->scrip_path = "../pdfToWord.py";

    ui->btn_docx->setEnabled(false);
    //创建子进程
    ConvertThread *pdf2d_thread = new ConvertThread(this);
    //绑定 Open按钮
    connect(ui->btn_open, &QPushButton::clicked, [=](){
        this->file_path = QFileDialog::getOpenFileName(this, "select", "C:/", "(*.pdf)");
        ui->edit_path->setText(this->file_path);
    });
    //connect(ui->btn_start, &QPushButton::clicked, this, &MainWindow::StartConvert);
    //绑定打开docx按钮
    connect(ui->btn_docx, &QPushButton::clicked, [=](){
       std::system(this->docx_path.c_str());
    });
    //绑定主线程向子线程传递文件路径的信号和槽
    connect(this, &MainWindow::SendPath, pdf2d_thread, &ConvertThread::RecvDate);
    //绑定子线程向主线程返回的信息
    connect(pdf2d_thread, &ConvertThread::SendDoxc, this, &MainWindow::RecvDocx);
    //绑定Start按钮，开始执行子线程
    connect(ui->btn_start, &QPushButton::clicked, [=](){
        std::string pdf = Qstring2string(this->file_path);
        emit SendPath(pdf, this->scrip_path);
        pdf2d_thread->start();
    });
}

void MainWindow::StartConvert()
{
    ui->btn_docx->setEnabled(false);
    std::string cmd = "python " + this->scrip_path + " " + "\"" + Qstring2string(this->file_path) + "\"";
    //std::cout << cmd << std::endl;
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cout << "Failed to execute command." << std::endl;
        return;
    }

    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    // 关闭管道
    _pclose(pipe);
    if ("0" != result)
    {
        ui->text_info->setText(this->file_path + " 转换成功！");
        this->docx_path = result;
        ui->btn_docx->setEnabled(true);
    }
    else
    {
        ui->text_info->setText(this->file_path + " 转换失败！");
    }
}
void MainWindow::RecvDocx(std::string docx)
{
    this->docx_path = docx;
    if ("0" != docx)
    {
        QString lien_start = "word path: ";
        ui->text_info->setText(this->file_path + " 转换成功");
        ui->text_info->append(lien_start + QString::fromLocal8Bit(docx.c_str()));
        this->docx_path = docx;
        ui->btn_docx->setEnabled(true);
    }
    else
    {
        ui->text_info->setText(this->file_path + " 转换失败！");
    }
}
std::string MainWindow::Qstring2string(const QString& qstring)
{
    QByteArray cstr = qstring.toLocal8Bit();
    return std::string(cstr);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("../src/ss1.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

MainWindow::~MainWindow() {
    delete ui;
}
