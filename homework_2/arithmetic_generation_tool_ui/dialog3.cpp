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

    ui->label_5->setVisible(false);
    ui->lineEdit_4->setVisible(false);
    ui->label_6->setVisible(false);


//接下来写如果是小数，就显示小数点精度
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_radioButton_2_toggled(bool checked)
{
    if (!checked){
        ui->label_5->setVisible(false);
        ui->lineEdit_4->setVisible(false);
        ui->label_6->setVisible(false);
    }
    else{
        ui->label_5->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->label_6->setVisible(true);
    }
}

void Dialog3::on_buttonBox_accepted()
{
    if(!ui->lineEdit->text().isEmpty()){
        opr_num = ui->lineEdit->text().toInt();
    }

    if(!ui->lineEdit_2->text().isEmpty()){
        min_num = ui->lineEdit_2->text().toInt();
    }

    if(!ui->lineEdit_3->text().isEmpty()){
        max_num = ui->lineEdit_3->text().toInt();
    }

    if(!ui->lineEdit_4->text().isEmpty()){
        accuracy = ui->lineEdit_4->text().toInt();
    }
}

int Dialog3::get_opr_num(){
    return opr_num;
}

int Dialog3::get_min_num(){
    return min_num;
}

int Dialog3::get_max_num(){
    return max_num;
}

int Dialog3::get_accuracy(){
    return accuracy;
}
