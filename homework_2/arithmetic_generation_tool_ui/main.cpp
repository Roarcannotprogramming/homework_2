#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./png");
    a.setFont(QFont("Microsoft Yahei", 9));
    a.setWindowIcon(QIcon(":/main.ico"));
    /*QFile file("E:/Project_Files/homework_2/arithmetic_generation_tool_ui/qss/stylesheet_black.qss");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    a.setPalette(QPalette(QColor("#F0F0F0")));
    file.close();*/

    //QFile file("E:/Project_Files/homework_2/arithmetic_generation_tool_ui/other/qss/psblack.css");
    QFile file("./other/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
