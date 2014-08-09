#-------------------------------------------------
#
# Project created by QtCreator 2014-07-31T04:13:09
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundCloud
TEMPLATE = app

CONFIG += c++11

# Installation
unix:!macx {
    target.path = /usr/bin

    INSTALLS += target
}

SOURCES += main.cpp\
    SoundCloudAuthDialog.cpp \
    SoundCloudApp.cpp \
    TrackListModel.cpp \
    SoundCloudX.cpp \
    SoundCloudMenuBar.cpp

HEADERS  += \
    SoundCloudAuthDialog.h \
    SoundCloudApp.h \
    TrackListModel.h \
    SoundCloudX.h \
    SoundCloudMenuBar.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SoundCloud/release/ -lSoundCloud
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SoundCloud/debug/ -lSoundCloud
else:unix: LIBS += -L$$OUT_PWD/../SoundCloud/ -lSoundCloud

INCLUDEPATH += $$PWD/../SoundCloud
DEPENDPATH += $$PWD/../SoundCloud

FORMS += \
    SoundCloudApp.ui \
    SoundCloudX.ui \
    SoundCloudMenuBar.ui

RESOURCES += \
    Resources.qrc
