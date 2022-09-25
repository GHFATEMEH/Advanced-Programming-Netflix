#ifndef ADD_FILM_HANDLER_H
#define ADD_FILM_HANDLER_H

#include "../server/server.hpp"

#include <string>

class ProgramData;

class AddFilmHandler : public RequestHandler {
public:
    AddFilmHandler(ProgramData* _program_data);
    Response *callback(Request *request);
    void add_film(std::string film_name, std::string length, std::string price,
    std::string rate, std::string year, std::string director, std::string summary);
private:
    ProgramData* program_data;
};
#endif