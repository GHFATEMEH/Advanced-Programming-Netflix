#include "LoginHandler.h"
#include "HandlingOfCommandLogin.h"
#include "ProgramData.h"
#include "define.h"

#include <string>

using namespace std;

LoginHandler::LoginHandler(ProgramData* _program_data ) {
    program_data = _program_data;
}

void LoginHandler::login_user(string username, string password) {
    HandlingOfCommandLogin command_login;
    command_login.cheak_input_for_login(username, password, program_data);
}

Response* LoginHandler::set_response_login_handler() {
    Response *response;
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        response = Response::redirect("/customer_home");
    else
        response = Response::redirect("/publisher_home");
    response->setSessionId(to_string(program_data->get_customer_id() - 1));
    return response;
}

Response* LoginHandler::callback(Request *request) {
    string username = request->getBodyParam("username");
    string password = request->getBodyParam("password");
    login_user(username, password);
    Response *response = set_response_login_handler();
    return response;
}
