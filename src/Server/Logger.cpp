/*  ESP-32 Security System Server for
    Copyright (C) 2024  Eldar Vanin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "Logger.h"

Logger::Logger() {

    add_common_attributes();
    add_console_log(std::cout, format = "[%TimeStamp%]: %Message%");
    add_file_log(
        file_name = "server_logs/server_log_%N.log",
        rotation_size = 10 * 1024 * 1024, // Ротація файлу при досягненні 10 МБ
        format = "[%TimeStamp%]: %Message%\n",
        open_mode = ios_base::app,
        auto_flush = true
    );
    core::get()->set_filter(trivial::severity >=info);
}

void Logger::logMessage(severity_level severityLevel, string message) {
    BOOST_LOG_SEV(logger, severityLevel) << message;
}




