include_directories(.)

find_package(Qt5 REQUIRED COMPONENTS
        Core)

set(LIBSHAB_PROTOCOL
        protocol/line.cpp
        protocol/line.hpp)

set(LIBSHAB_PARSER
        parser/line.cpp
        parser/line.hpp
        parser/exception.cpp
        parser/exception.hpp)

add_library(shab STATIC
        ${LIBSHAB_PROTOCOL}
        ${LIBSHAB_PARSER})

target_link_libraries(shab
        Qt5::Core)
