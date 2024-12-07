cmake_minimum_required(VERSION 3.28)
project(esp32_security_system_server)

set(CMAKE_CXX_STANDARD 26)

set(PROJECT_FILES
        src/ReaderJSON.cpp
        src/ServerTCP.cpp
        src/Logger.cpp
        src/LicenseInfo.cpp
        src/MessageHandler.cpp
        include/LicenseInfo.h
        include/Logger.h
        include/ServerTCP.h
        include/ReaderJSON.h
        include/MessageHandler.h
        src/main.cpp
)

set(PROJECT_DIRS
        PRIVATE ${PROJECT_SOURCE_DIR}/src
        PRIVATE ${PROJECT_SOURCE_DIR}/include
)

add_executable(esp32_security_system_server ${PROJECT_FILES})

target_include_directories(esp32_security_system_server ${PROJECT_DIRS})

find_package(Boost REQUIRED COMPONENTS log
        log_setup
)
target_link_libraries(esp32_security_system_server PRIVATE ${Boost_LIBRARIES})

install(TARGETS esp32_security_system_server DESTINATION bin)
