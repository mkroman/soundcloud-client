/*
 * Copyright (c) 2014, Mikkel Kroman <mk@maero.dk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <QDebug>

#include "Track.h"
#include "SoundcloudApp.h"
#include "TrackListModel.h"
#include "SoundcloudAuthDialog.h"

const char* SoundcloudApp::ClientID = "6eac891d530ac164fb776bbccdc81af6";

SoundcloudApp::SoundcloudApp(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::SoundcloudApp)
{
    ui_->setupUi(this);

    TrackListModel* trackListModel = new TrackListModel(this);
    ui_->trackTableView->setModel(trackListModel);
    ui_->trackTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _client = new Soundcloud::Client(this);

    connect(_client, SIGNAL(userProfileUpdated()), SLOT(clientUserProfileUpdated()));
    connect(_client, &Soundcloud::Client::trackSearchResults, trackListModel, &TrackListModel::onTrackSearchResults);
    // void trackSearchResults(QList<Track> trackList);
}

SoundcloudApp::~SoundcloudApp()
{
    delete _client;
}

bool SoundcloudApp::isAuthenticated()
{
    if (_settings.value("accessToken").toString().isEmpty()) {
        return false;
    }
    else {
        return true;
    }
}

void SoundcloudApp::run()
{
    if (!isAuthenticated()) {
        // Show the authentication dialog

        _authDialog = new SoundcloudAuthDialog(this);
        _authDialog->show();

        connect(_authDialog, SIGNAL(tokenChanged(QString)), this, SLOT(tokenChanged(QString)));
    }
    else {
        _client->setAccessToken(_settings.value("accessToken").toString());
        initializeClient();
    }
}

void SoundcloudApp::initializeClient()
{
    setVisible(true);

    _client->updateUserProfile();
}

void SoundcloudApp::tokenChanged(const QString &accessToken)
{
    qDebug() << "Updated access token";

    _authDialog->deleteLater();

    _settings.setValue("accessToken", accessToken);
    _client->setAccessToken(accessToken);
    initializeClient();
}

void SoundcloudApp::clientUserProfileUpdated()
{

}

void SoundcloudApp::onSearchButtonPressed()
{
    _client->searchTrack(ui_->searchLineEdit->text());
}
