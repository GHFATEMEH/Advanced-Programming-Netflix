#ifndef HANDLING_OF_COMMAND_BUY_H
#define HANDLING_OF_COMMAND_BUY_H

#include "ErrorCheakingBuy.h"
#include <vector>
#include <string>

class ProgramData;
class Customer;
class Publisher;

class HandlingOfCommandBuy {
public:
    void input_buy(std::vector<std::string>seperated_input, ProgramData* program_data);
    void cheak_for_user_have_money_and_reduce_money(Customer *customer, ProgramData* program_data,
    int id);
    void reduce_customer_money(int film_price, Customer* customer);
    void reduce_publisher_money(int film_price, Publisher* publisher);
    int save_film_bought_for_publisher(int id, ProgramData* program_data, int price_of_film, int rate);
    void notification_film_bought_customer(Customer* customer, std::string film_id,
    ProgramData* program_data,
    int number_of_publisher, int id);
    void save_buy_notifacation(int user_id, std::string username, std::string film_id, 
    std::string film_name, int number_of_publisher, ProgramData* program_data);
    void cheak_all_errors_for_buy(std::vector<std::string>seperated_input,
    ProgramData* program_data);
    void cheak_for_publisher_have_money_and_reduce_money(int id, Publisher* publisher,
    ProgramData* program_data);
    void notification_film_bought_by_publisher(Publisher* publisher,
    std::string film_id, ProgramData* program_data, int number_of_publisher, int id);
    void buy_film_customer(Customer* customer, ProgramData* program_data,
    int id, std::vector<std::string>seperated_input);
    void buy_film_publisher(Publisher* publisher, ProgramData* program_data,
    int id, std::vector<std::string>seperated_input);
private:
    ErrorCheakingBuy error_cheaking_buy;
};
#endif