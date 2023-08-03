#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window = MainWindow();
    main_window.show();
    return QApplication::exec();
}
