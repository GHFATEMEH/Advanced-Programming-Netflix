#include "HandlingOfCommandSignup.h"
#include "define.h"
#include "ProgramData.h"
#include "Publisher.h"
#include "Customer.h"
#include "ErrorCheakingSignup.h"

#include <iostream>
#include <string>

using namespace std;

void HandlingOfCommandSignup::signup_user(ProgramData* program_data, string username,
string password, string age, string email) {
    if(program_data->get_type_of_user_in_system() == PUBLISHER) {
        program_data->add_new_publisher(new Publisher(email, username, password, age,
        program_data->get_customer_id()));
        program_data->add_new_customer(new Customer::Customer(email, username, password, age,
        program_data->get_customer_id()));
    }
    else
        program_data->add_new_customer(new Customer::Customer(email, username, password, age,
        program_data->get_customer_id()));
    program_data->set_username_in_system(username);
}

void HandlingOfCommandSignup::input_signup(ProgramData* program_data, string username,
string password, string age, string publisher_or_not, string email) {
    error_cheaking_signup.cheak_input_for_signup(username, password, publisher_or_not,program_data);
    signup_user(program_data, username, password, age, email);
    program_data->set_be_login_or_signup_for_handling_command(IN);
    cout << OK << "\n";
}

