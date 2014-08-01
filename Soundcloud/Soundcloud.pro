#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T20:59:34
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = Soundcloud
TEMPLATE = lib

DEFINES += LIBSOUNDCLOUD_LIBRARY

SOURCES += Client.cpp \
    Request.cpp \
    Connection.cpp \
    Response.cpp

HEADERS += libsoundcloud_global.h \
    Client.h \
    Request.h \
    Connection.h \
    Response.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
