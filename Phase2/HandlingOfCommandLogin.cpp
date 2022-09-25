#include "HandlingOfCommandLogin.h"
#include "define.h"
#include "ProgramData.h"
#include "ErrorCheakingLogin.h"
#include "Publisher.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void HandlingOfCommandLogin::set_type_of_person_in_system_after_login(vector<string>separated_input,
ProgramData* program_data) {
    string username = separated_input[4];
    vector<Publisher*>publisher = program_data->get_publisher();
    for(int i = 0; i < publisher.size();i++) {
        if(publisher[i]->get_username() == username) {
            program_data->set_type_of_person_in_system(PUBLISHER);
            return;
        }
    }
    program_data->set_type_of_person_in_system(CUSTOMER);
}

void HandlingOfCommandLogin::cheak_input_for_login(vector<string>separated_input,
ProgramData* program_data, string user_in_or_out) {
    error_cheaking_login.cheak_all_error_for_login(separated_input, program_data, user_in_or_out);
    if(program_data->get_username_in_system() == ADMIN) {
        cout << OK << "\n";
        return;
    }
    set_type_of_person_in_system_after_login(separated_input, program_data);
    cout << OK << "\n";
}

