[1mdiff --git a/CMakeLists.txt b/CMakeLists.txt[m
[1mindex 3ec7421..87997ea 100644[m
[1m--- a/CMakeLists.txt[m
[1m+++ b/CMakeLists.txt[m
[36m@@ -5,12 +5,15 @@[m [mset(CMAKE_CXX_STANDARD 26)[m
 [m
 add_executable(security_system_back_end src/main.cpp src/json_reader/json_reader.cpp[m
         src/server/tcp_server.cpp[m
[32m+[m[32m        src/server/Logger.cpp[m
[32m+[m[32m        src/licenseInfo/licenseInfo.h[m
[32m+[m[32m        src/licenseInfo/licenseInfo.cpp[m
 )[m
 [m
 find_package(Boost REQUIRED COMPONENTS log log_setup)[m
 [m
 target_include_directories(security_system_back_end PRIVATE ${PROJECT_SOURCE_DIR}/src/server[m
[31m-        PRIVATE ${PROJECT_SOURCE_DIR}/src/json_reader PRIVATE ${Boost_INCLUDE_DIRS})[m
[32m+[m[32m        PRIVATE ${PROJECT_SOURCE_DIR}/src/json_reader PRIVATE ${PROJECT_SOURCE_DIR}/src/licenseInfo )[m
 target_link_libraries(security_system_back_end PRIVATE ${Boost_LIBRARIES})[m
 [m
 install(TARGETS security_system_back_end DESTINATION bin)[m
[1mdiff --git a/src/licenseInfo/licenseInfo.cpp b/src/licenseInfo/licenseInfo.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..a4f2f22[m
[1m--- /dev/null[m
[1m+++ b/src/licenseInfo/licenseInfo.cpp[m
[36m@@ -0,0 +1,47 @@[m
[32m+[m[32m//[m
[32m+[m[32m// Created by eldar on 08.09.24.[m
[32m+[m[32m//[m
[32m+[m
[32m+[m[32m#include "licenseInfo.h"[m
[32m+[m
[32m+[m[32mlicenseInfo::licenseInfo() {[m
[32m+[m[32m    showLicenseOnStart();[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid licenseInfo::runReadingInput() {[m
[32m+[m[32m    while(true) {[m
[32m+[m[32m        string input;[m
[32m+[m[32m        getline(cin, input);[m
[32m+[m[32m        if(input == "show c") showLicense();[m
[32m+[m[32m        else if(input == "show w") showWarranty();[m
[32m+[m[32m    }[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid licenseInfo::showLicense() {[m
[32m+[m[32m    std::cout << "This program is free software: you can redistribute it and/or modify" << std::endl;[m
[32m+[m[32m    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;[m
[32m+[m[32m    std::cout << "the Free Software Foundation, either version 3 of the License, or" << std::endl;[m
[32m+[m[32m    std::cout << "(at your option) any later version.\n" << std::endl;[m
[32m+[m[32m    std::cout << "This program is distributed in the hope that it will be useful," << std::endl;[m
[32m+[m[32m    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;[m
[32m+[m[32m    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the" << std::endl;[m
[32m+[m[32m    std::cout << "GNU General Public License for more details." << std::endl;[m
[32m+[m[32m    std::cout << "You should have received a copy of the GNU General Public License" << std::endl;[m
[32m+[m[32m    std::cout << "along with this program. If not, see <https://www.gnu.org/licenses/>." << std::endl;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid licenseInfo::showWarranty() {[m
[32m+[m[32m    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;[m
[32m+[m[32m    std::cout << "This is free software; you can redistribute it and/or modify" << std::endl;[m
[32m+[m[32m    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;[m
[32m+[m[32m    std::cout << "the Free Software Foundation. See the GNU General Public License for more details." << std::endl;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m
[32m+[m[32mvoid licenseInfo::showLicenseOnStart() {[m
[32m+[m[32m    std::cout << "ESP32 Security System Server Copyright (C) 2024 Eldar Vanin" << std::endl;[m
[32m+[m[32m    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;[m
[32m+[m[32m    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;[m
[32m+[m[32m    std::cout << "under certain conditions; type `show c` for details.\n" << std::endl;[m
[32m+[m[32m}[m
[32m+[m
[1mdiff --git a/src/licenseInfo/licenseInfo.h b/src/licenseInfo/licenseInfo.h[m
[1mnew file mode 100644[m
[1mindex 0000000..19ee98b[m
[1m--- /dev/null[m
[1m+++ b/src/licenseInfo/licenseInfo.h[m
[36m@@ -0,0 +1,26 @@[m
[32m+[m[32m//[m
[32m+[m[32m// Created by eldar on 08.09.24.[m
[32m+[m[32m//[m
[32m+[m
[32m+[m[32m#ifndef LICENSEINFO_H[m
[32m+[m[32m#define LICENSEINFO_H[m
[32m+[m
[32m+[m[32m#include <iostream>[m
[32m+[m[32m#include <thread>[m
[32m+[m
[32m+[m[32musing namespace std;[m
[32m+[m
[32m+[m[32mclass licenseInfo {[m
[32m+[m[32mpublic:[m
[32m+[m[32m    licenseInfo();[m
[32m+[m[32m    static void runReadingInput();[m
[32m+[m[32mprivate:[m
[32m+[m[32m    static void showLicense();[m
[32m+[m[32m    static void showWarranty();[m
[32m+[m[32m    static void showLicenseOnStart();[m
[32m+[m
[32m+[m[32m};[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m[32m#endif //LICENSEINFO_H[m
[1mdiff --git a/src/main.cpp b/src/main.cpp[m
[1mindex 432c57c..28ca8ea 100644[m
[1m--- a/src/main.cpp[m
[1m+++ b/src/main.cpp[m
[36m@@ -17,75 +17,41 @@[m
 [m
 #include <tcp_server.h>[m
 #include <json_reader.h>[m
[32m+[m
[32m+[m
 #include <boost/asio.hpp>[m
 #include <thread>[m
 #include <iostream>[m
[31m-#include <string.h>[m
[32m+[m
 [m
 using namespace std;[m
 [m
 unsigned short port;[m
 string ip;[m
 [m
[31m-void show_license_info();[m
[31m-[[noreturn]] void handle_input();[m
[31m-void show_warranty();[m
[31m-void show_license();[m
 [m
 int main() {[m
 [m
[31m-    show_license_info();[m
[31m-    thread handle_input_thread(handle_input);[m
[31m-[m
[31m-[m
     json_reader::read(ip,port);[m
     try {[m
[32m+[m
[32m+[m
[32m+[m
         boost::asio::io_context io_context;[m
[31m-        tcp_server server(io_context, ip, port);[m
 [m
 [m
[32m+[m[32m        thread showLicense(licenseInfo{}.runReadingInput);[m
[32m+[m
[32m+[m[32m        tcp_server server(io_context, ip, port);[m
         thread server_run([&io_context]() {[m
             io_context.run();[m
         });[m
[31m-        handle_input_thread.join();[m
[32m+[m
[32m+[m[32m        showLicense.join();[m
         server_run.join();[m
[32m+[m
     } catch (exception &exception) {[m
         cerr << "Error: " << exception.what() << endl;[m
     }[m
 [m
[31m-}[m
[31m-void show_license_info() {[m
[31m-    std::cout << "ESP32 Security System Server Copyright (C) 2024 Eldar Vanin" << std::endl;[m
[31m-    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;[m
[31m-    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;[m
[31m-    std::cout << "under certain conditions; type `show c` for details.\n" << std::endl;[m
[31m-}[m
[31m-[m
[31m-[[noreturn]] void handle_input() {[m
[31m-    while(true) {[m
[31m-        string input;[m
[31m-        getline(cin, input);[m
[31m-        if(input == "show c") show_license();[m
[31m-        else if(input == "show w") show_warranty();[m
[31m-    }[m
[31m-}[m
[31m-[m
[31m-void show_warranty() {[m
[31m-    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;[m
[31m-    std::cout << "This is free software; you can redistribute it and/or modify" << std::endl;[m
[31m-    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;[m
[31m-    std::cout << "the Free Software Foundation. See the GNU General Public License for more details." << std::endl;[m
[31m-}[m
[31m-[m
[31m-void show_license() {[m
[31m-    std::cout << "This program is free software: you can redistribute it and/or modify" << std::endl;[m
[31m-    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;[m
[31m-    std::cout << "the Free Software Foundation, either version 3 of the License, or" << std::endl;[m
[31m-    std::cout << "(at your option) any later version.\n" << std::endl;[m
[31m-    std::cout << "This program is distributed in the hope that it will be useful," << std::endl;[m
[31m-    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;[m
[31m-    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the" << std::endl;[m
[31m-    std::cout << "GNU General Public License for more details." << std::endl;[m
[31m-    std::cout << "You should have received a copy of the GNU General Public License" << std::endl;[m
[31m-    std::cout << "along with this program. If not, see <https://www.gnu.org/licenses/>." << std::endl;[m
[31m-}[m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/src/server/Logger.cpp b/src/server/Logger.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..7e241af[m
[1m--- /dev/null[m
[1m+++ b/src/server/Logger.cpp[m
[36m@@ -0,0 +1,27 @@[m
[32m+[m[32m//[m
[32m+[m[32m// Created by eldar on 08.09.24.[m
[32m+[m[32m//[m
[32m+[m
[32m+[m[32m#include "Logger.h"[m
[32m+[m
[32m+[m[32mLogger::Logger() {[m
[32m+[m
[32m+[m[32m    add_common_attributes();[m
[32m+[m[32m    add_console_log(std::cout, format = "[%TimeStamp%]: %Message%");[m
[32m+[m[32m    add_file_log([m
[32m+[m[32m        file_name = "server_logs/server_log_%N.log",[m
[32m+[m[32m        rotation_size = 10 * 1024 * 1024, // Ротація файлу при досягненні 10 МБ[m
[32m+[m[32m        format = "[%TimeStamp%]: %Message%\n",[m
[32m+[m[32m        open_mode = ios_base::app,[m
[32m+[m[32m        auto_flush = true[m
[32m+[m[32m    );[m
[32m+[m[32m    core::get()->set_filter(trivial::severity >=info);[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid Logger::logMessage(severity_level severityLevel, string message) {[m
[32m+[m[32m    BOOST_LOG_SEV(logger, severityLevel) << message;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m
[1mdiff --git a/src/server/Logger.h b/src/server/Logger.h[m
[1mnew file mode 100644[m
[1mindex 0000000..b2570bd[m
[1m--- /dev/null[m
[1m+++ b/src/server/Logger.h[m
[36m@@ -0,0 +1,35 @@[m
[32m+[m[32m//[m
[32m+[m[32m// Created by eldar on 08.09.24.[m
[32m+[m[32m//[m
[32m+[m
[32m+[m[32m#ifndef LOGGER_H[m
[32m+[m[32m#define LOGGER_H[m
[32m+[m
[32m+[m[32m#include <iostream>[m
[32m+[m[32m#include <boost/log/trivial.hpp>[m
[32m+[m[32m#include <boost/log/core.hpp>[m
[32m+[m[32m#include <boost/log/sources/logger.hpp>[m
[32m+[m[32m#include <boost/log/utility/setup/file.hpp>[m
[32m+[m[32m#include <boost/log/utility/setup/console.hpp>[m
[32m+[m[32m#include <boost/log/utility/setup/common_attributes.hpp>[m
[32m+[m
[32m+[m
[32m+[m[32musing namespace std;[m
[32m+[m[32musing namespace boost::log::trivial;[m
[32m+[m[32musing namespace boost::log::sources;[m
[32m+[m[32musing namespace boost::log;[m
[32m+[m[32musing namespace boost::log::keywords;[m
[32m+[m
[32m+[m
[32m+[m[32mclass Logger {[m
[32m+[m[32mpublic:[m
[32m+[m[32m    Logger();[m
[32m+[m
[32m+[m[32m    void logMessage(severity_level severityLevel, string message);[m
[32m+[m
[32m+[m[32mprivate:[m
[32m+[m[32m    severity_logger<severity_level> logger;[m
[32m+[m[32m};[m
[32m+[m
[32m+[m
[32m+[m[32m#endif //LOGGER_H[m
[1mdiff --git a/src/server/tcp_server.cpp b/src/server/tcp_server.cpp[m
[1mindex f5c2629..edd32f9 100644[m
[1m--- a/src/server/tcp_server.cpp[m
[1m+++ b/src/server/tcp_server.cpp[m
[36m@@ -16,33 +16,14 @@[m
 */[m
 #include <tcp_server.h>[m
 [m
[31m-[m
[31m-[m
 using boost::asio::ip::tcp;[m
 [m
 // FIX:[m
 // Previous logs can be deleted when server is started.[m
 [m
[31m-void init_logging() {[m
[31m-    namespace logging = boost::log;[m
[31m-    namespace keywords = boost::log::keywords;[m
[31m-[m
[31m-    logging::add_common_attributes();[m
[31m-    logging::add_console_log(std::cout, keywords::format = "[%TimeStamp%]: %Message%");[m
[31m-    logging::add_file_log([m
[31m-        keywords::file_name = "server_logs/server_log_%N.log",[m
[31m-        keywords::rotation_size = 10 * 1024 * 1024, // Ротація файлу при досягненні 10 МБ[m
[31m-        keywords::format = "[%TimeStamp%]: %Message%\n",[m
[31m-        keywords::auto_flush = true[m
[31m-    );[m
[31m-    logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);[m
[31m-}[m
[31m-[m
[31m-[m
 tcp_server::tcp_server(boost::asio::io_context &io_context, const std::string &ip_address, const unsigned short port)[m
         : acceptor(io_context, tcp::endpoint(boost::asio::ip::make_address(ip_address), port)) {[m
[31m-    init_logging();[m
[31m-    BOOST_LOG_TRIVIAL(info) << "Server started";[m
[32m+[m[32m    logger.logMessage(info, "Server started");[m
     start_accept();[m
 }[m
 [m
[36m@@ -50,14 +31,14 @@[m [mvoid tcp_server::start_accept() {[m
     auto socket = std::make_shared<tcp::socket>(acceptor.get_executor());[m
     acceptor.async_accept(*socket, [this, socket](boost::system::error_code error_code) {[m
         if (!error_code) {[m
[31m-            BOOST_LOG_TRIVIAL(info) << "New connection";[m
             start_read(socket);[m
[31m-        } else BOOST_LOG_TRIVIAL(error) << "Error occured: " << error_code.message();[m
[32m+[m[32m            logger.logMessage(info, "New connection");[m
[32m+[m[32m        } else logger.logMessage(error, "Error occures: " + error_code.message());[m
         start_accept();[m
     });[m
 }[m
 [m
[31m-void tcp_server::start_read(const std::shared_ptr<tcp::socket>& socket) const {[m
[32m+[m[32mvoid tcp_server::start_read(const std::shared_ptr<tcp::socket>& socket) {[m
     auto buffer = std::make_shared<boost::asio::streambuf>();[m
     async_read_until(*socket, *buffer, "\n",[m
     [this, socket, buffer](boost::system::error_code error_code, std::size_t bytes_transfered) {[m
[36m@@ -67,8 +48,8 @@[m [mvoid tcp_server::start_read(const std::shared_ptr<tcp::socket>& socket) const {[m
             std::getline(input_stream, message);[m
 [m
             // TO-DO: Make message handler[m
[31m-            BOOST_LOG_TRIVIAL(info) << "Received message: " << message;[m
[31m-        } else BOOST_LOG_TRIVIAL(warning) << "Connection closed";[m
[32m+[m[32m            logger.logMessage(info, "Received message: " + message);[m
[32m+[m[32m        } else logger.logMessage(warning, "Connection closed");[m
     });[m
 }[m
 [m
[1mdiff --git a/src/server/tcp_server.h b/src/server/tcp_server.h[m
[1mindex 24b589b..5e1517e 100644[m
[1m--- a/src/server/tcp_server.h[m
[1m+++ b/src/server/tcp_server.h[m
[36m@@ -17,6 +17,8 @@[m
 #ifndef TCPSERVER_H[m
 #define TCPSERVER_H[m
 [m
[32m+[m[32m#include <licenseInfo.h>[m
[32m+[m
 #include <boost/asio.hpp>[m
 #include <iostream>[m
 #include <boost/log/trivial.hpp>[m
[36m@@ -26,6 +28,7 @@[m
 #include <boost/log/utility/setup/console.hpp>[m
 #include <boost/log/utility/setup/common_attributes.hpp>[m
 [m
[32m+[m[32m#include <Logger.h>[m
 [m
 using boost::asio::ip::tcp;[m
 [m
[36m@@ -34,8 +37,9 @@[m [mpublic:[m
     tcp_server(boost::asio::io_context &io_context, const std::string &ip_address, unsigned short port);[m
 private:[m
     void start_accept();[m
[31m-    void start_read(const std::shared_ptr<tcp::socket>& socket) const;[m
[32m+[m[32m    void start_read(const std::shared_ptr<tcp::socket>& socket);[m
     tcp::acceptor acceptor;[m
[32m+[m[32m    Logger logger;[m
 [m
 };[m
 [m
