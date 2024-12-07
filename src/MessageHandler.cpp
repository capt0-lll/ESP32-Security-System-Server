#include "MessageHandler.h"

// TODO: Write message handling code
string MessageHandler::handleMessage(string message) {
  if (message.compare(0, 3, "GET", 0, 3) == 0) {
    return getRequestHandling(message);
  } else if (message.compare(0, 4, "POST", 0, 4) == 0) {
    return postRequestHandling(message);
  } else {
    return "Error! Unknown request!";
  }
}

// TODO: Add file blacklist
string MessageHandler::getRequestHandling(string message) {
  if (message.find(".json", 0) != string::npos) {
    if (message.length() < 4)
      return "Error! No \".json\" file found in request";
    string jsonFile = message.substr(4, string::npos);
    ifstream file(jsonFile);
    if (!file.is_open()) {
      return jsonFile;
    }
    string fileContent;
    string line;
    while (getline(file, line)) {
      fileContent += line + '\n';
    }
    return fileContent;
  } else
    return "Error! No \".json\" file found in request";
}

// TODO: Add files blacklist
string MessageHandler::postRequestHandling(string message) { return ""; }