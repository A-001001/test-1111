/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *m_pButton_1;
    QPushButton *m_pButton_2;
    QPushButton *m_pButton_3;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 1000);
        MainWindow->setMinimumSize(QSize(800, 1000));
        MainWindow->setMaximumSize(QSize(800, 1000));
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround2.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_pButton_1 = new QPushButton(centralWidget);
        m_pButton_1->setObjectName(QStringLiteral("m_pButton_1"));
        m_pButton_1->setGeometry(QRect(210, 140, 380, 120));
        QFont font;
        font.setPointSize(20);
        m_pButton_1->setFont(font);
        m_pButton_1->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround1.png);"));
        m_pButton_2 = new QPushButton(centralWidget);
        m_pButton_2->setObjectName(QStringLiteral("m_pButton_2"));
        m_pButton_2->setGeometry(QRect(210, 390, 380, 120));
        m_pButton_2->setFont(font);
        m_pButton_2->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround1.png);"));
        m_pButton_3 = new QPushButton(centralWidget);
        m_pButton_3->setObjectName(QStringLiteral("m_pButton_3"));
        m_pButton_3->setGeometry(QRect(210, 680, 380, 120));
        m_pButton_3->setFont(font);
        m_pButton_3->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround1.png);"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuBar->setStyleSheet(QStringLiteral("image: url(:/res/Title1.png);"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setStyleSheet(QStringLiteral("image: url(:/res/Title1.png);"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        m_pButton_1->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\346\270\270\346\210\217", 0));
        m_pButton_2->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\346\270\270\346\210\217", 0));
        m_pButton_3->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213\345\257\271\346\210\230\346\270\270\346\210\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
