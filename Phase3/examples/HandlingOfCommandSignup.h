#ifndef HANDLING_OF_COMMAND_SIGNUP
#define HANDLING_OF_COMMAND_SIGNUP

#include "ErrorCheakingSignup.h"

#include <string>

class ProgramData;

class HandlingOfCommandSignup {
public:
    void input_signup(ProgramData* program_data, std::string username, std::string password,
    std::string age, std::string publisher_or_not, std::string email);
    void signup_user(ProgramData* program_data, std::string username, std::string password,
    std::string age, std::string email);
private:
  ErrorCheakingSignup error_cheaking_signup;
};
#endif