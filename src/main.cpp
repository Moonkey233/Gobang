/*************************************************************************
 *  @Project:        MyGobang
 *  @Author:         Moonkey_
 *  @Email:          Moonkey233@foxmail.com
 *  @namespace       https://github.com/Moonkey233/MyGobang
 *  @Version:        1.0.0
 *  @Last change:    2023-06-07
 *  @Description     A gobang game both can online and Ai-Hunman play.
 *  @Copyright       All rights reserved copyright © 2023 Moonkey_
*************************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
