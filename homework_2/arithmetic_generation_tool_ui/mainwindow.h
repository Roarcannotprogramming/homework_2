#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "dialog1.h"
#include "dialog2.h"
#include <QLineEdit>
#include <QtGui/QtGui>
#include <QString>
#include <QTimer>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <string>
#include <QButtonGroup>
#include "dialog3.h"

using namespace std;

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
    //bool one;
    ofstream wrong_answers;
    ofstream history;
    ofstream share;


private slots:
    void on_pushButton_clicked();

    void on_actionewwewe_triggered();

    void on_actioncuotiben_triggered();

    void on_actionlishijiu_triggered();

    void on_actionshuchuchengji_triggered();

    void timeout();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    //QStackedWidget *main_stack_widget;
    int task_num, oper_num, max_num;
    int count, index;
    int task_num_0;
    int wrong_idd;
    string question;
    double result;
    double answer;
    int correct_num;
    double correct_rate;
    int calc_type_int;

    QButtonGroup *calc_type;
};

#endif // MAINWINDOW_H
