#include "CustomerProfileHandler.h"
#include "ProgramData.h"
#include "define.h"
#include "Customer.h"
#include "Films.h"
#include "HandlingOfCommandFilm.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

CustomerProfileHandler::CustomerProfileHandler(string filePath, ProgramData* _program_data) :
    TemplateHandler(filePath) {
        program_data = _program_data;
}

void CustomerProfileHandler::cheak_error_user_in_for_customer_profile() {
    if(program_data->get_be_login_or_signup_for_handling_command() == OUT)
        throw Server::Exception("You should login first");
}

map<string, string> CustomerProfileHandler::handle(Request *request) {
    map<string, string> context;
    HandlingOfCommandFilm command_film;
    cheak_error_user_in_for_customer_profile();
    Customer* customer = program_data->find_customer_in_system();
    vector<Films*>films = customer->get_films_that_customer_bought();
    if(request->getQueryParam("money") != "\0")
        customer->add_to_money(stoi(request->getQueryParam("money")));
    command_film.print_films(films, context);
    return context;
}