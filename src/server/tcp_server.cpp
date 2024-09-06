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
#include <tcp_server.h>



using boost::asio::ip::tcp;

// FIX:
// Previous logs can be deleted when server is started.

void init_logging() {
    namespace logging = boost::log;
    namespace keywords = boost::log::keywords;

    logging::add_common_attributes();
    logging::add_console_log(std::cout, keywords::format = "[%TimeStamp%]: %Message%");
    logging::add_file_log(
        keywords::file_name = "server_logs/server_log_%N.log",
        keywords::rotation_size = 10 * 1024 * 1024, // Ротація файлу при досягненні 10 МБ
        keywords::format = "[%TimeStamp%]: %Message%\n",
        keywords::auto_flush = true
    );
    logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}


tcp_server::tcp_server(boost::asio::io_context &io_context, const std::string &ip_address, const unsigned short port)
        : acceptor(io_context, tcp::endpoint(boost::asio::ip::make_address(ip_address), port)) {
    init_logging();
    BOOST_LOG_TRIVIAL(info) << "Server started";
    start_accept();
}

void tcp_server::start_accept() {
    auto socket = std::make_shared<tcp::socket>(acceptor.get_executor());
    acceptor.async_accept(*socket, [this, socket](boost::system::error_code error_code) {
        if (!error_code) {
            BOOST_LOG_TRIVIAL(info) << "New connection";
            start_read(socket);
        } else BOOST_LOG_TRIVIAL(error) << "Error occured: " << error_code.message();
        start_accept();
    });
}

void tcp_server::start_read(const std::shared_ptr<tcp::socket>& socket) const {
    auto buffer = std::make_shared<boost::asio::streambuf>();
    async_read_until(*socket, *buffer, "\n",
    [this, socket, buffer](boost::system::error_code error_code, std::size_t bytes_transfered) {
        if(!error_code) {
            std::istream input_stream(buffer.get());
            std::string message;
            std::getline(input_stream, message);

            // TO-DO: Make message handler
            BOOST_LOG_TRIVIAL(info) << "Received message: " << message;
        } else BOOST_LOG_TRIVIAL(warning) << "Connection closed";
    });
}


