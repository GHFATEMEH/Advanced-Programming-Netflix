#ifndef HANDLING_OF_COMMAND_MONEY_H
#define HANDLING_OF_COMMAND_MONEY_H

#include "ErrorCheakingMoney.h"
#include <vector>
#include <string>

class ProgramData;
class Customer;
class Publisher;

class HandlingOfCommandMoney {
public:
    void input_money(std::vector<std::string>separated_input, ProgramData* program_data);
    void increase_money(ProgramData* program_data, Customer* customer,
    std::vector<std::string>separated_input);
    void calculate_money(Publisher* publisher);
    void find_rate_and_price(int film_id, Publisher* publisher, int &price, float &rate);
private:
    ErrorCheakingMoney error_cheaking_money;
};
#endif