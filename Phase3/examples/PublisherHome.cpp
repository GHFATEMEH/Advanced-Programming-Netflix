#include "PublisherHome.h"
#include "ProgramData.h"
#include "define.h"
#include "Publisher.h"
#include "Films.h"
#include "ErrorCheakingFilm.h"
#include "HandlingOfCommandFilm.h"

#include <string>
#include <map>

using namespace std;

PublisherHome::PublisherHome(string filePath, ProgramData* _program_data) :
    TemplateHandler(filePath) {
        program_data = _program_data;
}

void PublisherHome::cheak_error_publisher_home_page() {
    ErrorCheakingFilm error_cheaking_film_view;
    error_cheaking_film_view.cheak_all_error_film(program_data);
}

map<string, string> PublisherHome::handle(Request *request) {
    map<string, string> context;
    HandlingOfCommandFilm command_film;
    cheak_error_publisher_home_page();
    Publisher* publisher = program_data->find_publisher_in_system();
    vector<Films*>films = publisher->get_films();
    if(request->getQueryParam("director") != "\0")
        command_film.print_publisher_films_filter_director(films,
        request->getQueryParam("director"), context);
    else 
    command_film.print_films(films, context);
    return context;
}
