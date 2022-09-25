#ifndef HANDLING_OF_COMMAND_LOGIN
#define HANDLING_OF_COMMAND_LOGIN

#include <vector>
#include <string>

class ProgramData;

class HandlingOfCommandLogin {
public:
    void cheak_password_and_user(std::vector<std::string>separated_input,
    ProgramData* program_data);
    void cheak_login_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_login(std::vector<std::string>separated_input);
    void cheak_input_for_login(std::vector<std::string>separated_input,
    ProgramData* program_data);
};
#endif