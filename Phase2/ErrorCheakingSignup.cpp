#include "ErrorCheakingSignup.h"
#include "Exception.h"
#include "define.h"
#include "ProgramData.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ErrorCheakingSignup::set_type_of_person_in_system_after_signup(vector<string>separated_input,
ProgramData* program_data) {
    for(int i = 0; i < separated_input.size(); i++){
        if(separated_input[i] == PUBLISHER){
            if(separated_input[i+1] == TRUE_ANSWER)
                program_data->set_type_of_person_in_system(PUBLISHER);
            else 
                program_data->set_type_of_person_in_system(CUSTOMER);
            return;
        }
    }
    program_data->set_type_of_person_in_system(CUSTOMER);
}

vector<string> find_user_and_password(vector<string>separated_input) {
    vector<string>saved_username_password(2);
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == USERNAME)
            saved_username_password[0] = separated_input[i+1];
        if(separated_input[i] == PASSWORD)
            saved_username_password[1] = separated_input[i+1];
    }
    return saved_username_password;
}

void ErrorCheakingSignup::cheak_user_and_save_it(vector<string>separated_input,
ProgramData* program_data) {
    vector<string>saved_usernames_and_passwords = find_user_and_password(separated_input);
    for(int i = 0; i < program_data->get_username_password().size(); i++){
        if(program_data->get_username_password()[i][0] == saved_usernames_and_passwords[0])
            throw Bad_Request_Exception();
    }
    program_data->set_username_password(saved_usernames_and_passwords);
}

void ErrorCheakingSignup::cheak_signup_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if ((separated_input[2*i + 1] == EMAIL) || (separated_input[2*i + 1] == USERNAME) ||
        (separated_input[2*i + 1] == PASSWORD) || (separated_input[2*i + 1] == AGE) ||
        (separated_input[2*i + 1] == PUBLISHER) || (separated_input[2*i + 1] == TRUE_ANSWER) ||
        (separated_input[2*i + 1] == FALSE_ANSWER))
        continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingSignup::cheak_number_of_input_signup(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if((number_of_input == ELEVEN) || (number_of_input == THIRTEEN))
        return;
    else
        throw Bad_Request_Exception();
}

string find_mail(vector<string>separated_input) {
    string email;
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == EMAIL) {
            email = separated_input[i + 1];
            return email;
        }
    }
    return email;
}

void ErrorCheakingSignup::cheak_email_format(vector<string>separated_input) {
    string mail = find_mail(separated_input);
    for(int i = 0; i < mail.size(); i++) {
        if(mail[i] == '@') {
            for(int j = i + 1; j < mail.size(); j++) {
                if(mail[j] == DOT_CHAR)
                    return;
            }
            throw Bad_Request_Exception();
        }
    }
    throw Bad_Request_Exception();
}

void ErrorCheakingSignup::cheak_user_is_in_or_not(string user_in_or_out) {
    if(user_in_or_out == IN)
        throw Bad_Request_Exception();
}

void ErrorCheakingSignup::cheak_admin_can_not_signup(vector<string>separated_input) {
    string username, password;
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == USERNAME)
            username = separated_input[i + 1];
        if(separated_input[i] == PASSWORD)
            password = separated_input[i + 1];
    }
    if((username == ADMIN) && (password == ADMIN))
        throw Bad_Request_Exception();
}

void ErrorCheakingSignup::cheak_input_for_signup(vector<string>separated_input,
ProgramData* program_data, string user_in_or_out) {
    cheak_user_is_in_or_not(user_in_or_out);
    cheak_number_of_input_signup(separated_input);
    cheak_signup_format(separated_input);
    cheak_email_format(separated_input);
    cheak_admin_can_not_signup(separated_input);
    cheak_user_and_save_it(separated_input, program_data);
    set_type_of_person_in_system_after_signup(separated_input, program_data);
}
