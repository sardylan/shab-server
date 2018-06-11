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

#include <QtCore/QTextStream>
#include <QtNetwork/QTcpSocket>

#include "server.hpp"
#include "version.hpp"

using namespace org::thehellnet::shab;

int main(int argc, char **argv) {
    QCoreApplication::setApplicationName(SHAB_SERVER_APPLICATION_NAME);
    QCoreApplication::setApplicationVersion(SHAB_SERVER_APPLICATION_VERSION);
    QCoreApplication::setOrganizationName(SHAB_SERVER_ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(SHAB_SERVER_ORGANIZATION_DOMAIN);

    ShabServer shabServer(argc, argv);
    shabServer.run();
    return shabServer.exec();
}

ShabServer::ShabServer(int &argc, char **argv) : QCoreApplication(argc, argv) {
    serverSocket = new QTcpServer(this);
}

ShabServer::~ShabServer() = default;

void ShabServer::run() {
    printHeader();
    prepareSocket();

//    QMetaObject::invokeMethod(this, "quit", Qt::QueuedConnection);
}

void ShabServer::prepareSocket() {
    connect(serverSocket, &QTcpServer::newConnection, this, &ShabServer::handleNewServerConnection);
}

void ShabServer::printHeader() {
    QTextStream stdErr(stderr);
    stdErr << applicationName() << " " << applicationVersion() << endl;
    stdErr << "Running with PID " << applicationPid() << endl;
}

void ShabServer::handleNewServerConnection() {
    QTcpSocket *socket = serverSocket->nextPendingConnection();
}
