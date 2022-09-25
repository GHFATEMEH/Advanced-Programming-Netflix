#ifndef ERROR_CHEAKING_SIGNUP
#define ERROR_CHEAKING_SIGNUP

#include <string>

class ProgramData;

class ErrorCheakingSignup {
public:
    void cheak_input_for_signup(std::string username, std::string password,
    std::string publisher_or_not, ProgramData* program_data);
    void set_type_of_person_in_system_after_signup(std::string publisher_or_not,
    ProgramData* program_data);
    void cheak_user_and_save_it(std::string username, std::string password, ProgramData* program_data);
};
#endif