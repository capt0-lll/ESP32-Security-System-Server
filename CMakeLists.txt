cmake_minimum_required(VERSION 3.28)
project(security_system_back_end)

set(CMAKE_CXX_STANDARD 26)

add_executable(security_system_back_end src/main.cpp src/json_reader/json_reader.cpp
        src/server/tcp_server.cpp
)

find_package(Boost REQUIRED COMPONENTS log log_setup)

target_include_directories(security_system_back_end PRIVATE ${PROJECT_SOURCE_DIR}/src/server
        PRIVATE ${PROJECT_SOURCE_DIR}/src/json_reader PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(security_system_back_end PRIVATE ${Boost_LIBRARIES})

install(TARGETS security_system_back_end DESTINATION bin)
