#ifndef FILM_DETAILS_H
#define FILM_DETAILS_H

#include "../server/server.hpp"

#include <string>
#include <map>

class ProgramData;

class FilmDetailsHandler : public TemplateHandler {
public:
  FilmDetailsHandler(std::string filePath, ProgramData* _program_data);
  std::map<std::string, std::string> handle(Request *request);
  void cheak_error_home_page();
private:
    ProgramData* program_data;
};
#endif