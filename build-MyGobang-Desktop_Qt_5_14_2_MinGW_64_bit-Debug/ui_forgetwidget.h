/********************************************************************************
** Form generated from reading UI file 'forgetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETWIDGET_H
#define UI_FORGETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgetWidget
{
public:
    QLineEdit *lineEdit_code;
    QPushButton *btn_send;
    QLineEdit *lineEdit_confirm_password;
    QLabel *label_confirm_password;
    QLabel *label_code;
    QLineEdit *lineEdit_password;
    QPushButton *btn_return;
    QLineEdit *lineEdit_userName;
    QPushButton *btn_change;
    QLabel *label_userName;
    QLabel *label_password;

    void setupUi(QWidget *ForgetWidget)
    {
        if (ForgetWidget->objectName().isEmpty())
            ForgetWidget->setObjectName(QString::fromUtf8("ForgetWidget"));
        ForgetWidget->resize(1280, 720);
        lineEdit_code = new QLineEdit(ForgetWidget);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));
        lineEdit_code->setGeometry(QRect(400, 290, 531, 41));
        lineEdit_code->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_send = new QPushButton(ForgetWidget);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setGeometry(QRect(780, 150, 141, 71));
        btn_send->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_confirm_password = new QLineEdit(ForgetWidget);
        lineEdit_confirm_password->setObjectName(QString::fromUtf8("lineEdit_confirm_password"));
        lineEdit_confirm_password->setGeometry(QRect(400, 460, 531, 41));
        lineEdit_confirm_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
        label_confirm_password = new QLabel(ForgetWidget);
        label_confirm_password->setObjectName(QString::fromUtf8("label_confirm_password"));
        label_confirm_password->setGeometry(QRect(170, 460, 221, 51));
        label_confirm_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_code = new QLabel(ForgetWidget);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        label_code->setGeometry(QRect(180, 290, 141, 51));
        label_code->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_password = new QLineEdit(ForgetWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(410, 380, 531, 41));
        lineEdit_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        btn_return = new QPushButton(ForgetWidget);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(350, 590, 181, 71));
        btn_return->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_userName = new QLineEdit(ForgetWidget);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(400, 170, 351, 41));
        lineEdit_userName->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_change = new QPushButton(ForgetWidget);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));
        btn_change->setGeometry(QRect(610, 590, 221, 71));
        btn_change->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_userName = new QLabel(ForgetWidget);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));
        label_userName->setGeometry(QRect(180, 170, 191, 51));
        label_userName->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        label_password = new QLabel(ForgetWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(180, 380, 141, 51));
        label_password->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(ForgetWidget);

        QMetaObject::connectSlotsByName(ForgetWidget);
    } // setupUi

    void retranslateUi(QWidget *ForgetWidget)
    {
        ForgetWidget->setWindowTitle(QCoreApplication::translate("ForgetWidget", "Form", nullptr));
        btn_send->setText(QCoreApplication::translate("ForgetWidget", "Send Code", nullptr));
        label_confirm_password->setText(QCoreApplication::translate("ForgetWidget", "Confirm Password:", nullptr));
        label_code->setText(QCoreApplication::translate("ForgetWidget", "Verify Code:", nullptr));
        btn_return->setText(QCoreApplication::translate("ForgetWidget", "Return", nullptr));
        btn_change->setText(QCoreApplication::translate("ForgetWidget", "Change Password", nullptr));
        label_userName->setText(QCoreApplication::translate("ForgetWidget", "UserName/Email:", nullptr));
        label_password->setText(QCoreApplication::translate("ForgetWidget", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgetWidget: public Ui_ForgetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETWIDGET_H
