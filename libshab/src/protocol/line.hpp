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

#ifndef __LIBSHAB_PROTOCOL_LINE_H
#define __LIBSHAB_PROTOCOL_LINE_H

#include <QtCore/QString>
#include <QtCore/QByteArray>

#define LIBSHAB_LINE_ELEMENTS 7
#define LIBSHAB_LINE_ELEMENTS_EXTENDED 13

#define LIBSHAB_LINE_POSITION_CHECKSUM 0
#define LIBSHAB_LINE_POSITION_IDENT 1
#define LIBSHAB_LINE_POSITION_LATITUDE 2
#define LIBSHAB_LINE_POSITION_LONGITUDE 3
#define LIBSHAB_LINE_POSITION_ALTITUDE 4
#define LIBSHAB_LINE_POSITION_SPEED 5
#define LIBSHAB_LINE_POSITION_ANGLE 6
#define LIBSHAB_LINE_POSITION_INT_TEMP 7
#define LIBSHAB_LINE_POSITION_OUT_TEMP 8
#define LIBSHAB_LINE_POSITION_OUT_PRESSURE 9
#define LIBSHAB_LINE_POSITION_SLICE_TOTAL 10
#define LIBSHAB_LINE_POSITION_SLICE_NUM 11
#define LIBSHAB_LINE_POSITION_DATA 12

#define LIBSHAB_LINE_SEPARATOR '|'

namespace org::thehellnet::shab::protocol {

    class ShabLine {

    public:
        ShabLine();

        quint16 getChecksum() const;

        void setChecksum(quint16 checksum);

        const QString &getIdent() const;

        void setIdent(const QString &ident);

        double getLatitude() const;

        void setLatitude(double latitude);

        double getLongitude() const;

        void setLongitude(double longitude);

        double getAltitude() const;

        void setAltitude(double altitude);

        double getSpeed() const;

        void setSpeed(double speed);

        double getAngle() const;

        void setAngle(double angle);

        bool isExtended() const;

        void setExtended(bool extended);

        float getIntTemp() const;

        void setIntTemp(float intTemp);

        float getOutTemp() const;

        void setOutTemp(float outTemp);

        int getOutPressure() const;

        void setOutPressure(int outPressure);

        int getSliceTotal() const;

        void setSliceTotal(int sliceTotal);

        int getSliceNum() const;

        void setSliceNum(int sliceNum);

        const QByteArray &getData() const;

        void setData(const QByteArray &data);

        bool operator==(const ShabLine &rhs) const;

        bool operator!=(const ShabLine &rhs) const;

    private:
        quint16 checksum;
        QString ident;
        double latitude;
        double longitude;
        double altitude;
        double speed;
        double angle;
        bool extended;
        float intTemp;
        float outTemp;
        int outPressure;
        int sliceTotal;
        int sliceNum;
        QByteArray data;
    };
}

#endif
