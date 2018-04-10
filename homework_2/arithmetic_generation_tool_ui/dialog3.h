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

private:
    Ui::Dialog3 *ui;

    QButtonGroup *type;

    int opr_num;
    int min_num,max_num;
    int accuracy;
};

#endif // DIALOG3_H
