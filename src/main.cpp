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
#include <json_reader.h>
#include <boost/asio.hpp>
#include <thread>
#include <iostream>
#include <string.h>

using namespace std;

unsigned short port;
string ip;

void show_license_info();
[[noreturn]] void handle_input();
void show_warranty();
void show_license();

int main() {

    show_license_info();
    thread handle_input_thread(handle_input);


    json_reader::read(ip,port);
    try {
        boost::asio::io_context io_context;
        tcp_server server(io_context, ip, port);


        thread server_run([&io_context]() {
            io_context.run();
        });
        handle_input_thread.join();
        server_run.join();
    } catch (exception &exception) {
        cerr << "Error: " << exception.what() << endl;
    }

}
void show_license_info() {
    std::cout << "ESP32 Security System Server Copyright (C) 2024 Eldar Vanin" << std::endl;
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions; type `show c` for details.\n" << std::endl;
}

[[noreturn]] void handle_input() {
    while(true) {
        string input;
        getline(cin, input);
        if(input == "show c") show_license();
        else if(input == "show w") show_warranty();
    }
}

void show_warranty() {
    std::cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w`." << std::endl;
    std::cout << "This is free software; you can redistribute it and/or modify" << std::endl;
    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;
    std::cout << "the Free Software Foundation. See the GNU General Public License for more details." << std::endl;
}

void show_license() {
    std::cout << "This program is free software: you can redistribute it and/or modify" << std::endl;
    std::cout << "it under the terms of the GNU General Public License as published by" << std::endl;
    std::cout << "the Free Software Foundation, either version 3 of the License, or" << std::endl;
    std::cout << "(at your option) any later version.\n" << std::endl;
    std::cout << "This program is distributed in the hope that it will be useful," << std::endl;
    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the" << std::endl;
    std::cout << "GNU General Public License for more details." << std::endl;
    std::cout << "You should have received a copy of the GNU General Public License" << std::endl;
    std::cout << "along with this program. If not, see <https://www.gnu.org/licenses/>." << std::endl;
}
