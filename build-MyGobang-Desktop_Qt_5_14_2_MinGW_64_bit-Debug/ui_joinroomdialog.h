/********************************************************************************
** Form generated from reading UI file 'joinroomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINROOMDIALOG_H
#define UI_JOINROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_JoinRoomDialog
{
public:
    QLabel *label_roomId;
    QLineEdit *lineEdit_roomId;
    QPushButton *btn_cancel;
    QPushButton *btn_join;

    void setupUi(QDialog *JoinRoomDialog)
    {
        if (JoinRoomDialog->objectName().isEmpty())
            JoinRoomDialog->setObjectName(QString::fromUtf8("JoinRoomDialog"));
        JoinRoomDialog->resize(400, 300);
        label_roomId = new QLabel(JoinRoomDialog);
        label_roomId->setObjectName(QString::fromUtf8("label_roomId"));
        label_roomId->setGeometry(QRect(20, 50, 111, 51));
        label_roomId->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        lineEdit_roomId = new QLineEdit(JoinRoomDialog);
        lineEdit_roomId->setObjectName(QString::fromUtf8("lineEdit_roomId"));
        lineEdit_roomId->setGeometry(QRect(130, 50, 231, 51));
        lineEdit_roomId->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_cancel = new QPushButton(JoinRoomDialog);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(130, 210, 91, 61));
        btn_cancel->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));
        btn_join = new QPushButton(JoinRoomDialog);
        btn_join->setObjectName(QString::fromUtf8("btn_join"));
        btn_join->setGeometry(QRect(260, 210, 101, 61));
        btn_join->setStyleSheet(QString::fromUtf8("font: 87 12pt \"Arial\";"));

        retranslateUi(JoinRoomDialog);

        QMetaObject::connectSlotsByName(JoinRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *JoinRoomDialog)
    {
        JoinRoomDialog->setWindowTitle(QCoreApplication::translate("JoinRoomDialog", "Dialog", nullptr));
        label_roomId->setText(QCoreApplication::translate("JoinRoomDialog", "Room ID:", nullptr));
        btn_cancel->setText(QCoreApplication::translate("JoinRoomDialog", "Cancel", nullptr));
        btn_join->setText(QCoreApplication::translate("JoinRoomDialog", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JoinRoomDialog: public Ui_JoinRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINROOMDIALOG_H
