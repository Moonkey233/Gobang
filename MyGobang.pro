QT += core gui network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/dialog/createroomdialog.cpp \
    src/dialog/joinroomdialog.cpp \
    src/tool/player.cpp \
    src/widget/boardwidget.cpp \
    src/widget/forgetwidget.cpp \
    src/widget/gamewidget.cpp \
    src/widget/indexwidget.cpp \
    src/dialog/infodialog.cpp \
    src/widget/loginwidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/tool/mycrypt.cpp \
    src/tool/mytcpsocket.cpp \
    src/widget/mywidget.cpp \
    src/widget/offlinewidget.cpp \
    src/widget/onlinewidget.cpp \
    src/widget/registerwidget.cpp \
    src/dialog/settingdialog.cpp

HEADERS += \
    src/dialog/createroomdialog.h \
    src/dialog/joinroomdialog.h \
    src/tool/config.h \
    src/tool/mychess.h \
    src/tool/player.h \
    src/widget/boardwidget.h \
    src/widget/forgetwidget.h \
    src/widget/gamewidget.h \
    src/widget/indexwidget.h \
    src/dialog/infodialog.h \
    src/widget/loginwidget.h \
    src/mainwindow.h \
    src/tool/mycrypt.h \
    src/tool/mytcpsocket.h \
    src/widget/mywidget.h \
    src/widget/offlinewidget.h \
    src/widget/onlinewidget.h \
    src/widget/registerwidget.h \
    src/dialog/settingdialog.h

FORMS += \
    src/dialog/createroomdialog.ui \
    src/dialog/joinroomdialog.ui \
    src/ui/forgetwidget.ui \
    src/ui/gamewidget.ui \
    src/ui/indexwidget.ui \
    src/ui/infodialog.ui \
    src/ui/loginwidget.ui \
    src/ui/mainwindow.ui \
    src/ui/mywidget.ui \
    src/ui/offlinewidget.ui \
    src/ui/onlinewidget.ui \
    src/ui/registerwidget.ui \
    src/ui/settingdialog.ui \
    src/ui/boardwidget.ui

RESOURCES += \
    res/black.png \
    res/white.png \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
