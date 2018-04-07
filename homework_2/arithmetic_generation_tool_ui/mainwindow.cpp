#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time1 = 20;
    //one = true;
    task_num = 0;
    oper_num = 0;
    max_num = 0;
    index = 0;
    count = 0;
    task_num_0 = 0;
    result = -1;
    question = "";
    answer = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete main_stack_widget;
}

void MainWindow::on_pushButton_clicked()
{
    task_num = ui->lineEdit->text().toInt();
    task_num_0=task_num;
    oper_num = ui->lineEdit_2->text().toInt();
    max_num = ui->lineEdit_3->text().toInt();
    //task_num--;
    count = ui->stackedWidget1->count();
    index = ui->stackedWidget1->currentIndex();
    index++;
    if(index == count){
        index =0;
    }
    //QString qstr="asdasd";
    ui->stackedWidget1->setCurrentIndex(index);

    ui->label_2->setText(QString::number(task_num_0-task_num+1));
    ui->textBrowser->setPlainText("456");//输入题目

    timer= new QTimer;
    if(one = true){
        connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
        timer->start(1000);
    }
}

//static int time1 = 20 ;

void MainWindow::timeout(){

    if(time1!=0){
        time1--;
        ui->lcdNumber->display(QString::number(time1,10));
    }else{
        task_num--;

        result = -1;

        wrong_answers.open("./wrong_answer.txt",ios::app);    //添加到错题本
        wrong_answers << question << " " << result << " " << answer << endl ;
        wrong_answers.close();

        result =-1;              //维护
        question = "";
        answer = -1;

        QMessageBox *box = new QMessageBox(this);

            if(QMessageBox::Yes == box->warning(this,tr("温馨提示"),tr("时间到！"),QMessageBox::Yes,QMessageBox::Yes));
            /*{
                ui->label_2->setText(QString::number(task_num_0-task_num+1));
                ui->textBrowser->setPlainText("123"); //输入题目
                ui->textEdit->clear();
            }*/
            if(task_num != 0)
                //question = 输入题目-------------------
                //answer = 输入答案---------------------
                ui->label_2->setText(QString::number(task_num_0-task_num+1));
                ui->textBrowser->setPlainText("question_time_out");
                ui->textEdit->clear();
                time1 = 20;
            else{
                timer->stop();
                index++;
                if(index == count){
                    index =0;
                }
                ui->stackedWidget1->setCurrentIndex(index);
                ui->textBrowser_3->setPlainText(QString::number(task_num_0));
            }
    }

}

void MainWindow::on_actionewwewe_triggered()
{
    if(timer->isActive())
        timer->stop();
    index = 1;
    ui->stackedWidget1->setCurrentIndex(index);
}

void MainWindow::on_actioncuotiben_triggered()
{
    //ofstream wrong_answers;
    /*wrong_answers.open("./wrong_answer.txt",ios::app);
    wrong_answers << question << " " << result <<" "<< answer << endl ;
    wrong_answers.close();*/
    ifstream wrong_things;

}

void MainWindow::on_actionlishijiu_triggered()
{

}

void MainWindow::on_actionshuchuchengji_triggered()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    task_num--;
    result = ui->textEdit->toPlainText();//获取结果

    if(result != answer){           //加入错题本
        wrong_answers.open("./wrong_answer.txt",ios::app);
        wrong_answers << question << " " << result <<" "<< answer << endl ;
        wrong_answers.close();

        result =-1;
        question = "";
        answer = -1;
    }

    //进入下一题

    if(task_num != 0)
        time1=20;
        //question = 输入题目-----------------
        //answer = 输入答案-------------------
        ui->label_2->setText(QString::number(task_num_0-task_num+1));
        ui->textBrowser->setPlainText("question");
        ui->textEdit->clear();
    else{
        timer->stop();
        index++;
        if(index == count){
            index =0;
        }
        ui->stackedWidget1->setCurrentIndex(index);
        ui->textBrowser_3->setPlainText(QString::number(task_num_0));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    index++;
    if(index == count){
        index =0;
    }
    ui->stackedWidget1->setCurrentIndex(index);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    qApp->quit();
}
