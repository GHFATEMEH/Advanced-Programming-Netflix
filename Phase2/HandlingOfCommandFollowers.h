#ifndef HANDLING_OF_COMMAND_FOLLOWERS_H
#define HANDLING_OF_COMMAND_FOLLOWERS_H

#include "ErrorCheakingFollowers.h"
#include <vector>
#include <string>

class ProgramData;
class Customer;
class Publisher;

class HandlingOfCommandFollowers {
public:
    void input_followers(std::vector<std::string>separated_input, ProgramData* program_data);
    void followe_publisher(std::vector<std::string>separated_input, ProgramData* program_data,
    Customer* customer, Publisher* publisher);
    void cheak_id_is_available(std::string &publisher_id, ProgramData* program_data,
    std::vector<std::string>separated_input);
    bool cheak_id_in_publishers(std::string publisher_id, ProgramData* program_data);
    bool cheak_id_is_digit(std::string publisher_id);
    void save_publisher_followers(int publisher_id, Customer* customer, ProgramData* program_data);
    bool did_not_followe_before(std::string publisher_id, Customer* customer,
    Publisher* publisher, ProgramData* program_data);
    void print_publisher_followers(Publisher* publisher, ProgramData* program_data);
    void save_publisher_followers_for_publisher(int publisher_id,
    Publisher* publisher, ProgramData* program_data);
private:
    ErrorCheakingFollowers error_cheaking_followers;
};
#endif