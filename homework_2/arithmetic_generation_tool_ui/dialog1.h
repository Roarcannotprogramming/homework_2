#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QStandardItemModel>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

    QStandardItemModel *wrong_answer_model;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
