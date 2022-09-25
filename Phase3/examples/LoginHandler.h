#ifndef LOGIN_HANDLER_H
#define LOGIN_HANDLER_H

#include "../server/server.hpp"

#include <string>

class ProgramData;

class LoginHandler : public RequestHandler {
public:
  LoginHandler(ProgramData* _program_data);
  Response *callback(Request *request);
  void login_user(std::string username, std::string password);
  Response* set_response_login_handler();
private:
  ProgramData* program_data;
};
#endif