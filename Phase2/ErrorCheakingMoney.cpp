#include "ErrorCheakingMoney.h"
#include "ProgramData.h"
#include "Exception.h"
#include "define.h"

#include <string>
#include <vector>

using namespace std;

void ErrorCheakingMoney::cheak_customer_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == PUBLISHER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingMoney::cheak_publisher_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == CUSTOMER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingMoney::cheak_input_for_money(std::vector<std::string>separated_input) {
    if(separated_input[3] == AMOUNT)
        return;
    else
        throw Bad_Request_Exception();
}

void ErrorCheakingMoney::cheak_number_of_input_money(std::vector<std::string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == 5 )
        return;
    else
        throw Bad_Request_Exception();
}
