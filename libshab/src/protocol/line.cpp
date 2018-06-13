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

using namespace org::thehellnet::shab::protocol;

ShabLine::ShabLine() {
    checksum = 0;
    ident = "";
    latitude = 0;
    longitude = 0;
    altitude = 0;
    speed = 0;
    angle = 0;
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
