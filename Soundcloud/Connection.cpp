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

#include <QUrl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "Connection.h"
#include "Response.h"
#include "Request.h"

namespace Soundcloud {

const char* Connection::SERVICE_URL = "https://api.soundcloud.com/";

Connection::Connection(QObject* parent) :
    QObject(parent)
{
}

void Connection::sendRequest(const Request* request)
{
    QUrl requestUrl(SERVICE_URL);
    QNetworkReply* networkReply;

    // Set the endpoint path
    requestUrl.setPath(request->endpoint());

    // Build the query
    QUrlQuery query;
    QMap<QString, QVariant>::const_iterator it;

    for (it = request->params().constBegin();
         it != request->params().constEnd(); it++) {
        query.addQueryItem(it.key(), it.value().toString());
    }

    // Add the users oauth token
    query.addQueryItem("oauth_token", accessToken_);

    // Set the query
    requestUrl.setQuery(query);

    // Send the request
    qDebug() << requestUrl;

    QNetworkRequest networkRequest(requestUrl);
    networkReply = nam_.get(networkRequest);

    connect(networkReply, SIGNAL(finished()), request, SLOT(finished()));
}

} // namespace Soundcloud
