#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T04:13:09
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Soundcloud
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    SoundcloudAuthDialog.cpp

HEADERS  += MainWindow.h \
    SoundcloudAuthDialog.h \
    Soundcloud.h

FORMS    += MainWindow.ui
