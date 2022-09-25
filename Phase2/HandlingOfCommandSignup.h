#ifndef HANDLING_OF_COMMAND_SIGNUP
#define HANDLING_OF_COMMAND_SIGNUP

#include "ErrorCheakingSignup.h"

#include <vector>
#include <string>
class ProgramData;

class HandlingOfCommandSignup {
public:
    void input_signup(std::vector<std::string>separated_input, ProgramData* program_data,
    std::string user_in_or_out);
    void signup_user(std::vector<std::string>separated_input, ProgramData* program_data);
private:
    ErrorCheakingSignup error_cheaking_signup;
};
#endif