#include "FilmDetailsHandler.h"
#include "define.h"
#include "ProgramData.h"
#include "HandlingOfCommandFilm.h"
#include "Customer.h"

#include <vector>
#include <string>
#include <map>

using namespace std;

FilmDetailsHandler::FilmDetailsHandler(string filePath, ProgramData* _program_data) :
    TemplateHandler(filePath) {
        program_data = _program_data;
}

void FilmDetailsHandler::cheak_error_home_page() {
    if(program_data->get_be_login_or_signup_for_handling_command() == OUT)
        throw Server::Exception("You should login first");
}

map<string, string> FilmDetailsHandler::handle(Request *request) {
    map<string, string> context;
    HandlingOfCommandFilm command_film;
    cheak_error_home_page();
    vector<Films*>films = program_data->get_film_vector();
    cout << request->getQueryParam("id")<<"\n";
    command_film.print_film_details(films, request->getQueryParam("id"), context);
    command_film.print_recommended_movies(films, program_data, context, request->getQueryParam("id"));
    return context;
}