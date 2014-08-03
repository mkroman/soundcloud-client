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

#ifndef SOUNDCLOUD_RESPONSE_H
#define SOUNDCLOUD_RESPONSE_H

#include <QObject>
#include <QVariant>
#include <QJsonDocument>

#include "libsoundcloud_global.h"

namespace Soundcloud {

class LIBSOUNDCLOUDSHARED_EXPORT Response : public QObject
{
    Q_OBJECT

public:
    explicit Response(QObject* parent = 0);
    ~Response();

    /// Returns true if the body isn't empty
    bool success() { return body_.isEmpty(); }

    /// Set the response body (this is a json object)
    void setBody(QJsonDocument document) { body_ = document; }

    /// Return the body of the response
    const QJsonDocument& body() const { return body_; }

signals:
    void finished();

public slots:
    void networkReplyFinished();

private:
    QJsonDocument body_;

};

} // namespace Soundcloud

#endif // SOUNDCLOUD_RESPONSE_H
