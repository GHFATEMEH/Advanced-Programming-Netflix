#ifndef HANDLING_OF_COMMAND_LOGIN
#define HANDLING_OF_COMMAND_LOGIN

#include "ErrorCheakingLogin.h"

#include <vector>
#include <string>

class ProgramData;

class HandlingOfCommandLogin {
public:
    void cheak_input_for_login(std::vector<std::string>separated_input,
    ProgramData* program_data, std::string user_in_or_out);
    void set_type_of_person_in_system_after_login(std::vector<std::string>separated_input,
    ProgramData* program_data);
private:
    ErrorCheakingLogin error_cheaking_login;
};
#endif