#-------------------------------------------------
#
# Project created by QtCreator 2014-08-21T19:55:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

SUBDIRS = resources

SOURCES += main.cpp\
        mainwindow.cpp \
    logmodelextended.cpp

HEADERS  += mainwindow.h \
    logmodelextended.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resource.qrc
