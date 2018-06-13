/*
 * SHAB Server
 * Copyright (C) 2018  Luca Cireddu <sardylan@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 */


#include "client.hpp"

using namespace org::thehellnet::shab;

ShabClient::ShabClient(QTcpSocket *socket) : QObject() {
    this->socket = socket;
}

ShabClient::~ShabClient() {
    if (socket != nullptr)
        socket->deleteLater();
}

void ShabClient::start() {
    connect(socket, &QAbstractSocket::disconnected, this, &ShabClient::handleSocketDisconnection);
    connect(socket, &QIODevice::readyRead, this, &ShabClient::handleSocketReadyRead);
}

void ShabClient::stop() {
    if (socket != nullptr) {
        if (socket->isOpen())
            socket->close();

        socket->deleteLater();
    }
}

void ShabClient::send(QByteArray rawData) {
    if (socket == nullptr || !socket->isOpen())
        return;

    socket->write(rawData);
}

void ShabClient::handleSocketDisconnection() {
    emit disconnected();
}

void ShabClient::handleSocketReadyRead() {
    QByteArray rawData = socket->readAll();

    emit newRawData(rawData);
}
