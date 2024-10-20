//
// Created by eldar on 15.09.24.
//
#define BOOST_TEST_MAIN

#include <ServerTCP.h>
#include <ReaderJSON.h>


#include <boost/asio.hpp>
#include <boost/test/included/unit_test.hpp>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std;

string ip;
unsigned short port;

class TestServer {
public:
    TestServer(const string &ip, const unsigned short &port);
    ~TestServer();
private:
    boost::asio::io_context serverContext;
    thread serverRun;
    ServerTCP server;
};

bool connectToServer(const string &ip, const unsigned short &port, boost::asio::io_context &clientContext,
    tcp::socket &socket);
bool connectToServer(const string &ip, const unsigned short &port);

// Test if client is able to connect to the test server
BOOST_AUTO_TEST_CASE(connection_test) {
    ReaderJSON::read(ip, port);
    TestServer test(ip, port);

    bool result = connectToServer(ip, port);
    BOOST_TEST(result);
}

BOOST_AUTO_TEST_CASE(get_request_handling_test) {
    try {
        TestServer test(ip, port);
        boost::asio::io_context clientContext;

        tcp::socket socket(clientContext);

        if(!connectToServer(ip, port, clientContext, socket)) {
            BOOST_TEST_MESSAGE("Failed connect to server");
            BOOST_TEST(false);
        }

        const string request("GET options.json");
        write(socket, boost::asio::buffer(request));

        string optionsFileContent;

        try{
            ifstream file("options.json");
            stringstream buffer;
            buffer << file.rdbuf();
            optionsFileContent = buffer.str();
        } catch (exception &exception) {
            BOOST_TEST_MESSAGE(exception.what());
            BOOST_TEST(false);
        }

        this_thread::sleep_for(chrono::seconds(2));

        boost::asio::streambuf responce;
        read_until(socket, responce, "\n");

        istream responceStream(&responce);
        string optionsFileContentReceived;
        getline(responceStream, optionsFileContentReceived);

        BOOST_TEST_MESSAGE("Message received: " + optionsFileContentReceived);
        BOOST_TEST(optionsFileContentReceived == optionsFileContent);
    }
    catch(exception &exception) {
        BOOST_TEST_MESSAGE(exception.what());
        BOOST_TEST(false);
    }
}

BOOST_AUTO_TEST_CASE(post_request_handling_test) {
    try {
        TestServer test(ip, port);
        boost::asio::io_context clientContext;

        tcp::socket socket(clientContext);

        if(!connectToServer(ip, port, clientContext, socket)) {
            BOOST_TEST_MESSAGE("Failed connect to server");
            BOOST_TEST(false);
        }

        const string postRequestContent = "{\n\"device_on\": false\n\"smoke_detected\": false\n\"motion_detected\": false\n\"camera_on\": false\n}";
        const string request = ("POST device_status.json " + postRequestContent);
        write(socket, boost::asio::buffer(request));

        this_thread::sleep_for(chrono::seconds(2));

        boost::asio::streambuf responce;
        read_until(socket, responce, "\n");

        istream responceStream(&responce);
        string responceText;
        getline(responceStream, responceText);

        BOOST_TEST_MESSAGE("Message received: " + responceText);

        string deviceStatusFileContent;
        try{
            ifstream file("device_status.json");
            stringstream buffer;
            buffer << file.rdbuf();
            deviceStatusFileContent = buffer.str();
        } catch (exception &exception) {
            BOOST_TEST_MESSAGE(exception.what());
            BOOST_TEST(false);
        }

        BOOST_TEST_MESSAGE("Content of device_status.json file: " + deviceStatusFileContent);

        BOOST_TEST((postRequestContent == deviceStatusFileContent && responceText == "SUCCEED"));
    }
    catch (exception &exception) {
        BOOST_TEST_MESSAGE(exception.what());
        BOOST_TEST(false);
    }
}

TestServer::TestServer(const string &ip, const unsigned short &port) : server (serverContext, ip, port){
    serverRun = thread ([this]() {serverContext.run();});
}

TestServer::~TestServer() {
    serverContext.stop();
    serverRun.join();
}


bool connectToServer(const string &ip, const unsigned short &port, boost::asio::io_context &clientContext, tcp::socket &socket) {
    try {

        tcp::resolver resolver(clientContext);
        const tcp::resolver::results_type endpoint = resolver.resolve(ip, to_string(port));
        connect(socket, endpoint);
        return true;
    } catch(exception &exception) {
        BOOST_TEST_MESSAGE(exception.what());
        return false;
    }
}

bool connectToServer(const string &ip, const unsigned short &port) {
    boost::asio::io_context clientContext;
    tcp::socket socket(clientContext);
    return connectToServer(ip, port, clientContext, socket);
}