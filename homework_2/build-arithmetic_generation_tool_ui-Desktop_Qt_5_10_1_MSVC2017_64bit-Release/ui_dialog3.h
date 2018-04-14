/********************************************************************************
** Form generated from reading UI file 'dialog3.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG3_H
#define UI_DIALOG3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog3
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_6;

    void setupUi(QDialog *Dialog3)
    {
        if (Dialog3->objectName().isEmpty())
            Dialog3->setObjectName(QStringLiteral("Dialog3"));
        Dialog3->resize(619, 396);
        buttonBox = new QDialogButtonBox(Dialog3);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 101, 31));
        lineEdit = new QLineEdit(Dialog3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 60, 113, 31));
        label_2 = new QLabel(Dialog3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(71, 110, 81, 20));
        radioButton = new QRadioButton(Dialog3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(170, 110, 115, 19));
        radioButton_2 = new QRadioButton(Dialog3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(230, 110, 115, 19));
        radioButton_3 = new QRadioButton(Dialog3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(290, 110, 115, 19));
        label_3 = new QLabel(Dialog3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 101, 16));
        label_4 = new QLabel(Dialog3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 200, 101, 20));
        label_5 = new QLabel(Dialog3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 240, 91, 20));
        lineEdit_2 = new QLineEdit(Dialog3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 160, 113, 21));
        lineEdit_3 = new QLineEdit(Dialog3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 200, 113, 21));
        lineEdit_4 = new QLineEdit(Dialog3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 240, 31, 21));
        label_6 = new QLabel(Dialog3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 240, 72, 15));

        retranslateUi(Dialog3);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog3, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog3, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog3);
    } // setupUi

    void retranslateUi(QDialog *Dialog3)
    {
        Dialog3->setWindowTitle(QApplication::translate("Dialog3", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("Dialog3", "<html><head/><body><p align=\"center\">\350\277\220\347\256\227\347\254\246\346\225\260\357\274\232</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Dialog3", "\350\241\250\350\276\276\345\274\217\347\261\273\345\236\213:", nullptr));
        radioButton->setText(QApplication::translate("Dialog3", "\346\225\264\346\225\260", nullptr));
        radioButton_2->setText(QApplication::translate("Dialog3", "\345\260\217\346\225\260", nullptr));
        radioButton_3->setText(QApplication::translate("Dialog3", "\345\210\206\346\225\260", nullptr));
        label_3->setText(QApplication::translate("Dialog3", "<html><head/><body><p align=\"center\">\346\223\215\344\275\234\346\225\260\346\234\200\345\260\217\345\200\274\357\274\232</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Dialog3", "<html><head/><body><p align=\"center\">\346\223\215\344\275\234\346\225\260\346\234\200\345\244\247\345\200\274\357\274\232</p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Dialog3", "<html><head/><body><p align=\"center\">\345\260\217\346\225\260\347\202\271\345\220\216\344\277\235\347\225\231</p></body></html>", nullptr));
        label_6->setText(QApplication::translate("Dialog3", "\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog3: public Ui_Dialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG3_H
