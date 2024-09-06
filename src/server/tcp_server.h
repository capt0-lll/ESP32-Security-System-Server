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
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


using boost::asio::ip::tcp;

class tcp_server {
public:
    tcp_server(boost::asio::io_context &io_context, const std::string &ip_address, unsigned short port);
private:
    void start_accept();
    void start_read(const std::shared_ptr<tcp::socket>& socket) const;
    tcp::acceptor acceptor;

};

#endif //TCPSERVER_H
