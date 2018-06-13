configure_file(version.hpp.in version.hpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Network)

set(SHAB_SERVER_SOURCES
        server.cpp
        client.cpp)

set(SHAB_SERVER_HEADERS
        server.hpp
        version.hpp
        client.cpp)

add_executable(shab-server
        ${SHAB_SERVER_SOURCES}
        ${SHAB_SERVER_HEADERS})

target_link_libraries(shab-server
        shab
        Qt5::Core
        Qt5::Network)
