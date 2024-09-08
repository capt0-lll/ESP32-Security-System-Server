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
#ifndef LICENSEINFO_H
#define LICENSEINFO_H

#include <iostream>
#include <thread>

using namespace std;

class licenseInfo {
public:
    licenseInfo();
    static void runReadingInput();
private:
    static void showLicense();
    static void showWarranty();
    static void showLicenseOnStart();

};



#endif //LICENSEINFO_H
