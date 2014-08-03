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

#include "User.h"
#include "Client.h"
#include "Request.h"
#include "Response.h"
#include "Connection.h"

namespace Soundcloud {

Client::Client(QObject* parent) :
    QObject(parent)
{
    connection_ = new Connection(this);
}

Client::Client(QString& clientId, QObject* parent) :
    QObject(parent),
    clientId_(clientId)
{
    connection_ = new Connection(this);
}

Client::~Client()
{
    delete connection_;
}

void Client::updateUserProfile()
{
    Response* response = connection_->get("/me.json");

    connect(response, SIGNAL(finished()), SLOT(onUserProfile()));
}

void Client::searchTrack(const QString &query)
{
    Response* response;
    QVariantMap params;

    params["q"] = query;
    response = connection_->get("/tracks.json", params);

    connect(response, &Response::finished, this, &Client::onTrackSearchCompleted);
}

void Client::setAccessToken(const QString& accessToken)
{
    connection_->setAccessToken(accessToken);
}

void Client::onUserProfile()
{
    Response* response = qobject_cast<Response*>(sender());
    QJsonObject object = response->body().object();

    User user = User::fromJson(object);

    qDebug() << "Received user profile. I'm" << user.name();

    me_ = user;

    emit userProfileUpdated();

    // Always remember to free the response
    response->deleteLater();
}

void Client::onTrackSearchCompleted()
{
    Response* response = qobject_cast<Response*>(sender());

    if (!response->body().isArray()) {
        qWarning() << Q_FUNC_INFO << "Expected response to be an array!";

        return;
    }

    QJsonArray array = response->body().array();

    qDebug() << "Track search:" << response->body();

    response->deleteLater();
}

} // namespace Soundcloud
