#include "HandlingOfCommandSignup.h"
#include "define.h"
#include "ProgramData.h"
#include "Publisher.h"
#include "Customer.h"
#include "ErrorCheakingSignup.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
    

void HandlingOfCommandSignup::signup_user(vector<string>separated_input, ProgramData* program_data) {
      string email,username,password,age;
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == EMAIL)
            email = separated_input[i + 1];
        if(separated_input[i] == USERNAME)
            username = separated_input[i + 1];
        if(separated_input[i] == PASSWORD)
            password = separated_input[i + 1];
        if(separated_input[i] == AGE)
            age = separated_input[i + 1];
    }
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

void HandlingOfCommandSignup::input_signup(vector<string>separated_input, ProgramData* program_data,
string user_in_or_out) {
    error_cheaking_signup.cheak_input_for_signup(separated_input, program_data, user_in_or_out);
    signup_user(separated_input, program_data);
    cout << OK << "\n";
}

