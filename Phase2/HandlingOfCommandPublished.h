#ifndef HANDLING_OF_COMMAND_PUBLISHED
#define HANDLING_OF_COMMAND_PUBLISHED

#include "ListOfFilmSorted.h"
#include "ErrorCheakingFilm.h"
#include <string>
#include <vector>

class ProgramData;


class HandlingOfCommandPublished {
public:
    void input_published(std::vector<std::string>separated_input, ProgramData* program_data);
private:
    ListOfFilmSorted list_of_film_sorted;
    ErrorCheakingFilm error_cheaking_film;
};
#endif