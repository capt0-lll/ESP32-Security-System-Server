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

#include <ServerTCP.h>
#include <ReaderJSON.h>


#include <boost/asio.hpp>
#include <thread>
#include <iostream>


using namespace std;

unsigned short port;
string ip;


int main() {

    ReaderJSON::read(ip,port);
    try {



        boost::asio::io_context io_context;


        thread showLicense(LicenseInfo{}.runReadingInput);

        ServerTCP server(io_context, ip, port);
        thread server_run([&io_context]() {
            io_context.run();
        });

        showLicense.join();
        server_run.join();

    } catch (exception &exception) {
        cerr << "Error: " << exception.what() << endl;
    }

}