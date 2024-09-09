cmake_minimum_required(VERSION 3.28)
project(security_system_back_end)

set(CMAKE_CXX_STANDARD 26)

add_executable(security_system_back_end src/main.cpp
        src/ReaderJSON/ReaderJSON.cpp
        src/Server/ServerTCP.cpp
        src/Server/Logger.cpp
        src/LicenseInfo/LicenseInfo.cpp
        include/LicenseInfo/LicenseInfo.h
        include/Server/Logger.h
        include/Server/ServerTCP.h
        include/ReaderJSON/ReaderJSON.h
)

find_package(Boost REQUIRED COMPONENTS log log_setup)

target_include_directories(security_system_back_end PRIVATE ${PROJECT_SOURCE_DIR}/src/Server
        PRIVATE ${PROJECT_SOURCE_DIR}/src/ReaderJSON
        PRIVATE ${PROJECT_SOURCE_DIR}/src/LicenseInfo
        PRIVATE ${PROJECT_SOURCE_DIR}/include/Server
        PRIVATE ${PROJECT_SOURCE_DIR}/include/ReaderJSON
        PRIVATE ${PROJECT_SOURCE_DIR}/include/LicenseInfo
)
target_link_libraries(security_system_back_end PRIVATE ${Boost_LIBRARIES})

install(TARGETS security_system_back_end DESTINATION bin)
