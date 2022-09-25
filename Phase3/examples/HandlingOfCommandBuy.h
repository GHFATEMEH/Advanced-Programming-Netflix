#ifndef HANDLING_OF_COMMAND_BUY_H
#define HANDLING_OF_COMMAND_BUY_H

#include "ErrorCheakingBuy.h"
#include <vector>
#include <string>

class ProgramData;
class Films;

class HandlingOfCommandBuy {
public:
    void buy_film(std::string id, std::string rate, ProgramData* program_data);
    void find_film_details(std::string id, std::string &year, std::string &length, std::string &price,
    std::string &name, std::string &summary, std::string &director, std::vector<Films*>film);
    void cheak_error_for_buy(std::string film_id, std::vector<Films*>film,
    ProgramData* program_data);
private:
    ErrorCheakingBuy error_cheaking_buy;
};
#endif