#ifndef ERROR_CHEAKING_SIGNUP
#define ERROR_CHEAKING_SIGNUP

#include <vector>
#include <string>

class ProgramData;

class ErrorCheakingSignup {
public:
    void cheak_input_for_signup(std::vector<std::string>separated_input, ProgramData* program_data);
    void cheak_number_of_input_signup(std::vector<std::string>separated_input);
    void set_type_of_person_in_system_after_signup(std::vector<std::string>separated_input,
    ProgramData* program_data);
    void cheak_user_and_save_it(std::vector<std::string>separated_input, ProgramData* program_data);
    void cheak_signup_format(std::vector<std::string>separated_input);
    void cheak_email_format(std::vector<std::string>separated_input);
};
#endif