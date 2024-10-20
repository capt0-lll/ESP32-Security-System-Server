cmake_minimum_required(VERSION 3.28)
project(esp32_security_system_server)
project(test)

set(CMAKE_CXX_STANDARD 26)

set(PROJECT_FILES
        src/ReaderJSON/ReaderJSON.cpp
        src/Server/ServerTCP.cpp
        src/Server/Logger.cpp
        src/LicenseInfo/LicenseInfo.cpp
        include/LicenseInfo/LicenseInfo.h
        include/Server/Logger.h
        include/Server/ServerTCP.h
        include/ReaderJSON/ReaderJSON.h
        src/Server/MessageHandler/MessageHandler.h
        src/Server/MessageHandler/MessageHandler.cpp
)

set(PROJECT_DIRS
        PRIVATE ${PROJECT_SOURCE_DIR}/src/Server
        PRIVATE ${PROJECT_SOURCE_DIR}/src/ReaderJSON
        PRIVATE ${PROJECT_SOURCE_DIR}/src/LicenseInfo
        PRIVATE ${PROJECT_SOURCE_DIR}/include/Server
        PRIVATE ${PROJECT_SOURCE_DIR}/include/ReaderJSON
        PRIVATE ${PROJECT_SOURCE_DIR}/include/LicenseInfo
)

add_executable(esp32_security_system_server src/main.cpp
        ${PROJECT_FILES}
)

target_include_directories(esp32_security_system_server ${PROJECT_DIRS})

add_executable(test tests/test.cpp
        ${PROJECT_FILES}
)

target_include_directories(test ${PROJECT_DIRS})



find_package(Boost REQUIRED COMPONENTS log
        log_setup
        unit_test_framework
)
target_link_libraries(esp32_security_system_server PRIVATE ${Boost_LIBRARIES})
target_link_libraries(test PRIVATE ${Boost_LIBRARIES})

install(TARGETS esp32_security_system_server DESTINATION bin)
