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

#ifndef SOUNDCLOUD_CONNECTION_H
#define SOUNDCLOUD_CONNECTION_H

#include <QObject>
#include <QNetworkAccessManager>

#include "libsoundcloud_global.h"

namespace Soundcloud {

class Request;

class LIBSOUNDCLOUDSHARED_EXPORT Connection : public QObject
{
    Q_OBJECT

public:
    static const char* SERVICE_URL;

    explicit Connection(QObject* parent = 0);

    /// Set the access token
    void setAccessToken(const QString& accessToken) { accessToken_ = accessToken; }

    /// Send a new request
    void sendRequest(const Request* request);

signals:

public slots:

private:
    QString accessToken_;
    QNetworkAccessManager nam_;
};

} // namespace Soundcloud

#endif // SOUNDCLOUD_CONNECTION_H
