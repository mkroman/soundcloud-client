#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T20:59:34
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = SoundCloud
TEMPLATE = lib

DEFINES += LIBSOUNDCLOUD_LIBRARY

INCLUDEPATH += $$PWD/../

SOURCES += Client.cpp \
    Connection.cpp \
    Response.cpp \
    User.cpp \
    Track.cpp

HEADERS += libsoundcloud_global.h \
    Client.h \
    Connection.h \
    Response.h \
    User.h \
    Track.h

CONFIG += staticlib

unix {
    target.path = /usr/lib
    headers.path = /usr/include/SoundCloud
    headers.files = $$HEADERS
    INSTALLS += target headers
}
