/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionewwewe;
    QAction *actioncuotiben;
    QAction *actionlishijiu;
    QAction *actionshuchuchengji;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget1;
    QWidget *page;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *page_2;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(581, 440);
        MainWindow->setMinimumSize(QSize(581, 440));
        MainWindow->setMaximumSize(QSize(581, 440));
        actionewwewe = new QAction(MainWindow);
        actionewwewe->setObjectName(QStringLiteral("actionewwewe"));
        actioncuotiben = new QAction(MainWindow);
        actioncuotiben->setObjectName(QStringLiteral("actioncuotiben"));
        actionlishijiu = new QAction(MainWindow);
        actionlishijiu->setObjectName(QStringLiteral("actionlishijiu"));
        actionshuchuchengji = new QAction(MainWindow);
        actionshuchuchengji->setObjectName(QStringLiteral("actionshuchuchengji"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget1 = new QStackedWidget(centralWidget);
        stackedWidget1->setObjectName(QStringLiteral("stackedWidget1"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 30, 301, 171));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 210, 151, 61));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        stackedWidget1->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(11, 35, 301, 192));
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(357, 35, 191, 121));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 210, 151, 71));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 11, 274, 17));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 10, 32, 17));
        lcdNumber = new QLCDNumber(page_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 260, 131, 41));
        stackedWidget1->addWidget(page_2);

        gridLayout->addWidget(stackedWidget1, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 581, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionewwewe);
        menu_2->addAction(actioncuotiben);
        menu_2->addAction(actionlishijiu);
        menu_2->addAction(actionshuchuchengji);
        mainToolBar->addAction(actionewwewe);
        mainToolBar->addAction(actioncuotiben);
        mainToolBar->addAction(actionlishijiu);
        mainToolBar->addAction(actionshuchuchengji);

        retranslateUi(MainWindow);

        stackedWidget1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionewwewe->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\255\224\351\242\230", nullptr));
#ifndef QT_NO_TOOLTIP
        actionewwewe->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\255\224\351\242\230", nullptr));
#endif // QT_NO_TOOLTIP
        actioncuotiben->setText(QApplication::translate("MainWindow", "\351\224\231\351\242\230\346\234\254", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncuotiben->setToolTip(QApplication::translate("MainWindow", "\351\224\231\351\242\230\346\234\254", nullptr));
#endif // QT_NO_TOOLTIP
        actionlishijiu->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#ifndef QT_NO_TOOLTIP
        actionlishijiu->setToolTip(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        actionshuchuchengji->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\346\210\220\347\273\251\345\215\225", nullptr));
#ifndef QT_NO_TOOLTIP
        actionshuchuchengji->setToolTip(QApplication::translate("MainWindow", "\347\224\237\346\210\220\346\210\220\347\273\251\345\215\225", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:33pt; font-weight:600; font-style:italic;\">\346\254\242\350\277\216\347\255\224\351\242\230</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\274\200\345\247\213\347\255\224\351\242\230</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\274\200\345\247\213\347\255\224\351\242\230</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\255\224\351\242\230", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\242\230", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">\347\255\224\346\241\210</span></p></body></html>", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
