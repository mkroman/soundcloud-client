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

#ifndef SOUNDCLOUD_H
#define SOUNDCLOUD_H

#include <QWidget>
#include <QSettings>

#include "../Soundcloud/Client.h"

class SoundcloudAuthDialog;

class SoundcloudApp : public QWidget
{
    Q_OBJECT

public:
    static const char* ClientID;

    explicit SoundcloudApp(QWidget* parent = 0);
    ~SoundcloudApp();

    /// Run the main application.
    void run();

    /// Initialize the user session, etc.
    void initialize();

    /// Return true if the user has already authenticated.
    bool isAuthenticated();

    /// Return the settings.
    QSettings& settings()
    {
        return _settings;
    }

public slots:
    void tokenChanged(const QString& accessToken);

private:
    Soundcloud::Client* _client;

    QSettings _settings;

    /// The soundcloud auth dialog.
    SoundcloudAuthDialog* _authDialog;
};

#endif // SOUNDCLOUD_H
