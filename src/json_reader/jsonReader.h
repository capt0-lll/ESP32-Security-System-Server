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

#ifndef JSON_READER_H
#define JSON_READER_H

#include <iostream>
#include <boost/property_tree/json_parser.hpp>

// Change file location to your server configuration file
const std::string json_file = "server_config.json";
const std::string port_key = "port";
const std::string ip_key = "ip";

class jsonReader {
public:
    static void read(std::string &ip, unsigned short &port);
};



#endif //JSON_READER_H
