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

#ifndef __SHAB_SERVER_SERVER_H
#define __SHAB_SERVER_SERVER_H

#include <QtCore/QCoreApplication>
#include <QtCore/QHash>
#include <QtCore/QThread>
#include <QtNetwork/QTcpServer>

#include "client.hpp"

namespace org::thehellnet::shab {

    class ShabServer : public QCoreApplication {
    Q_OBJECT

    public:

        explicit ShabServer(int &argc, char **argv);

        ~ShabServer() override;

        void run();

    private:
        QTcpServer *serverSocket;
        quint64 nextId;
        QHash<quint64, QThread *> threads;
        QHash<quint64, ShabClient *> clients;

        void prepareSocket();

        void printHeader();

    private slots:

        void handleNewServerConnection();

    };
};

#endif
