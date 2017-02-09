#-------------------------------------------------
#
# Project created by QtCreator 2016-10-23T18:24:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainLab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    hi.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    hi.h

FORMS    += mainwindow.ui \
    dialog.ui \
    hi.ui

RESOURCES += \
    res.qrc
