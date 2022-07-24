#-------------------------------------------------
#
# Project created by QtCreator 2022-07-20T14:14:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gobang
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    checkerboard.cpp \
    ckernel.cpp \
    ai.cpp

HEADERS  += mainwindow.h \
    checkerboard.h \
    ckernel.h \
    packdef.h \
    ai.h

FORMS    += mainwindow.ui \
    checkerboard.ui

RESOURCES += \
    ziyuan.qrc
