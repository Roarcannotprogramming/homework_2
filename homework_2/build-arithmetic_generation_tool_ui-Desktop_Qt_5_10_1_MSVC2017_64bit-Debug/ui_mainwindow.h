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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *page_2;
    QCheckBox *checkBox;
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
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 30, 301, 171));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 210, 151, 61));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        checkBox = new QCheckBox(page_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(220, 190, 91, 19));
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

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

        stackedWidget->setCurrentIndex(0);


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
        checkBox->setText(QApplication::translate("MainWindow", "123", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
