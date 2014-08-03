#include "SoundCloudApp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Soundcloud");
    QCoreApplication::setOrganizationName("mkroman");
    QCoreApplication::setOrganizationDomain("https://github.com/mkroman/soundcloud");

    SoundCloudApp soundCloud;
    soundCloud.run();

    return a.exec();
}
