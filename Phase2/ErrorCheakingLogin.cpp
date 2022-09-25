#include "ErrorCheakingLogin.h"
#include "Exception.h"
#include "define.h"
#include "ProgramData.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> find_user_and_password_for_login(vector<string>separated_input){
    vector<string>save_username_password(2);
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == USERNAME)
            save_username_password[0] = separated_input[i + 1];
        if(separated_input[i] == PASSWORD)
            save_username_password[1] = separated_input[i + 1];
    }
    return save_username_password;
}

void ErrorCheakingLogin::cheak_password_and_user(vector<string>separated_input,
ProgramData* program_data) {
    string username_in;
    vector<string>saved_usernames_and_passwords = find_user_and_password_for_login(separated_input);
    vector<vector<string> > username_password = program_data->get_username_password();
    for(int i = 0; i < username_password.size(); i++){
        if((username_password[i][0] == saved_usernames_and_passwords[0]) &&
        (username_password[i][1] == saved_usernames_and_passwords[1])){
            username_in = saved_usernames_and_passwords[0];
            program_data->set_username_in_system(username_in);
            return;
        }
    }
    throw Bad_Request_Exception();
}

void ErrorCheakingLogin::cheak_login_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if((separated_input[2*i + 1] == USERNAME) || (separated_input[2*i +1] == PASSWORD))
            continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingLogin::cheak_number_of_input_login(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == SEVEN)
        return;
    else
        throw Bad_Request_Exception();
}

void ErrorCheakingLogin::cheak_user_in_system(string user_in_or_out) {
    if(user_in_or_out == IN)
        throw Bad_Request_Exception();
}

bool ErrorCheakingLogin::cheak_login_for_admin(vector<string>separated_input,
ProgramData* program_data) {
    string username, password;
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == USERNAME)
            username = separated_input[i + 1];
        if(separated_input[i] == PASSWORD)
            password = separated_input[i + 1];
    }
    if((username == ADMIN) && (password == ADMIN)) {
        program_data->set_username_in_system(ADMIN);
        return true;
    }
    return false;
}

void ErrorCheakingLogin::cheak_all_error_for_login(vector<string>separated_input,
ProgramData* program_data, string user_in_or_out) {
    cheak_user_in_system(user_in_or_out);
    cheak_number_of_input_login(separated_input);
    cheak_login_format(separated_input);
    if(cheak_login_for_admin(separated_input, program_data))
        return;
    cheak_password_and_user(separated_input, program_data);
}