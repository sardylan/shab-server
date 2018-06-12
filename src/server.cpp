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

    nextId = 0;
}

ShabServer::~ShabServer() = default;

void ShabServer::run() {
    printHeader();
    prepareSocket();

//    QMetaObject::invokeMethod(this, "quit", Qt::QueuedConnection);
}

void ShabServer::prepareSocket() {
    connect(serverSocket, &QTcpServer::newConnection, this, &ShabServer::handleNewServerConnection);

    serverSocket->listen(QHostAddress::Any, 12345);
}

void ShabServer::printHeader() {
    QTextStream stdErr(stderr);
    stdErr << applicationName() << " " << applicationVersion() << endl;
    stdErr << "Running with PID " << applicationPid() << endl;
}

void ShabServer::handleNewServerConnection() {
    QTextStream stdErr(stderr);

    quint64 id = nextId;
    nextId++;

    stdErr << "New connection - ID " << id << endl;

    QTcpSocket *socket = serverSocket->nextPendingConnection();

    auto *newClient = new ShabClient(socket);

    auto *newThread = new QThread();
    newClient->moveToThread(newThread);
    newThread->start();

    connect(newClient, &ShabClient::disconnected, [=]() {
        clientDisonnection(id);
    });

    connect(newClient, &ShabClient::newRawData, [=](QString rawData) {
        QTextStream stdOut(stdout);
        stdOut << rawData;
    });

    clients.insert(id, newClient);
    threads.insert(id, newThread);
}

void ShabServer::clientDisonnection(quint64 id) {
    QTextStream stdErr(stderr);

    ShabClient *client = clients.take(id);
    QThread *thread = threads.take(id);

    client->quit();
    client->deleteLater();

    thread->quit();
    thread->deleteLater();

    stdErr << "Connection " << id << " closed." << endl;
}