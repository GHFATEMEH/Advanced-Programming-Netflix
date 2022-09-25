#include "AddFilmHandler.h"
#include "ProgramData.h"
#include "define.h"
#include "HandlingOfCommandFilm.h"

#include <string>

using namespace std;

AddFilmHandler::AddFilmHandler(ProgramData* _program_data) {
    program_data = _program_data;
}

void AddFilmHandler::add_film(string film_name, string length, string price,
string rate, string year, string director, string summary) {
    HandlingOfCommandFilm command_film;
    command_film.add_film(year, length, price, film_name, summary, director, program_data, rate);
}

Response* AddFilmHandler::callback(Request *request) {
    string film_name =  request->getBodyParam("film_name");
    string length =  request->getBodyParam("length");
    string price =  request->getBodyParam("price");
    string rate =  request->getBodyParam("rate");
    string year =  request->getBodyParam("year");
    string director =  request->getBodyParam("director");
    string summary =  request->getBodyParam("summary");
    add_film(film_name, length, price, rate, year, director, summary);
    Response *res = Response::redirect("/publisher_home");
    return res;
}