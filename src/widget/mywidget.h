#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QResizeEvent>
#include <QtConcurrent/QtConcurrent>
#include "../tool/mytcpsocket.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent = nullptr);
    ~MyWidget();

protected:

    virtual bool connectSlot() = 0;
    QSharedPointer<MyTcpSocket> m_socket;

private slots:

signals:
    void changeWidgetSignal(const QString &widgetName);

};

#endif // MYWIDGET_H
