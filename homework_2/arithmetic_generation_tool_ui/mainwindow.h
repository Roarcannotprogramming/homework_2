#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "dialog1.h"
#include <QLineEdit>
#include <QtGui/QtGui>
#include <QString>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*void change_page();*/
    QTimer *timer;

    int time1;
    bool one;


private slots:
    void on_pushButton_clicked();

    void on_actionewwewe_triggered();

    void on_actioncuotiben_triggered();

    void on_actionlishijiu_triggered();

    void on_actionshuchuchengji_triggered();

    void timeout();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    //QStackedWidget *main_stack_widget;
};

#endif // MAINWINDOW_H
