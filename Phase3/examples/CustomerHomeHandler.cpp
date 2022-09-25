#include "CustomerHomeHandler.h"
#include "ProgramData.h"
#include "define.h"
#include "Customer.h"
#include "Films.h"
#include "HandlingOfCommandFilm.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

CustomerHomeHandler::CustomerHomeHandler(string filePath, ProgramData* _program_data) :
    TemplateHandler(filePath) {
        program_data = _program_data;
}

void CustomerHomeHandler::cheak_error_customer_home_page() {
    if(program_data->get_be_login_or_signup_for_handling_command() == OUT)
        throw Server::Exception("You should login first");
}

map<string, string> CustomerHomeHandler::handle(Request *request) {
    map<string, string> context;
    HandlingOfCommandFilm command_film;
    cheak_error_customer_home_page();
    Customer* customer = program_data->find_customer_in_system();
    vector<Films*>films = program_data->get_film_vector();
    vector<Films*>films_bought = customer->get_films_that_customer_bought();
    command_film.print_films_did_not_bought_and_can_buy(customer, films, films_bought, context);
    return context;
}
