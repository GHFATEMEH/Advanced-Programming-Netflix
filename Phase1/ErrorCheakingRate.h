#ifndef ERROR_CHEAKING_RATE_H
#define ERROR_CHEAKING_RATE_H

#include "ErrorCheakingFilm.h"
#include <string>
#include <vector>

class ProgramData;
class Customer;

class ErrorCheakingRate : public ErrorCheakingFilm {
public:
    void cheak_film_has_bought(std::string id, ProgramData* program_data);
    void cheak_rote_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_rote(std::vector<std::string>separated_input);
};
#endif