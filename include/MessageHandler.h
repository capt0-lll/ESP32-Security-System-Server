#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

class MessageHandler {
public:
  static string handleMessage(string message);

private:
  static string getRequestHandling(string message);
  static string postRequestHandling(string message);
};

#endif // MESSAGE_HANDLER_H