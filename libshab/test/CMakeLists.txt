include_directories(../src)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Test)

add_executable(test_parser_line
        parser/testline.cpp
        parser/testline.hpp)

target_link_libraries(test_parser_line
        Qt5::Core
        Qt5::Test
        shab)

add_test(ParserLineTest
        test_parser_line)
