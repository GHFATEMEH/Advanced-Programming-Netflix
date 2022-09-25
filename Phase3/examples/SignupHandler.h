#ifndef SIGNUP_HANDLER
#define SIGNUP_HANDLER

#include "../server/server.hpp"

#include <string>

class ProgramData;

class SignupHandler : public RequestHandler {
public:
  SignupHandler(ProgramData* _program_data);
  Response *callback(Request *request);
  void signup_user(ProgramData* program_data, std::string username, std::string password,
  std::string age, std::string publisher_or_not, std::string email);
  Response* set_response();
private:
  ProgramData* program_data;
};
#endif