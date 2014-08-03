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

Client::~Client()
{
    delete connection_;
}

void Client::requestPersona()
{
    Request* personaRequest = new Request("/me.json", this);

    connection_->sendRequest(personaRequest);

    connect(personaRequest, SIGNAL(response(Response*)), SLOT(updatePersona(Response*)));
}

void Client::setAccessToken(const QString& accessToken)
{
    connection_->setAccessToken(accessToken);
}

void Client::updatePersona(Response* response)
{
    User persona = User::fromJson(response->body());

    qDebug() << "Received persona" << persona.name();

    me_ = persona;

    response->deleteLater();
}

} // namespace Soundcloud
