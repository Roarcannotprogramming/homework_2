#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include <QButtonGroup>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    ~Dialog3();

    /*int opr_num;
    int min_num,max_num;
    int accuracy;*/

    int get_opr_num();
    int get_min_num();
    int get_max_num();
    int get_accuracy();
    int get_type_int();

private slots:
    void on_radioButton_2_toggled(bool checked);

    void on_buttonBox_accepted();

private:
    Ui::Dialog3 *ui;

    QButtonGroup *type;

    int opr_num;
    int min_num,max_num;
    int accuracy;
    int type_int;
};

#endif // DIALOG3_H
