#ifndef ERROR_CHEAKING_MONEY_H
#define ERROR_CHEAKING_MONEY_H

#include <vector>
#include <string>

class ProgramData;

class ErrorCheakingMoney {
public:
    void cheak_customer_in(ProgramData* program_data);
    void cheak_input_for_money(std::vector<std::string>separated_input);
    void cheak_number_of_input_money(std::vector<std::string>separated_input);
    void cheak_publisher_in(ProgramData* program_data);
};
#endif