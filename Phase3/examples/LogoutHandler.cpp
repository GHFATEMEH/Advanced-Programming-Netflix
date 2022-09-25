#include "LogoutHandler.h"
#include "ProgramData.h"
#include "define.h"


using namespace std;

LogoutHandler::LogoutHandler(ProgramData* _program_data ) {
    program_data = _program_data;
}

Response* LogoutHandler::callback(Request *request) {
    program_data->set_be_login_or_signup_for_handling_command(OUT);
    Response *response = Response::redirect("/login");
    response->setSessionId("");
    return response;
}
