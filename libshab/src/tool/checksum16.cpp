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

#include <QtCore/QString>

#include <parser/line.hpp>
#include <iostream>

using namespace org::thehellnet::shab::parser;

void computeChecksum(char *rawString);

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++)
        computeChecksum(argv[i]);

    return 0;
}

void computeChecksum(char *rawString) {
    QString string(rawString);
    quint16 checksum = LineParser::checksum16(string);
    QString checksumString = LineParser::serializeChecksum(checksum);
    std::cout << checksumString.toStdString() << " - " << rawString << std::endl;
}