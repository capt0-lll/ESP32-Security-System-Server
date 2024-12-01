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
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


using namespace std;
using namespace boost::log::trivial;
using namespace boost::log::sources;
using namespace boost::log;
using namespace boost::log::keywords;


class Logger {
public:
    Logger();

    void logMessage(severity_level severityLevel, string message);

private:
    severity_logger<severity_level> logger;
};


#endif //LOGGER_H
