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

#ifndef SOUNDCLOUDAUTHDIALOG_H
#define SOUNDCLOUDAUTHDIALOG_H

#include <QDialog>
#include <QUrl>
#include <QUrlQuery>
#include "SoundcloudApp.h"

class QWebView;
class QVBoxLayout;

class SoundcloudAuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SoundcloudAuthDialog(QWidget *parent = 0);
    ~SoundcloudAuthDialog();
    static const QString SUCCESSFUL_REDIRECT_URL;

public:

    const QUrl buildOAuthUrl()
    {
        QUrl authUrl("https://soundcloud.com/connect");
        QUrlQuery queryItems;

        queryItems.addQueryItem("redirect_uri", "https://developers.soundcloud.com/callback.html");
        queryItems.addQueryItem("response_type", "code_and_token");
        queryItems.addQueryItem("scope", "non-expiring");
        queryItems.addQueryItem("display", "popup");
        queryItems.addQueryItem("client_id", SoundcloudApp::ClientID);

        authUrl.setQuery(queryItems);

        return authUrl;
    }

public slots:
    void onWebViewUrlChanged(const QUrl& url);

signals:
    void tokenChanged(const QString& accessToken);

private:
    QWebView* _webView;
    QVBoxLayout* _verticalLayout;
};

#endif // SOUNDCLOUDAUTHDIALOG_H
