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
#include <QWebView>
#include <QVBoxLayout>
#include <QSettings>

#include "Soundcloud.h"
#include "SoundcloudAuthDialog.h"

const QString SoundcloudAuthDialog::SUCCESSFUL_REDIRECT_URL = "https://developers.soundcloud.com/callback.html";

SoundcloudAuthDialog::SoundcloudAuthDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(437, 566);

    _verticalLayout = new QVBoxLayout(this);
    _verticalLayout->setSpacing(0);
    _verticalLayout->setContentsMargins(0, 0, 0, 0);

    _webView = new QWebView(this);
    _webView->setUrl(this->buildOAuthUrl());

    qDebug() << _webView->url();

    _verticalLayout->addWidget(_webView);

    connect(_webView, SIGNAL(urlChanged(QUrl)), SLOT(onWebViewUrlChanged(QUrl)));
}

SoundcloudAuthDialog::~SoundcloudAuthDialog()
{
    delete _webView;
    delete _verticalLayout;
}

void SoundcloudAuthDialog::onWebViewUrlChanged(const QUrl &url)
{
    if (!url.isEmpty() && url.toString().startsWith(SUCCESSFUL_REDIRECT_URL)) {
        QString accessToken = url.fragment();

        accessToken = accessToken.split("&").first();
        accessToken = accessToken.split("=").at(1);

        emit authenticated(accessToken);

        close();
    }

    qDebug() << Q_FUNC_INFO << url;
}
