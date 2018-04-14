#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define CORE_MRC
#define CORE_LJW

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
#include <vector>

//API
#ifdef CORE_MRC
#include "core.h"
#endif

#ifdef CORE_LJW
#include "Core15.h"
#endif
//END OF API

class fomularCore;

using namespace std;

class Dialog3;

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

    void get_arith(const string &arith);
    void get_ans(const string &ans);


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
    int task_num, oper_num, max_num;  //题目数 操作数 最大值
    int count, index;  //实现过程中的界面累加器，索引
    int task_num_0;     //题目总数
    int wrong_idd;  //错题标号
    string question;  //题目
    double result;  //用户答案（废弃不用）
    string result_str;  //用户答案
    double answer; //标准答案（废弃不用）
    string answer_str; //标准答案
    int correct_num; //题目正确数
    double correct_rate; //正确率
    int calc_type_int;  //运算种类 加减 加减乘除 加减乘除乘方
    int opr_num;  //运算符数量
    int min_num; //最小值
    //int max_num;
    int accuracy;  //精度 小数点后保留几位
    int type_int; //答案种类 整数 小数 分数
    bool flag_choose_advance;  //是否选着高级选项
    Dialog3 *dlg3;

    //API
#ifdef CORE_MRC
    fomularCore *core;
    vector<string> out_api,res_api;
    string ops_api;
    int count_api;
    bool fraction;
#endif

#ifdef CORE_LJW
    string* out_api;
    string* res_api;
    int has_real;
    int has_fraction;
    int has_mul_div;
    int has_power;
#endif
    //string question;

    QButtonGroup *calc_type;
};

#endif // MAINWINDOW_H
