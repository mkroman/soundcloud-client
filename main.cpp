#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Soundcloud");
    QCoreApplication::setOrganizationName("mkroman");
    QCoreApplication::setOrganizationDomain("https://github.com/mkroman/soundcloud");

    MainWindow w;
    w.show();

    return a.exec();
}
