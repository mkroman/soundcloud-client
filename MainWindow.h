#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class SoundcloudAuthDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    SoundcloudAuthDialog* _authDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
