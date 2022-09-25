#ifndef HANDLING_OF_COMMAND_REPLIES
#define HANDLING_OF_COMMAND_REPLIES

#include "ErrorCheakingRepliesAndDeleteComments.h"

#include <string>
#include <vector>

class ProgramData;
class Publisher;

class HandlingOfCommandReplies {
public:
    void input_reply(std::vector<std::string>separated_input, ProgramData* program_data);
    void add_notification_reply(Publisher* publisher, std::string film_id,
    ProgramData* program_data, std::string comment_id, std::string content);
    std::string find_customer_id_that_comment_film(std::string comment_id,
    std::string film_id, ProgramData* program_data);
    void set_notification_for_customer(std::string customer_id,
    std::string publisher_name, std::string publisher_id, ProgramData* program_data,
    std::string content);
private:
    ErrorCheakingRepliesAndDeleteComments error_cheaking_replies;
};
#endif