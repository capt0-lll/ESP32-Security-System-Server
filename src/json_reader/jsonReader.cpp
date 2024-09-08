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
#include "jsonReader.h"


void jsonReader::read(std::string &ip, unsigned short &port) {

    try {
        boost::property_tree::ptree ptree;
        read_json(json_file, ptree);
        ip = ptree.get<std::string>("ip");
        port = std::stoi (ptree.get<std::string>("port"));
    } catch (std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }

}