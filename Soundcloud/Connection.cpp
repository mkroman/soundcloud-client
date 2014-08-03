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

#include "Client.h"
#include "Connection.h"
#include "Response.h"

namespace Soundcloud {

const char* Connection::SERVICE_URL = "https://api.soundcloud.com/";

Connection::Connection(QObject* parent) :
    QObject(parent),
    client_(qobject_cast<Client*>(parent))
{
}

Response* Connection::get(const QString& path)
{
    QUrl requestUrl = buildRequestUrl(path);
    QNetworkRequest networkRequest(requestUrl);
    QNetworkReply* networkReply;
    Response* soundcloudResponse = new Response(this);

    networkReply = nam_.get(networkRequest);

    connect(networkReply, SIGNAL(finished()), soundcloudResponse, SLOT(networkReplyFinished()));

    return soundcloudResponse;
}

Response* Connection::get(const QString& path, const QVariantMap& params)
{
    QUrl requestUrl = buildRequestUrl(path, params);
    QNetworkRequest networkRequest(requestUrl);
    QNetworkReply* networkReply;
    Response* soundcloudResponse = new Response(this);

    networkReply = nam_.get(networkRequest);
    networkReply->setParent(soundcloudResponse);

    connect(networkReply, SIGNAL(finished()), soundcloudResponse, SLOT(networkReplyFinished()));

    return soundcloudResponse;
}

QUrl Connection::buildRequestUrl(const QString& path, const QVariantMap& params)
{
    QUrl requestUrl(SERVICE_URL);
    QUrlQuery urlQuery;

    // Add all the variant types as parameters
    QVariantMap::const_iterator it;

    for (it = params.constBegin(); it != params.constEnd(); it++) {
        urlQuery.addQueryItem(it.key(), it.value().toString());
    }

    // Build the resource query
    if (accessToken_.isEmpty()) {
        urlQuery.addQueryItem("client_id", client_->clientId());
    }
    else {
        urlQuery.addQueryItem("oauth_token", accessToken_);
    }

    // Set the resource path
    requestUrl.setPath(path);
    // Set the query
    requestUrl.setQuery(urlQuery);

    return requestUrl;
}

QUrl Connection::buildRequestUrl(const QString& path)
{
    QUrl requestUrl(SERVICE_URL);
    QUrlQuery urlQuery;

    // Build the resource query
    if (accessToken_.isEmpty()) {
        urlQuery.addQueryItem("client_id", client_->clientId());
    }
    else {
        urlQuery.addQueryItem("oauth_token", accessToken_);
    }

    // Set the resource path
    requestUrl.setPath(path);
    // Set the query
    requestUrl.setQuery(urlQuery);

    return requestUrl;
}

} // namespace Soundcloud
