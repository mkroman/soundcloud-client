#include "SoundCloudApp.h"
#include "SoundCloudX.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("SoundCloud");
    QCoreApplication::setOrganizationName("mkroman");
    QCoreApplication::setOrganizationDomain("https://github.com/mkroman/soundcloud");

    SoundCloudX soundCloud;
    soundCloud.show();

    return a.exec();
}
