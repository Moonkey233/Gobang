import smtplib
from email.mime.text import MIMEText
from email.header import Header
import threading
import pymysql
import hashlib
import socket
import random
import uuid
import time

SERVER_PORT = 8888
MYSQL_SERVER = "www.Moonkey.top"
MYSQL_USERNAME = "root"
MYSQL_PASSWORD = "1206"
serverAddress = ('0.0.0.0', SERVER_PORT)


class MyEmail:

    def __init__(self):
        self.server = 'SMTP.Moonkey.top'
        self.sender = 'Moonkey_Support@Moonkey.top'
        self.password = 'Mok_em@Moo.1315#'
        self.port = 465

    def sendMail(self, title, receiver, content):
        # noinspection PyBroadException
        try:
            message = MIMEText(content, 'plain', 'utf-8')  # 发送内容 （文本内容，发送格式，编码格式）
            message['From'] = self.sender
            message['To'] = receiver
            message['Subject'] = Header(title, 'utf-8')
            server = smtplib.SMTP_SSL(self.server, self.port)
            server.login(self.sender, self.password)
            server.sendmail(self.sender, [receiver], message.as_string())
            server.quit()
            print('Email sent successfully.')
        except Exception as e:
            print('Failed to send email: ', e)

    def sendCode(self, emailAddr, code):
        self.sendMail("验证码", emailAddr, code)


class MyMySql:

    def __init__(self):
        self.conn = pymysql.connect(
            host=MYSQL_SERVER,
            user=MYSQL_USERNAME,
            password=MYSQL_PASSWORD
        )
        self.cursor = self.conn.cursor()
        # 创建数据库
        self.execute("CREATE DATABASE IF NOT EXISTS GOBANG")
        # 切换到新创建的数据库
        self.execute("USE GOBANG")
        # 创建用户表
        self.execute("""
            CREATE TABLE IF NOT EXISTS User (
            id INT AUTO_INCREMENT PRIMARY KEY,
            username VARCHAR(32) NOT NULL,
            password VARCHAR(32) NOT NULL,
            email VARCHAR(32) NOT NULL,
            salt VARCHAR(32) NOT NULL,
            registration_date DATETIME DEFAULT CURRENT_TIMESTAMP);
        """
                     )
        self.execute("""
            CREATE TABLE IF NOT EXISTS Cookie (
            id INT PRIMARY KEY,
            cookie VARCHAR(32) NOT NULL,
            expiration INT NOT NULL);
        """
                     )

    def close(self):
        self.conn.close()

    def isExistData(self, dataName, data, table="User"):
        # 查询用户表中是否存在指定的用户名
        self.execute(f"SELECT * FROM {table} WHERE {dataName} = '{data}'")
        # 获取查询结果的行数
        row_count = self.cursor.rowcount
        # 如果行数大于0，则用户已存在
        if row_count > 0:
            return True
        else:
            return False

    def execute(self, cmd):
        command = f"{cmd}"
        self.cursor.execute(command)
        self.conn.commit()

    def query(self, cmd):
        self.execute(cmd)
        return self.cursor.fetchone()

    def addUser(self, name, password, email, salt):
        self.execute(
            f"INSERT INTO User (username, password, email, salt) VALUES ('{name}', '{password}', '{email}', '{salt}')")


