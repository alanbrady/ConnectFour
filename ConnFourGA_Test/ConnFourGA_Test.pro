#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T00:15:09
#
#-------------------------------------------------

QT       += testlib

TARGET = tst_connfourga_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_connfourga_test.cpp \
    mockplayer.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../ConnFourGA/
include(../ConnFourGA/ConnFourGA_Sources.pri)

HEADERS += \
    mockplayer.h
