#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFile file("E:/Project_Files/homework_2/arithmetic_generation_tool_ui/qss/stylesheet.qss");
    //file.open(QFile::ReadOnly);
    //a.setStyleSheet(file.readAll());
    //file.close();
    MainWindow w;
    w.show();
    return a.exec();
}