class MyServer:

    def __init__(self):
        self.codeDict = {}
        self.client = {}
        self.room = {}
        self.publicRoom = []

    @staticmethod
    def calculateMd5(string: str) -> str:
        md5_hash = hashlib.md5()
        md5_hash.update(string.encode('utf-8'))
        return md5_hash.hexdigest().lower()

    @staticmethod
    def salt16() -> str:
        strs = "0123456789abcdef"
        salt = ""
        for i in range(0, 16):
            s = random.randint(0, 15)
            salt += strs[s]
        return salt

    @staticmethod
    def generateCode() -> str:
        # 生成随机的6位验证码
        code = random.randint(100000, 999999)
        return str(code)

    def startServer(self):
        # 创建 TCP 套接字
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind(serverAddress)
        server_socket.listen(1)

        print("Server listening on {}:{}".format(serverAddress[0], serverAddress[1]))

        while True:
            # 等待客户端连接
            clientSocket, clientAddress = server_socket.accept()
            clientSocket.send("CONNECTED".encode(encoding="utf-8"))
            print("connected")
            # 创建一个新的线程处理客户端
            threading.Thread(target=self.handleClient, args=(clientSocket,)).start()

    def checkData(self, data: str) -> bool:
        message = data.split(" ")[1][:-38] + "xyloveyy1314like"
        sign = data.split(" ")[1][-32:]
        if self.calculateMd5(message) == sign:
            return True
        else:
            return False

    def handleClient(self, clientSocket):
        while True:
            # 接收客户端发送的邮件地址
            response = ""
            data = clientSocket.recv(1024).decode().strip()

            print(data)

            if data == "EXIT" or data == '':
                break

            if not self.checkData(data):
                response = "ERROR sign"
                clientSocket.send(response.encode())
                break

            message = data[:-38].split(" ")
            message[0] = message[0].upper()
            myMySql = MyMySql()

            if message[0] == "SENDCODE":
                emailAddr = message[1]
                # 处理邮件地址（这里仅打印邮件地址）
                myEmail = MyEmail()
                verifyCode = self.generateCode()
                myEmail.sendCode(emailAddr, verifyCode)

                # 发送响应给客户端
                response = "SENDCODE"
                self.codeDict[emailAddr] = {
                    "timeStamp": time.time(),
                    "verifyCode": verifyCode
                }

            elif message[0] == "REGISTER":
                parameter = message[1].split("&")
                emailAddr = ""
                userName = ""
                password = ""
                verifyCode = ""
                for i in parameter:
                    if i.split("=")[0] == "email":
                        emailAddr = i.split("=")[1]
                    elif i.split("=")[0] == "username":
                        userName = i.split("=")[1]
                    elif i.split("=")[0] == "password":
                        password = i.split("=")[1]
                    elif i.split("=")[0] == "verifycode":
                        verifyCode = i.split("=")[1]

                if emailAddr in self.codeDict:
                    if self.codeDict[emailAddr]["verifyCode"] == verifyCode and \
                            time.time() - self.codeDict[emailAddr]["timeStamp"] < 180:
                        if not myMySql.isExistData("username", userName, "User") \
                                and not myMySql.isExistData("email", emailAddr, "User"):
                            salt = self.salt16()
                            password = self.calculateMd5(password + salt)
                            myMySql.addUser(userName, password, emailAddr, salt)
                            response = "REGISTER"
                        else:
                            response = "ERROR username or email"
                    else:
                        response = "ERROR verifycode"
                else:
                    response = "ERROR verifycode"

            elif message[0] == "LOGIN":
                parameter = message[1].split("&")
                userName = ""
                password = ""
                for i in parameter:
                    if i.split("=")[0] == "username":
                        userName = i.split("=")[1]
                    elif i.split("=")[0] == "password":
                        password = i.split("=")[1]

                if myMySql.isExistData("username", userName, "User") or myMySql.isExistData("email", userName, "User"):
                    query = f"SELECT password, salt, id, email, username FROM User \
                    WHERE username = '{userName}' or email = '{userName}'"
                    result = myMySql.query(query)
                    if self.calculateMd5(password + result[1]) == result[0]:
                        cookie = uuid.uuid4().hex.lower()
                        if myMySql.isExistData("id", result[2], "Cookie"):
                            myMySql.execute(
                                f"UPDATE Cookie SET expiration = '{int(time.time()) + 604800}', \
                                cookie = '{cookie}' WHERE id = '{result[2]}'"
                            )
                        else:
                            myMySql.execute(
                                f"INSERT INTO Cookie (id, cookie, expiration) VALUES \
                                ('{result[2]}', '{cookie}', '{int(time.time()) + 604800}')"
                            )
                        response = f"LOGIN cookie={cookie}&email={result[3]}&username={result[4]}"
                    else:
                        response = "ERROR password"
                else:
                    response = "ERROR username"

            elif message[0] == "AUTOLOGIN":
                cookie = message[1].split("=")[1]
                if myMySql.isExistData("cookie", cookie, "Cookie"):
                    result = myMySql.query(f"SELECT expiration, id FROM Cookie WHERE cookie = '{cookie}'")
                    if result[0] >= time.time():
                        result = myMySql.query(f"SELECT email, username FROM User WHERE id = '{result[1]}'")
                        response = f"LOGIN cookie={cookie}&email={result[0]}&username={result[1]}"
                    else:
                        response = f"RELOGIN"
                else:
                    response = "ERROR wrong cookie"

            elif message[0] == "PASSWORD":
                parameter = message[1].split("&")
                emailAddr = ""
                password = ""
                verifyCode = ""
                for i in parameter:
                    if i.split("=")[0] == "email":
                        emailAddr = i.split("=")[1]
                    elif i.split("=")[0] == "password":
                        password = i.split("=")[1]
                    elif i.split("=")[0] == "verifycode":
                        verifyCode = i.split("=")[1]

                if emailAddr in self.codeDict:
                    if self.codeDict[emailAddr]["verifyCode"] == verifyCode and \
                            time.time() - self.codeDict[emailAddr]["timeStamp"] < 180:
                        if myMySql.isExistData("email", emailAddr, "User"):
                            result = myMySql.query(f"SELECT salt, id from User WHERE email = '{emailAddr}'")
                            salt = result[0]
                            userId = result[1]
                            password = self.calculateMd5(password + salt)
                            myMySql.execute(f"UPDATE User SET password = '{password}' WHERE id = '{userId}'")
                            myMySql.execute(f"UPDATE Cookie SET expiration = '0' WHERE id = '{userId}'")
                            response = "PASSWORD"
                        else:
                            response = "ERROR emailAddress"
                    else:
                        response = "ERROR verifycode"
                else:
                    response = "ERROR verifycode"

            elif message[0] == "HEARTBEAT":
                # 将新连接的客户端加入客户端列表
                parameter = message[1].split("&")
                cookie = ""
                for i in parameter:
                    if i.split("=")[0] == "cookie":
                        cookie = i.split("=")[1]
                self.client[cookie] = {"socket": clientSocket, "timeStamp": time.time()}

            elif message[0] == "CREATE":
                parameter = message[1].split("&")
                cookie = ""
                roomName = ""
                chessType = ""
                isPublicRoom = True
                for i in parameter:
                    if i.split("=")[0] == "cookie":
                        cookie = i.split("=")[1]
                    elif i.split("=")[0] == "roomname":
                        roomName = i.split("=")[1]
                    elif i.split("=")[0] == "public":
                        isPublicRoom = i.split("=")[1] == "true"
                    elif i.split("=")[0] == "chesstype":
                        chessType = i.split("=")[1]
                roomId = str(uuid.uuid4())[0:6].lower() + hex(int(time.time() / 256)).lower()[2:]
                if chessType == "black":
                    self.room[roomId] = ({"name": roomName, "black": cookie, "white": 0, "live": []})
                else:
                    self.room[roomId] = ({"name": roomName, "black": 0, "white": cookie, "live": []})
                if isPublicRoom:
                    self.publicRoom.append(roomId)

                response = f"JOIN roomid={roomId}&roomname={roomName}&chesstype={chessType}&rival=null"

            elif message[0] == "JOIN":
                parameter = message[1].split("&")
                cookie = ""
                roomId = ""
                userName = ""
                for i in parameter:
                    if i.split("=")[0] == "cookie":
                        cookie = i.split("=")[1]
                    elif i.split("=")[0] == "roomid":
                        roomId = i.split("=")[1]
                    elif i.split("=")[0] == "username":
                        userName = i.split("=")[1]
                result = myMySql.query(
                    f"SELECT username "
                    f"FROM Cookie "
                    f"JOIN User "
                    f"ON Cookie.id = User.id "
                    f"WHERE Cookie.cookie = '{cookie}'"
                )
                chessType = ""
                if self.room[roomId]["black"] == 0:
                    chessType = "black"
                    self.client[self.room[roomId]["white"]]["socket"].send(
                        f"NEWJOIN username={userName}&type={chessType}".encode(encoding="utf-8")
                    )
                elif self.room[roomId]["white"] == 0:
                    chessType = "white"
                    self.client[self.room[roomId]["black"]]["socket"].send(
                        f"NEWJOIN username={userName}&type={chessType}".encode(encoding="utf-8")
                    )
                else:
                    response = "ERROR room is full"

                if chessType != "":
                    response = f"JOIN roomid={roomId}&roomname={self.room[roomId]['name']}" \
                               f"&chesstype={chessType}&rival={result[0]}"
                    self.room[roomId][chessType] = cookie
                    for c in self.room[roomId]["live"]:
                        self.client[c]["socket"].send(
                            f"NEWJOIN username={userName}&type={chessType}".encode(encoding="utf-8")
                        )

            elif message[0] == "SETPIECE":
                parameter = message[1].split("&")
                row = ""
                col = ""
                chessType = ""
                roomId = ""
                for i in parameter:
                    if i.split("=")[0] == "row":
                        row = i.split("=")[1]
                    elif i.split("=")[0] == "col":
                        col = i.split("=")[1]
                    elif i.split("=")[0] == "type":
                        chessType = i.split("=")[1]
                    elif i.split("=")[0] == "roomid":
                        roomId = i.split("=")[1]
                rivalType = "black"
                if chessType.upper() == "BLACK":
                    rivalType = "white"
                self.client[self.room[roomId][rivalType]]["socket"].send(
                    f"SETPIECE row={row}&col={col}&type={chessType}".encode(encoding="utf-8")
                )

            else:
                print(message)

            print(response)
            clientSocket.send(response.encode())

        # 关闭客户端套接字
        clientSocket.close()
        print("disconnected")


def main():
    # 启动服务器
    myServer = MyServer()
    myServer.startServer()


if __name__ == '__main__':
    main()
