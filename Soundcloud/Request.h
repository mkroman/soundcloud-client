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

#ifndef SOUNDCLOUD_REQUEST_H
#define SOUNDCLOUD_REQUEST_H

#include <QObject>
#include <QVariantMap>

#include "libsoundcloud_global.h"

namespace Soundcloud {

class Response;

class LIBSOUNDCLOUDSHARED_EXPORT Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject* parent = 0);
    explicit Request(const QString& endpoint, QObject* parent = 0);
    explicit Request(const QString& endpoint, QVariantMap& params, QObject* parent = 0);

public:
    /// Set the endpoint
    void setEndpoint(const QString& endpoint) { endpoint_ = endpoint; }

    /// Set the parameters
    void setParams(const QVariantMap& params) { params_ = params; }

public:

    /// Return the endpoint
    const QString& endpoint() const { return endpoint_; }

    /// Return the parameters
    const QVariantMap& params() const { return params_; }

signals:
    void response(Response* response);

public slots:
    void finished();

private:
    QString endpoint_;
    QVariantMap params_;
};

} // namespace Soundcloud

#endif // SOUNDCLOUD_REQUEST_H
