#include "dialog2.h"
#include "ui_dialog2.h"
using namespace std;

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    history_model = new QStandardItemModel(this);


    history_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("题数")));
    history_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("正确题数")));
    history_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("正确比例")));
    //history_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("正确答案")));
    ui->tableView->setModel(history_model);


    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setColumnWidth(2,100);
    //ui->tableView->setColumnWidth(3,100);
    //ui->tableView->setColumnWidth(4,100);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ifstream history_text;
    string total;
    string correct;
    string correct_rate;
    //string answer;
    int line=0;

    history_text.open("./history.txt",ios::in);

    while(getline(history_text, total)){

          history_model->setItem(line, 0, new QStandardItem(QString::fromStdString(total)));
          getline(history_text, correct);
          history_model->setItem(line, 1, new QStandardItem(QString::fromStdString(correct)));
          getline(history_text, correct_rate);
          history_model->setItem(line, 2, new QStandardItem(QString::fromStdString(correct_rate)));

        line++;
    }
    history_text.close();
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    ofstream file;
    file.open("./history.txt", ios::out | ios::trunc);
    file.close();

    history_model->removeRows(0,history_model->rowCount());


}
