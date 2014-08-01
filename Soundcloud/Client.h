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

#ifndef SOUNDCLOUD_CLIENT_H
#define SOUNDCLOUD_CLIENT_H

#include <QObject>

#include "libsoundcloud_global.h"

namespace Soundcloud {

class Response;
class Connection;

class LIBSOUNDCLOUDSHARED_EXPORT Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject* parent = 0);
    ~Client();

    /// Request the users personal information
    void requestPersona();

public:

    /// Set the access token
    void setAccessToken(const QString& accessToken);

signals:

public slots:
    void updatePersona(const Response& response);

private:
    Connection* connection_; /// The soundcloud connection.
};

} // namespace Soundcloud

#endif // SOUNDCLOUD_CLIENT_H
