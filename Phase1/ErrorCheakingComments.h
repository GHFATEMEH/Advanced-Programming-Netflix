#ifndef ERROR_CHEAKING_COMMENTS_H
#define ERROR_CHEAKING_COMMENTS_H

#include "ErrorCheakingFilm.h"

#include <string>
#include <vector>

class ProgramData;
class Customer;

class ErrorCheakingComments : public ErrorCheakingFilm {
public:
    void cheak_film_has_bought_for_post(std::string id, ProgramData* program_data);
    void cheak_delete_comments_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_delete_comments(std::vector<std::string>separated_input);
    void cheak_film_has_bought(std::string id, ProgramData* program_data);
    void cheak_post_comments_format(std::vector<std::string>separated_input);
    void cheak_number_of_input_post_comments(std::vector<std::string>separated_input);
};
#endif