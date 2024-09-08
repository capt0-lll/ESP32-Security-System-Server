# TCP-server for security system

This project implements TCP-server for security system based on ESP32 microcontroller. 
It supports message receiving and logging events.
In future updates will be added message handling

<!-- CONFIGURATION SECTION -->

# Configuration
Configuration is done through the `server_config.json` file, 
which you need to create and provide information about the
IP address and port that the server will listen on,
in the same directory as the server executable file

Here is example of this file
   ```json
      {
      "ip": "127.0.0.1", 
      "port": 12345
      }
   ```

<!-- INSTALLATION SECTION -->

# How to install
### This project use:

- **Boost**(at least version 4.3)
- **CMake**(at least version 3.28)
- **Compiler** that supports C++26

### Installation

1. Copy this code using git clone

   ``` bash
      git clone https://github.com/capt0-lll/ESP32-Security-System-Server
   ```
2. Create and enter a build directory for the server
   ```bash
      mkdir build
   ```
   ```bash
      cd build
   ```

3. Run CMake command specifying directory, where you copied the code
   ```bash     
      cmake <absolute/path/to/security_system_back_end/>
   ```
4. Build server using make command in build directory

   ```bash
      make
   ```
        
5. Run server using next command in this directory. 
Make sure you have configuration file `server_config.json`
   ```bash
      ./security_system_back_end
   ```
   
   <!-- PROJECT STRUCTURE SECTION -->

# Project structure:
   - **TCP-Server:** Handles incoming TCP-connections and processes client requests.
   - **JSON-reader:** Used for reading configuration files
   - **Main:** Executable file which has entry point to an application

   <!-- FUTURE PLANS SECTION --> 

# Future plans:
   - **Add message handling**
   - **Add API to work with ESP32 microcontrollers**
   - **Add a Multi-Platform API** 

# Contributing

You are welcomed to contribute to this project. To get started:

1. Fork the repository.
2. Create a new branch, for your changes.
3. Make your changes and test them.
4. Submit a pull request with a description of your changes.

# License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE.txt) file for details.
