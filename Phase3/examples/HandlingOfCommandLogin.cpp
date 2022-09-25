#include "HandlingOfCommandLogin.h"
#include "define.h"
#include "ProgramData.h"
#include "ErrorCheakingLogin.h"
#include "Publisher.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void HandlingOfCommandLogin::set_type_of_person_in_system_after_login(string username,
ProgramData* program_data) {
    vector<Publisher*>publisher = program_data->get_publisher();
    for(int i = 0; i < publisher.size(); i++) {
        if(publisher[i]->get_username() == username) {
            program_data->set_type_of_person_in_system(PUBLISHER);
            return;
        }
    }
    program_data->set_type_of_person_in_system(CUSTOMER);
}

void HandlingOfCommandLogin::cheak_input_for_login(string username, string password,
ProgramData* program_data) {
    error_cheaking_login.cheak_all_error_for_login(username, password, program_data);
    set_type_of_person_in_system_after_login(username, program_data);
    program_data->set_be_login_or_signup_for_handling_command(IN);
    cout << OK << "\n";
}

