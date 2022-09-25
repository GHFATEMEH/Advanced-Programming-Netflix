#ifndef LOGOUT_HANDLER
#define LOGOUT_HANDLER

#include "../server/server.hpp"

class ProgramData;

class LogoutHandler : public RequestHandler {
public:
  LogoutHandler(ProgramData* _program_data);
  Response *callback(Request *request);
private:
  ProgramData* program_data;
};
#endif