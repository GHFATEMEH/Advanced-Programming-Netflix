#ifndef ERROR_CHEAKING_LOGIN
#define ERROR_CHEAKING_LOGIN

#include <vector>
#include <string>

class ProgramData;

class ErrorCheakingLogin {
public:
    void cheak_password_and_user(std::vector<std::string>separated_input,
    ProgramData* program_data);
    void cheak_login_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_login(std::vector<std::string>separated_input);
    void cheak_all_error_for_login(std::vector<std::string>separated_input,
    ProgramData* program_data, std::string user_in_or_out);
    void cheak_user_in_system(std::string user_in_or_out);
    bool cheak_login_for_admin(std::vector<std::string>separated_input,
    ProgramData* program_data);
};
#endif