#include "dialog1.h"
#include "ui_dialog1.h"
using namespace std;


Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    QStandardItemModel *wrong_answer_model = new QStandardItemModel(this);
    wrong_answer_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("错题序号")));
    wrong_answer_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("题目")));
    wrong_answer_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("你的答案")));
    wrong_answer_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("正确答案")));
    ui->tableView->setModel(wrong_answer_model);

    /*ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);*/

    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,300);
    ui->tableView->setColumnWidth(2,100);
    ui->tableView->setColumnWidth(3,100);
    //ui->tableView->setColumnWidth(4,100);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ifstream wrong_things;
    string wrong_id;
    string question;
    string result;
    string answer;
    int line=0;

    wrong_things.open("./wrong_answer.txt",ios::in);

    while(getline(wrong_things, wrong_id)){
          //getline(wrong_things, wrong_id);
          wrong_answer_model->setItem(line, 0, new QStandardItem(QString::fromStdString(wrong_id)));
          getline(wrong_things, question);
          wrong_answer_model->setItem(line, 1, new QStandardItem(QString::fromStdString(question)));
          getline(wrong_things, result);
          wrong_answer_model->setItem(line, 2, new QStandardItem(QString::fromStdString(result)));
          getline(wrong_things, answer);
          wrong_answer_model->setItem(line, 3, new QStandardItem(QString::fromStdString(answer)));

        //wrong_answer_model->setItem(line, 0, new QStandardItem(QString::fromStdString(wrong_id)));
        //wrong_answer_model->setItem(line, 1, new QStandardItem(QString::fromStdString(question)));
        //wrong_answer_model->setItem(line, 2, new QStandardItem(QString::fromStdString(result)));
        //wrong_answer_model->setItem(line, 3, new QStandardItem(QString::fromStdString(answer)));

        line++;
    }
    wrong_things.close();
}

Dialog1::~Dialog1()
{
    delete ui;
}
