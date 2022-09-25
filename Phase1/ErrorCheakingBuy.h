#ifndef ERROR_CHEAKING_BUY
#define ERROR_CHEAKING_BUY

#include "ErrorCheakingFilm.h"

class ErrorCheakingBuy : public ErrorCheakingFilm {
public:
    void cheak_buy_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_buy(std::vector<std::string>separated_input);
};
#endif