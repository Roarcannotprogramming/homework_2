#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time1 = 20;
    timer=nullptr;
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
    wrong_idd =-1;
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete main_stack_widget;
}

void MainWindow::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty()){
        task_num = ui->lineEdit->text().toInt();
        task_num_0=task_num;
        oper_num = ui->lineEdit_2->text().toInt();
        max_num = ui->lineEdit_3->text().toInt();
    }
    else{
        QMessageBox *box_ = new QMessageBox(this);
        box_->warning(this, tr("温馨提示"), tr("请填写题目数，最多运算次数，数值最大范围！"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    //task_num_0=task_num;
    //oper_num = ui->lineEdit_2->text().toInt();
    //max_num = ui->lineEdit_3->text().toInt();
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

    question = "the_first_q";
    answer = 2;
    ui->textBrowser->setPlainText(QString::fromStdString(question));//输入题目

    timer= new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer->start(1000);
}

//static int time1 = 20 ;

void MainWindow::timeout(){

    if(time1!=0){
        time1--;
        ui->lcdNumber->display(QString::number(time1,10));
    }else{


        result = -1;
        wrong_idd = task_num_0-task_num+1;

        //task_num--;

        wrong_answers.open("./wrong_answer.txt",ios::app);    //添加到错题本
        wrong_answers << wrong_idd <<"\n"<< question << "\n" << result << "\n" << answer << endl ;
        wrong_answers.close();

        result =-1;              //维护
        question = "";
        answer = -1;
        wrong_idd = -1;

        QMessageBox *box = new QMessageBox(this);

            //if(QMessageBox::Yes == box->warning(this,tr("温馨提示"),tr("时间到！"),QMessageBox::Yes,QMessageBox::Yes));
            box->warning(this,tr("温馨提示"),tr("时间到！"),QMessageBox::Yes,QMessageBox::Yes);
            /*{
                ui->label_2->setText(QString::number(task_num_0-task_num+1));
                ui->textBrowser->setPlainText("123"); //输入题目
                ui->textEdit->clear();
            }*/


            task_num--;
            //进入下一题!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(task_num != 0){
                question = "time_out_ok?";
                //answer = 输入答案---------------------
                answer = 2;
                ui->label_2->setText(QString::number(task_num_0-task_num+1));
                ui->textBrowser->setPlainText(QString::fromStdString(question));
                ui->textEdit->clear();
                time1 = 20;
            }
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
    if(timer && timer->isActive())
        timer->stop();
    //count = ui->stackedWidget1->count();
    //index = ui->stackedWidget1->currentIndex();
    //if(index!=1){
    index = 1;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->stackedWidget1->setCurrentIndex(index);
    //}
}

void MainWindow::on_actioncuotiben_triggered()
{
    //ofstream wrong_answers;
    /*wrong_answers.open("./wrong_answer.txt",ios::app);
    wrong_answers << question << " " << result <<" "<< answer << endl ;
    wrong_answers.close();*/
    Dialog1 *dlg = new Dialog1(this);
    dlg->exec();
}

void MainWindow::on_actionlishijiu_triggered()
{

}

void MainWindow::on_actionshuchuchengji_triggered()
{

}

void MainWindow::on_pushButton_2_clicked()
{

    result = ui->textEdit->toPlainText().toDouble();//获取结果

    if(result - answer >0.0001 || result - answer < -0.0001){           //加入错题本
        wrong_answers.open("./wrong_answer.txt",ios::app);
        wrong_idd = task_num_0-task_num+1;
        wrong_answers << wrong_idd <<"\n"<< question << "\n" << result <<"\n"<< answer << endl ;
        wrong_answers.close();
    }
    result =-1;
    question = "";
    answer = -1;
    wrong_idd=-1;


    task_num--;
    //进入下一题

    if(task_num != 0){
        time1=20;
        question = "aaaaaaaaaaaaaaaaaa";
        //answer = "输入答案-------------------"
        answer = 2;
        ui->label_2->setText(QString::number(task_num_0-task_num+1));
        ui->textBrowser->setPlainText(QString::fromStdString(question));
        ui->textEdit->clear();
    }
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

void MainWindow::on_pushButton_3_clicked()
{
    Dialog1 *dlg = new Dialog1(this);
    dlg->exec();
}
