#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

    opr_num = 5;
    min_num = 0;
    max_num = 100;
    accuracy = 2;

    type = new QButtonGroup(this);
    type->addButton(ui->radioButton,0);
    type->addButton(ui->radioButton_2,1);
    type->addButton(ui->radioButton_3,2);
    ui->radioButton->setChecked(true);
//接下来写如果是小数，就显示小数点精度
}

Dialog3::~Dialog3()
{
    delete ui;
}
