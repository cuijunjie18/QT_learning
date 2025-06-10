/********************************************************************************
** Form generated from reading UI file 'cjj.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CJJ_H
#define UI_CJJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(577, 395);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 90, 171, 61));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 220, 151, 61));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CJJ_Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CJJ_H
