#include "ErrorCheakingFilm.h"
#include "ProgramData.h"
#include "define.h"
#include "../server/server.hpp"

using namespace std;

void ErrorCheakingFilm::cheak_user_in(ProgramData* program_data) {
    if(program_data->get_be_login_or_signup_for_handling_command() == OUT)
        throw Server::Exception("Bad Request : This username did not login before.");
}

void ErrorCheakingFilm::cheak_type_of_user(ProgramData* program_data) {
    if(program_data->get_user_in_system() == CUSTOMER)
        throw Server::Exception
        ("Permission denied : This command is for publisher ,you can't use it.");
}

void ErrorCheakingFilm::cheak_all_error_film(ProgramData* program_data) {
    cheak_user_in(program_data);
    cheak_type_of_user(program_data);
}

