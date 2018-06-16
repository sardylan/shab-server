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


#include "testline.hpp"

#include <parser/line.hpp>
#include <parser/exception.hpp>

using namespace org::thehellnet::shab::protocol;
using namespace org::thehellnet::shab::parser;

QTEST_MAIN(LineParserTest)

void LineParserTest::emptyInput() {
    input = "";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::emptyItems() {
    input = "||||||";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongChecksumLength() {
    input = "4D2|shab|-39445419|-9541433|-10|0|0";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongLatitudeLength() {
    input = "04D2|shab|445419|-9541433|-10|0|0";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongLongitudeLength() {
    input = "04D2|shab|39445419|541433|-10|0|0";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongAltitudeLength() {
    input = "04D2|shab|39445419|9541433||0|0";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongSpeedLength() {
    input = "04D2|shab|39445419|9541433|110||0";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::wrongAngleLength() {
    input = "04D2|shab|39445419|9541433|110|0|";

    QVERIFY_EXCEPTION_THROWN(LineParser::parse(input), LineParserException);
}

void LineParserTest::normalLine() {
    input = "04D2|shab|39445419|9541433|110|0|0";

    expected.setChecksum(0x04d2);
    expected.setIdent("shab");
    expected.setLatitude(39.445419);
    expected.setLongitude(9.541433);
    expected.setAltitude(11.0);
    expected.setSpeed(0.0);
    expected.setAngle(0.0);

    actual = LineParser::parse(input);

    QCOMPARE(actual, expected);
}

void LineParserTest::negativeValues() {
    input = "04D2|shab|-39445419|-9541433|-10|0|0";

    expected.setChecksum(0x04d2);
    expected.setIdent("shab");
    expected.setLatitude(-39.445419);
    expected.setLongitude(-9.541433);
    expected.setAltitude(-1.0);
    expected.setSpeed(0.0);
    expected.setAngle(0.0);

    actual = LineParser::parse(input);

    QCOMPARE(actual, expected);
}
