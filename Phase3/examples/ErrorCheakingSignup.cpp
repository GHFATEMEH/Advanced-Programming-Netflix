#include "ErrorCheakingSignup.h"
#include "define.h"
#include "ProgramData.h"
#include "../server/server.hpp"

#include <string>

using namespace std;

void ErrorCheakingSignup::set_type_of_person_in_system_after_signup(string publisher_or_not,
ProgramData* program_data) {
    if(publisher_or_not == TRUE_ANSWER)
        program_data->set_type_of_person_in_system(PUBLISHER);
    if(publisher_or_not == FALSE_ANSWER)
        program_data->set_type_of_person_in_system(CUSTOMER);
}

void ErrorCheakingSignup::cheak_user_and_save_it(string username, string password,
ProgramData* program_data) {
    for(int i = 0; i < program_data->get_username_password().size(); i++){
        if(program_data->get_username_password()[i][0] == username)
            throw Server::Exception("Bad Request : This username has already signup.");
    }
    program_data->set_username_password(username, password);
}

void ErrorCheakingSignup::cheak_input_for_signup(string username, string password,
string publisher_or_not, ProgramData* program_data) {
    cheak_user_and_save_it(username, password, program_data);
    set_type_of_person_in_system_after_signup(publisher_or_not, program_data);
}
