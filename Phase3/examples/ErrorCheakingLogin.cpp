#include "ErrorCheakingLogin.h"
#include "ProgramData.h"
#include "../server/server.hpp"

#include <vector>
#include <string>

using namespace std;

void ErrorCheakingLogin::cheak_password_and_user(string username, string password,
ProgramData* program_data) {
    vector<vector<string> > username_password = program_data->get_username_password();
    for(int i = 0; i < username_password.size(); i++){
        if((username_password[i][0] == username) &&
        (username_password[i][1] == password)){
            program_data->set_username_in_system(username);
            return;
        }
    }
    throw Server::Exception("Bad Request : Your username or password is not correct.");;
}

void ErrorCheakingLogin::cheak_all_error_for_login(string username, string password,
ProgramData* program_data) {
    cheak_password_and_user(username, password, program_data);
}