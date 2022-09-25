#ifndef ERROR_CHEAKING_BUY
#define ERROR_CHEAKING_BUY

#include <string>
#include <vector>

class Films;
class ProgramData;

class ErrorCheakingBuy {
public:
    int find_price_of_film(std::string film_id, std::vector<Films*>film);
    void cheak_money_to_buy_film(std::string film_id, std::vector<Films*>film, 
    ProgramData* program_data);
};
#endif