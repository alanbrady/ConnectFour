#-------------------------------------------------
#
# Project created by QtCreator 2014-05-14T22:30:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConnFourGA
TEMPLATE = app

SOURCES += ../ConnFourGA/main.cpp\
        ../ConnFourGA/mainwindow.cpp \
    gameboardwidget.cpp

HEADERS  += ../ConnFourGA/mainwindow.h \
    gameboardwidget.h


FORMS += \
    mainwindow.ui


include(ConnFourGA_Sources.pri)


