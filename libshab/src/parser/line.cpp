/*
 * libshab
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


#include <QtCore/QtMath>

#include "line.hpp"
#include "exception.hpp"

using namespace org::thehellnet::shab::parser;

ShabLine LineParser::parse(const QString &data) {
    QStringList items = data.split(LIBSHAB_LINE_SEPARATOR);

    if (items.count() != LIBSHAB_LINE_ELEMENTS)
        throw LineParserException();

    ShabLine line;

    QString &checksumString = items[LIBSHAB_LINE_POSITION_CHECKSUM];
    if (checksumString.length() != 4)
        throw LineParserException();

    quint16 checksum = parseChecksum(checksumString);
    QString checkRawData = data.mid(5, data.length());

    quint16 computedChecksum = checksum16(checkRawData);
    if (computedChecksum != checksum)
        throw LineParserException();

    line.setChecksum(checksum);

    QString &identString = items[LIBSHAB_LINE_POSITION_IDENT];
    if (identString.length() == 0)
        throw LineParserException();
    line.setIdent(parseString(identString));

    QString &latitudeString = items[LIBSHAB_LINE_POSITION_LATITUDE];
    if (latitudeString.length() < 7)
        throw LineParserException();
    line.setLatitude(parseDouble(latitudeString, 6));

    QString &longitudeString = items[LIBSHAB_LINE_POSITION_LONGITUDE];
    if (longitudeString.length() < 7)
        throw LineParserException();
    line.setLongitude(parseDouble(longitudeString, 6));

    QString &altitudeString = items[LIBSHAB_LINE_POSITION_ALTITUDE];
    if (altitudeString.length() == 0)
        throw LineParserException();
    line.setAltitude(parseDouble(altitudeString, 1));

    QString &speedString = items[LIBSHAB_LINE_POSITION_SPEED];
    if (speedString.length() == 0)
        throw LineParserException();
    line.setSpeed(parseDouble(speedString, 1));

    QString &angleSpeed = items[LIBSHAB_LINE_POSITION_ANGLE];
    if (angleSpeed.length() == 0)
        throw LineParserException();
    line.setAngle(parseDouble(angleSpeed, 1));

    return line;
}

ShabLine LineParser::parse(const QByteArray &rawData) {
    QString data = parseString(QString(rawData));
    return LineParser::parse(data);
}

QByteArray LineParser::serialize(const ShabLine &line) {
    return QByteArray();
}

quint16 LineParser::checksum16(const QString &item) {
    quint16 checksum = 0;

    const std::string &itemStr = item.toStdString();
    for (char c: itemStr) {
        checksum += c;
        checksum %= 0xFFFF + 1;
    }

    return checksum;
}

quint16 LineParser::parseChecksum(const QString &item) {
    return static_cast<quint16>(item.toInt(nullptr, 16));
}

double LineParser::parseDouble(const QString &item, int decimals) {
    if (item.length() == 0)
        return 0;

    double value = item.toDouble();

    if (decimals > 0)
        value /= qPow(10, decimals);

    return value;
}

QString LineParser::parseString(const QString &item) {
    return QString(item).remove(QRegExp(R"([\n\t\r])")).trimmed();
}
