#ifndef ERROR_CHEAKING_LOGIN
#define ERROR_CHEAKING_LOGIN

#include <string>

class ProgramData;

class ErrorCheakingLogin {
public:
    void cheak_password_and_user(std::string username, std::string password,
    ProgramData* program_data);
    void cheak_all_error_for_login(std::string username, std::string password,
    ProgramData* program_data);
};
#endif