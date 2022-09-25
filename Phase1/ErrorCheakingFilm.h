#ifndef ERROR_CHEAKING_FILM
#define ERROR_CHEAKING_FILM

#include <string>
#include <vector>

class ProgramData;

class ErrorCheakingFilm {
public:
    bool cheak_id_is_digit(std::string film_id);
    void cheak_film_id_exist(std::string id, ProgramData* program_data);
    void cheak_all_error_film(std::string film_id, ProgramData* program_data);
    void cheak_number_of_input_add_film(std::vector<std::string>separated_input);
    void cheak_film_format(std::vector<std::string>separated_input);
    void cheak_customer_in(ProgramData* program_data);
    void cheak_publisher_in(ProgramData* program_data);
};
#endif