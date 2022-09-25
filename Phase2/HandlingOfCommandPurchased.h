#ifndef HANDLING_OF_COMMAND_PURCHASED
#define HANDLING_OF_COMMAND_PURCHASED

#include "ListOfFilmSorted.h"

#include <string>
#include <vector>

class Publisher;
class ProgramData;

class HandlingOfCommandPurchased {
public:
    void input_purchased(std::vector<std::string>separated_input, ProgramData* program_data);
    void print_all_films(ProgramData* program_data);
private:
    ListOfFilmSorted list_of_film_sorted;
};
#endif