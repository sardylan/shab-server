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


#include "line.hpp"
#include "exception.hpp"

using namespace org::thehellnet::shab::parser;

ShabLine LineParser::parse(const QByteArray &rawData) {
    QString data = parseString(QString(rawData));
    QStringList items = data.split(LIBSHAB_LINE_SEPARATOR);

    if (items.count() != LIBSHAB_LINE_ELEMENTS)
        throw LineParserException();

    ShabLine line;

    QString &checksumString = items[LIBSHAB_LINE_POSITION_CHECKSUM];
    if (checksumString.length() != 4)
        throw LineParserException();

    line.setChecksum(parseChecksum(checksumString));
    line.setIdent(parseString(items[LIBSHAB_LINE_POSITION_IDENT]));
    line.setLatitude(parseDouble(items[LIBSHAB_LINE_POSITION_LATITUDE]));
    line.setLongitude(parseDouble(items[LIBSHAB_LINE_POSITION_LONGITUDE]));
    line.setAltitude(parseDouble(items[LIBSHAB_LINE_POSITION_ALTITUDE]));
    line.setSpeed(parseDouble(items[LIBSHAB_LINE_POSITION_SPEED]));
    line.setAngle(parseDouble(items[LIBSHAB_LINE_POSITION_ANGLE]));

    return line;
}

QByteArray LineParser::serialize(const ShabLine &line) {
    return QByteArray();
}

quint16 LineParser::parseChecksum(const QString &item) {
    return static_cast<quint16>(item.toInt(nullptr, 16));
}

double LineParser::parseDouble(const QString &item) {
    return item.toDouble();
}

QString LineParser::parseString(const QString &item) {
    return QString(item).remove(QRegExp(R"([\n\t\r])")).trimmed();
}
