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
    std::vector<std::string>separated_input, Publisher* publisher);
    void calculate_money(Publisher* publisher, ProgramData* program_data);
    void find_rate_and_price(int film_id, Publisher* publisher, int &price, float &rate);
    void show_money(ProgramData* program_data);
    void error_cheaking_post_money(ProgramData* program_data,
    std::vector<std::string>separated_input);
    void post_money(ProgramData* program_data, std::vector<std::string>separated_input);
    void show_money_of_customer(ProgramData* program_data);
    void show_money_of_publisher(ProgramData* program_data);
private:
    ErrorCheakingMoney error_cheaking_money;
};
#endif