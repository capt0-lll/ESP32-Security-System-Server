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
#include <serverTCP.h>

using boost::asio::ip::tcp;

// FIX:
// Previous logs can be deleted when server is started.

serverTCP::serverTCP(boost::asio::io_context &io_context, const std::string &ip_address, const unsigned short port)
        : acceptor(io_context, tcp::endpoint(boost::asio::ip::make_address(ip_address), port)) {
    logger.logMessage(info, "Server started");
    startAccept();
}

void serverTCP::startAccept() {
    auto socket = std::make_shared<tcp::socket>(acceptor.get_executor());
    acceptor.async_accept(*socket, [this, socket](boost::system::error_code error_code) {
        if (!error_code) {
            startRead(socket);
            logger.logMessage(info, "New connection");
        } else logger.logMessage(error, "Error occures: " + error_code.message());
        startAccept();
    });
}

void serverTCP::startRead(const std::shared_ptr<tcp::socket>& socket) {
    auto buffer = std::make_shared<boost::asio::streambuf>();
    async_read_until(*socket, *buffer, "\n",
    [this, socket, buffer](boost::system::error_code error_code, std::size_t bytes_transfered) {
        if(!error_code) {
            std::istream input_stream(buffer.get());
            std::string message;
            std::getline(input_stream, message);

            // TO-DO: Make message handler
            logger.logMessage(info, "Received message: " + message);
        } else logger.logMessage(warning, "Connection closed");
    });
}


