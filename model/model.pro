#-------------------------------------------------
#
# Project created by QtCreator 2017-02-11T20:45:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = model
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylistview.cpp \
    filesystemwidget.cpp \
    spinboxdelegate.cpp \
    sortview.cpp \
    currencymodel.cpp

HEADERS  += mainwindow.h \
    mylistview.h \
    filesystemwidget.h \
    spinboxdelegate.h \
    sortview.h \
    currencymodel.h

FORMS    += mainwindow.ui
