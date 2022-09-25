#ifndef HANDLING_OF_COMMAND_COMMENTS
#define HANDLING_OF_COMMAND_COMMENTS

#include "ErrorCheakingRate.h"
#include "ErrorCheakingRepliesAndDeleteComments.h"
#include "ErrorCheakingComments.h"

#include <string>
#include <vector>

class ProgramData;
class Customer;
class Publisher;

class HandlingOfCommandComments {
public:
    void input_comments(std::vector<std::string> separated_input, ProgramData* program_data);
    void add_comments(std::vector<std::string>separated_input,
    ProgramData *program_data, std::string id, int customer_id);
    void add_notification_for_comment(std::string film_id, Customer* customer,
    ProgramData* program_data);
    int find_publisher_with_this_id(ProgramData* program_data, std::string film_id);
    std::string find_name_of_film(std::string film_id, ProgramData* program_data);
    void add_comment_notification(ProgramData* program_data,std::string name_of_film,
    std::string film_id, int publisher_code, std::string customer_name,int customer_id); 
    void post_comment(std::string id, ProgramData* program_data,
    std::vector<std::string>separated_input, Customer* customer, Publisher* publisher);
    void delete_comment(std::string id, ProgramData* program_data,
    std::vector<std::string>separated_input, Publisher* publisher);
    void delete_comment_from_customer_comments(std::string id, Publisher* publisher,
    std::vector<std::string>separated_input);
    void cheak_all_error_for_post_comments(std::vector<std::string>separated_input,
    std::string id, ProgramData* program_data);
    void add_notification_for_comment_for_publisher(std::string film_id,Publisher* publisher,
    ProgramData* program_data);
    void error_cheaking_delete_comments(ProgramData* program_data, std::vector<std::string>
    separated_input, std::string id, Publisher* publisher);
private:
    ErrorCheakingComments error_cheaking_comments;
    ErrorCheakingRepliesAndDeleteComments error_cheaking_replie_and_delete_comments;

};
#endif