#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T18:19:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainLab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    table.cpp \
    vhod.cpp

HEADERS  += mainwindow.h \
    table.h \
    vhod.h

FORMS    += mainwindow.ui \
    table.ui \
    vhod.ui

RESOURCES += \
    res.qrc
