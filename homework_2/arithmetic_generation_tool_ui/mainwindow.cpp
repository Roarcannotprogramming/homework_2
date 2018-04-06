#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time1 = 2;
    //one = true;
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete main_stack_widget;
}

void MainWindow::on_pushButton_clicked()
{
    int count = ui->stackedWidget1->count();
    int index = ui->stackedWidget1->currentIndex();
    index++;
    if(index == count){
        index =0;
    }
    //QString qstr="asdasd";
    ui->stackedWidget1->setCurrentIndex(index);

    ui->textBrowser->setPlainText("456");

    timer= new QTimer;
    if(one = true){
        connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
        timer->start(1000);
    }
}

//static int time1 = 20 ;

void MainWindow::timeout(){
    int ii =1;
    if(time1!=0){
        time1--;
        ui->lcdNumber->display(QString::number(time1,10));
    }else{
        QMessageBox *box = new QMessageBox(this);

            if(QMessageBox::Yes == box->warning(this,tr("温馨提示"),tr("时间到！"),QMessageBox::Yes,QMessageBox::Yes)){
                ui->textBrowser->setPlainText("123");
                ui->textEdit->clear();
            }
            time1 =20;
    }

}

void MainWindow::on_actionewwewe_triggered()
{

}

void MainWindow::on_actioncuotiben_triggered()
{

}

void MainWindow::on_actionlishijiu_triggered()
{

}

void MainWindow::on_actionshuchuchengji_triggered()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->toPlainText();
    ui->textBrowser->setPlainText("789");
    ui->textEdit->clear();
    time1=20;
    //ui->textEdit->clear();
}
