#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket()
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [this](){
        if(m_cookie != "")
            this->sendToServer(this->sign("HEARTBEAT", "", SIGN_KEY));
    });
    m_timer->start(HEARTBEAT_INTERVAL_TIME_MS);

    connect(this, &MyTcpSocket::sigParseResponse, this, &MyTcpSocket::onParseResponse);
}

bool MyTcpSocket::connectToServer() {
    disconnect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReadyRead);
    connectToHost(m_serverAddr, m_serverPort.toInt());
    if (!waitForConnected(MAX_SERVER_WAIT_TIME_MS)) {
        emit sigReturnConnectStatus(CONNECT_FAIL);
        return false;
    }
    if (state() != QAbstractSocket::ConnectedState) {
        emit sigReturnConnectStatus(CONNECT_FAIL);
        return false;
    }
    if(!waitForReadyRead(MAX_SERVER_WAIT_TIME_MS)) {
        emit sigReturnConnectStatus(CONNECT_FAIL);
        return false;
    }
    if(QString(readAll()) != "CONNECTED") {
        emit sigReturnConnectStatus(CONNECT_FAIL);
        return false;
    }
    connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::onReadyRead);
    emit sigReturnConnectStatus(CONNECT_SUCCESS);
    return true;
}

bool MyTcpSocket::sendToServer(const QString &message) {
    if (state() != QAbstractSocket::ConnectedState) {
        if (!connectToServer())
            return false;
    }
    write(message.toUtf8());
//    write("\r\n");
    flush();
    return true;
}

bool MyTcpSocket::recvFromServer(QString *response) {
    if (!waitForReadyRead())
        return false;
    *response = QString(readAll());
    qDebug() << "Server response: " << *response;
    return true;
}

bool MyTcpSocket::closeSocket() {
    if (state() == QAbstractSocket::ConnectedState) {
        sendToServer("EXIT");
        waitForBytesWritten(MAX_SERVER_WAIT_TIME_MS);
        close();
        return true;
    }
    return false;
}

MyTcpSocket::~MyTcpSocket() {
    closeSocket();
}

QString MyTcpSocket::sign(const QString &cmd, const QString &data, const QString &key) {
    if (data == "")
        return cmd + " " + MyCrypt::sign((m_cookie == "" ? "" : "cookie=" + m_cookie), key);
    else
        return cmd + " " + MyCrypt::sign(data + (m_cookie == "" ? "" : "&cookie=" + m_cookie), key);
}

bool MyTcpSocket::setServerAddress(const QString &serverAddr, const QString &serverPort) {
    m_serverAddr = serverAddr;
    m_serverPort = serverPort;
    return true;
}

void MyTcpSocket::onReadyRead() {
    QString response = QString(readAll());
    emit sigParseResponse(response);
}

void MyTcpSocket::onParseResponse(const QString &response) {
    qDebug() << "Recv from server:" << response;

    QStringList responseList = response.split(" ");
    QString cmd = responseList[0].toUpper();
    if (responseList.size() > 1) {
        QString message = responseList[1];
        if (cmd == "ERROR") {
            QString error = message;
            for (int i = 2; i < responseList.size(); i++)
                error = error + " " + responseList[i];
            emit sigErrorResponse(error);
        } else if (cmd == "LOGIN") {
            QString cookie = getValue(message, "cookie");
            QString email = getValue(message, "email");
            QString userName = getValue(message, "username");
            emit sigLoginResponse(cookie, email, userName);
        } else if (cmd == "SETPIECE") {
            int row = getValue(message, "row").toInt();
            int col = getValue(message, "col").toInt();
            ChessType type = getValue(message, "type").toUpper() == "BLACK" ? CHESS_BLACK : CHESS_WHITE;
            emit sigSetpieceResponse(ChessPieceInfo(row, col, type));
        } else if (cmd == "JOIN") {
            QString roomId = getValue(message, "roomid");
            QString roomName = getValue(message, "roomname");
            QString rival = getValue(message, "rival");
            ChessType chessType = getValue(message, "chesstype").toUpper() == "BLACK" ? CHESS_BLACK : CHESS_WHITE;
            emit sigJoinResponse(roomId, roomName, rival, chessType);
        }
    } else {
        if (cmd == "PASSWORD") {
            emit sigPasswordResponse();
        } else if (cmd == "RELOGIN") {
            emit sigReloginResponse();
        } else if (cmd == "SENDCODE") {
            emit sigSendcodeResponse();
        } else if (cmd == "REGISTER") {
            emit sigRegisterResponse();
        }
    }
}

QString MyTcpSocket::getValue(const QString &message, const QString &key) {
    QStringList list = message.split("&");
    for(int i = 0; i < list.size(); i++) {
        if(list[i].split("=")[0].toLower() == key.toLower()) {
            return list[i].split("=")[1];
        } else {
            continue;
        }
    }
    return NULL;
}
