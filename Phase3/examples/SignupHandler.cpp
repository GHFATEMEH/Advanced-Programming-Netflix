#include "SignupHandler.h"
#include "ProgramData.h"
#include "HandlingOfCommandSignup.h"
#include "define.h"

#include <string>

using namespace std;

SignupHandler::SignupHandler(ProgramData* _program_data) {
    program_data = _program_data;
}

void SignupHandler::signup_user(ProgramData* program_data, string username, string password,
string age, string publisher_or_not, string email) {
    HandlingOfCommandSignup command_signup;
    command_signup.input_signup(program_data, username, password, age, publisher_or_not, email);
}

Response* SignupHandler::set_response() {
    Response *response;
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        response = Response::redirect("/customer_home");
    else
        response = Response::redirect("/publisher_home");
    response->setSessionId(to_string(program_data->get_customer_id() - 1));
    return response;
}

Response* SignupHandler::callback(Request *request) {
    string username = request->getBodyParam("username");
    string age = request->getBodyParam("age");
    string publisher_or_not = request->getBodyParam("publisher_or_not");
    string email = request->getBodyParam("email");
    string password = request->getBodyParam("password");
    string repeated_password = request->getBodyParam("repeated_password");
    signup_user(program_data, username, password, age, publisher_or_not, email);
    Response *response = set_response();
    return response;
}
