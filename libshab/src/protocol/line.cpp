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


#include <QtCore/QtCore>

#include "line.hpp"

using namespace org::thehellnet::shab::protocol;

ShabLine::ShabLine() {
    checksum = 0;
    ident = "";
    latitude = 0;
    longitude = 0;
    altitude = 0;
    speed = 0;
    angle = 0;
    extended = false;
    intTemp = 0;
    outTemp = 0;
    outPressure = 0;
    sliceTotal = 0;
    sliceNum = 0;
    data.clear();
}

quint16 ShabLine::getChecksum() const {
    return checksum;
}

void ShabLine::setChecksum(quint16 checksum) {
    ShabLine::checksum = checksum;
}

const QString &ShabLine::getIdent() const {
    return ident;
}

void ShabLine::setIdent(const QString &ident) {
    ShabLine::ident = ident;
}

double ShabLine::getLatitude() const {
    return latitude;
}

void ShabLine::setLatitude(double latitude) {
    ShabLine::latitude = latitude;
}

double ShabLine::getLongitude() const {
    return longitude;
}

void ShabLine::setLongitude(double longitude) {
    ShabLine::longitude = longitude;
}

double ShabLine::getAltitude() const {
    return altitude;
}

void ShabLine::setAltitude(double altitude) {
    ShabLine::altitude = altitude;
}

double ShabLine::getSpeed() const {
    return speed;
}

void ShabLine::setSpeed(double speed) {
    ShabLine::speed = speed;
}

double ShabLine::getAngle() const {
    return angle;
}

void ShabLine::setAngle(double angle) {
    ShabLine::angle = angle;
}

bool ShabLine::isExtended() const {
    return extended;
}

void ShabLine::setExtended(bool extended) {
    ShabLine::extended = extended;
}

float ShabLine::getIntTemp() const {
    return intTemp;
}

void ShabLine::setIntTemp(float intTemp) {
    ShabLine::intTemp = intTemp;
}

float ShabLine::getOutTemp() const {
    return outTemp;
}

void ShabLine::setOutTemp(float outTemp) {
    ShabLine::outTemp = outTemp;
}

int ShabLine::getOutPressure() const {
    return outPressure;
}

void ShabLine::setOutPressure(int outPressure) {
    ShabLine::outPressure = outPressure;
}

int ShabLine::getSliceTotal() const {
    return sliceTotal;
}

void ShabLine::setSliceTotal(int sliceTotal) {
    ShabLine::sliceTotal = sliceTotal;
}

int ShabLine::getSliceNum() const {
    return sliceNum;
}

void ShabLine::setSliceNum(int sliceNum) {
    ShabLine::sliceNum = sliceNum;
}

const QByteArray &ShabLine::getData() const {
    return data;
}

void ShabLine::setData(const QByteArray &data) {
    ShabLine::data = data;
}

bool ShabLine::operator==(const ShabLine &rhs) const {
    if (extended != rhs.extended)
        return false;

    if (checksum != rhs.checksum
        || ident != rhs.ident
        || latitude != rhs.latitude
        || longitude != rhs.longitude
        || altitude != rhs.altitude
        || speed != rhs.speed
        || angle != rhs.angle)
        return false;

    if (extended) {
        if (intTemp != rhs.intTemp
            || outTemp != rhs.outTemp
            || outPressure != rhs.outPressure
            || sliceTotal != rhs.sliceTotal
            || sliceNum != rhs.sliceNum
            || data != rhs.data)
            return false;
    }

    return true;
}

bool ShabLine::operator!=(const ShabLine &rhs) const {
    return !(rhs == *this);
}
