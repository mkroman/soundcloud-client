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

#include <QNetworkReply>
#include <QJsonDocument>

#include "Request.h"
#include "Response.h"

namespace Soundcloud {

Request::Request(QObject* parent) :
    QObject(parent)
{
}

Request::Request(const QString& endpoint, QObject* parent) :
    QObject(parent),
    endpoint_(endpoint)
{

}

Request::Request(const QString& endpoint, QVariantMap& params, QObject* parent) :
    QObject(parent),
    endpoint_(endpoint),
    params_(params)
{
}

void Request::finished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    // Get the response code
    int responseCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if (responseCode == 401) {
        // The access token has expired or is invalid
    }
    else {
        Response* requestResponse = new Response();

        // Parse the response body
        QJsonParseError parseError;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &parseError);

        if (parseError.error == QJsonParseError::NoError) {
            Q_ASSERT(jsonDocument.isObject());

            requestResponse->setBody(jsonDocument.object());

            emit response(requestResponse);
        }
        else {
            qDebug() << Q_FUNC_INFO << "Failed in parsing the response!";
        }

    }

    qDebug() << reply->readAll();
    qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    deleteLater();
    reply->deleteLater();
}

} // namespace Soundcloud
