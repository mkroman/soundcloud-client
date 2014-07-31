#include <QSettings>

#include "MainWindow.h"
#include "SoundcloudAuthDialog.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hide();

    QSettings settings;

    if (settings.value("accessToken").toString().isEmpty()) {
        _authDialog = new SoundcloudAuthDialog(this);
        _authDialog->show();
    }
    else {
        show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _authDialog;
}
