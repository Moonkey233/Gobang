#include "mywidget.h"

MyWidget::MyWidget(QSharedPointer<MyTcpSocket> socket, QWidget *parent) :
    QWidget(parent)
{
    m_socket = socket;
}

MyWidget::~MyWidget()
{
    m_socket.clear();
}
