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



#ifndef __LIBSHAB_PROTOCOL_TESTLINE_H
#define __LIBSHAB_PROTOCOL_TESTLINE_H

#include <QtCore/QObject>
#include <QtTest>

#include <protocol/line.hpp>

namespace org::thehellnet::shab::protocol {

    class LineParserTest : public QObject {
    Q_OBJECT

    private slots:

        void emptyInput();

        void emptyItems();

        void wrongChecksumLength();

        void wrongLatitudeLength();

        void wrongLongitudeLength();

        void wrongAltitudeLength();

        void wrongSpeedLength();

        void wrongAngleLength();

        void wrongLine();

        void wrongLineExtended();

        void normalLine();

        void negativeValues();

        void extendedLine();

        void serializeNormalLine();

        void serializeExtendedLine();

        void checksumEmpty();
    };

}
#endif
