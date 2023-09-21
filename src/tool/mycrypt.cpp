#include "mycrypt.h"

MyCrypt::MyCrypt()
{

}

QString MyCrypt::calculateMD5(const QString &text)
{
    QByteArray data = text.toUtf8(); // 将文本转换为字节数组
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(data); // 添加要计算哈希值的数据
    QByteArray result = hash.result(); // 获取计算得到的哈希值
    QString md5 = QString(result.toHex()); // 将字节数组转换为十六进制字符串
    return md5;
}

QString MyCrypt::sign(const QString &text, const QString &key) {
    QString textWithKey = text + key;
    QString textSigned = text + "&sign=" + calculateMD5(textWithKey);
    return textSigned;
}
