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
