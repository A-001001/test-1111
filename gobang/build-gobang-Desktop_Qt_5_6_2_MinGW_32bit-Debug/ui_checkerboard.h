/********************************************************************************
** Form generated from reading UI file 'checkerboard.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKERBOARD_H
#define UI_CHECKERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkerboard
{
public:
    QPushButton *c_pButton_1;
    QPushButton *c_pButton_2;
    QPushButton *c_pButton_3;

    void setupUi(QWidget *checkerboard)
    {
        if (checkerboard->objectName().isEmpty())
            checkerboard->setObjectName(QStringLiteral("checkerboard"));
        checkerboard->resize(1350, 1050);
        checkerboard->setMinimumSize(QSize(1350, 1050));
        checkerboard->setMaximumSize(QSize(1350, 1050));
        checkerboard->setStyleSheet(QLatin1String("background-image: url(:/res/BackGround1.png);\n"
""));
        c_pButton_1 = new QPushButton(checkerboard);
        c_pButton_1->setObjectName(QStringLiteral("c_pButton_1"));
        c_pButton_1->setGeometry(QRect(1100, 490, 190, 71));
        QFont font;
        font.setPointSize(20);
        c_pButton_1->setFont(font);
        c_pButton_1->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround2.png);"));
        c_pButton_2 = new QPushButton(checkerboard);
        c_pButton_2->setObjectName(QStringLiteral("c_pButton_2"));
        c_pButton_2->setGeometry(QRect(1100, 660, 191, 71));
        c_pButton_2->setFont(font);
        c_pButton_2->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround2.png);"));
        c_pButton_3 = new QPushButton(checkerboard);
        c_pButton_3->setObjectName(QStringLiteral("c_pButton_3"));
        c_pButton_3->setGeometry(QRect(1100, 810, 191, 71));
        c_pButton_3->setFont(font);
        c_pButton_3->setStyleSheet(QStringLiteral("background-image: url(:/res/BackGround2.png);"));

        retranslateUi(checkerboard);

        QMetaObject::connectSlotsByName(checkerboard);
    } // setupUi

    void retranslateUi(QWidget *checkerboard)
    {
        checkerboard->setWindowTitle(QApplication::translate("checkerboard", "Form", 0));
        c_pButton_1->setText(QApplication::translate("checkerboard", "\346\202\224\346\243\213", 0));
        c_pButton_2->setText(QApplication::translate("checkerboard", "\350\256\244\350\276\223", 0));
        c_pButton_3->setText(QApplication::translate("checkerboard", "\351\200\200\345\207\272\346\270\270\346\210\217", 0));
    } // retranslateUi

};

namespace Ui {
    class checkerboard: public Ui_checkerboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKERBOARD_H
