#include "SoundcloudApp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Soundcloud");
    QCoreApplication::setOrganizationName("mkroman");
    QCoreApplication::setOrganizationDomain("https://github.com/mkroman/soundcloud");

    SoundcloudApp soundcloud;
    soundcloud.run();

    return a.exec();
}
