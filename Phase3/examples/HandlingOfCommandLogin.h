#ifndef HANDLING_OF_COMMAND_LOGIN
#define HANDLING_OF_COMMAND_LOGIN

#include "ErrorCheakingLogin.h"

#include <string>

class ProgramData;

class HandlingOfCommandLogin {
public:
    void cheak_input_for_login(std::string username, std::string password, ProgramData* program_data);
    void set_type_of_person_in_system_after_login(std::string username, ProgramData* program_data);
private:
    ErrorCheakingLogin error_cheaking_login;
};
#endif