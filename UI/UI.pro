#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T04:13:09
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Soundcloud
TEMPLATE = app

CONFIG += c++11

# Installation
unix:!macx {
    target.path = /usr/bin

    INSTALLS += target
}

SOURCES += main.cpp\
    SoundcloudAuthDialog.cpp \
    SoundcloudApp.cpp \
    TrackListModel.cpp

HEADERS  += \
    SoundcloudAuthDialog.h \
    SoundcloudApp.h \
    TrackListModel.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Soundcloud/release/ -lSoundcloud
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Soundcloud/debug/ -lSoundcloud
else:unix: LIBS += -L$$OUT_PWD/../Soundcloud/ -lSoundcloud

INCLUDEPATH += $$PWD/../Soundcloud
DEPENDPATH += $$PWD/../Soundcloud

FORMS += \
    SoundcloudApp.ui
