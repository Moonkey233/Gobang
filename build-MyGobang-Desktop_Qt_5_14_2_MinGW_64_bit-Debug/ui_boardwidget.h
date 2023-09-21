/********************************************************************************
** Form generated from reading UI file 'boardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDWIDGET_H
#define UI_BOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardWidget
{
public:

    void setupUi(QWidget *BoardWidget)
    {
        if (BoardWidget->objectName().isEmpty())
            BoardWidget->setObjectName(QString::fromUtf8("BoardWidget"));
        BoardWidget->resize(640, 640);

        retranslateUi(BoardWidget);

        QMetaObject::connectSlotsByName(BoardWidget);
    } // setupUi

    void retranslateUi(QWidget *BoardWidget)
    {
        BoardWidget->setWindowTitle(QCoreApplication::translate("BoardWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoardWidget: public Ui_BoardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDWIDGET_H
