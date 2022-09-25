#ifndef ERROR_CHEAKING_FOLLOWERS
#define ERROR_CHEAKING_FOLLOWERS

#include <string>

class ProgramData;

class ErrorCheakingFollowers {
public:
    void cheak_customer_in(ProgramData* program_data);
    void cheak_publisher_in(ProgramData* program_data);
    void cheak_user_id_exist(ProgramData* program_data, std::string user_id);
};
#endif