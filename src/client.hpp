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

#ifndef __SHAB_SERVER_CLIENT_H
#define __SHAB_SERVER_CLIENT_H

#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtNetwork/QTcpSocket>

namespace org::thehellnet::shab {

    class ShabClient : public QObject {
    Q_OBJECT

    public:
        explicit ShabClient(QTcpSocket *socket);

        ~ShabClient() override;

    public slots:

        void start();

        void stop();

        void send(QByteArray rawData);

    private:
        QTcpSocket *socket;

    private slots:

        void handleSocketDisconnection();

        void handleSocketReadyRead();

    signals:

        void disconnected();

        void newRawLine(QString data);
    };

};

#endif
