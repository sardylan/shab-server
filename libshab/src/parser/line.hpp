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

#ifndef __LIBSHAB_PARSER_LINE_H
#define __LIBSHAB_PARSER_LINE_H

#include <QtCore/QByteArray>

#include <protocol/line.hpp>

using namespace org::thehellnet::shab::protocol;

namespace org::thehellnet::shab::parser {

    class LineParser {

    public:
        static ShabLine parse(const QByteArray &rawData);

        static QByteArray serialize(const ShabLine &line);

    private:
        static quint16 parseChecksum(const QString &item);

        static double parseDouble(const QString &item);

        static QString parseString(const QString &item);
    };
}

#endif
