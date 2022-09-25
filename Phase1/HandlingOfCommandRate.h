#ifndef HANDLING_OF_COMMAND_RATE_H
#define HANDLING_OF_COMMAND_RATE_H

#include "ErrorCheakingRate.h"

#include <vector>
#include <string>

class ProgramData;
class Customer;

class HandlingOfCommandRate {
public:
    void input_rate(std::vector<std::string>separated_input, ProgramData* program_data);
    void add_to_rate(std::vector<std::string>separated_input, Customer* customer,
    ProgramData* program_data);
    void cheak_all_error_for_rate(std::vector<std::string>separated_input,
    ProgramData* program_data, std::string id);
    std::string find_name_of_film(std::string film_id, ProgramData* program_data);
    int find_publisher_with_this_id(ProgramData* program_data, std::string film_id);
    void add_rate_notification(ProgramData* program_data, std::string name_of_film,
    std::string film_id, int publisher_code, std::string customer_name, int customer_id);
    void send_notification_to_publisher(std::string film_id, Customer* customer,
    ProgramData* program_data);
private:
    ErrorCheakingRate error_cheaking_rate;
};
#endif