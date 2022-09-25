#ifndef HANDLING_OF_COMMAND_FILM
#define HANDLING_OF_COMMAND_FILM

#include "ErrorCheakingFilm.h"

#include <string>
#include <vector>

class Publisher;
class ProgramData;
class Films;
class Customer;

class HandlingOfCommandFilm {
public:
    void input_film(ProgramData* program_data,
    std::vector<std::string> seperated_input);
    void add_film(Publisher* publisher, ProgramData* program_data,
    std::vector<std::string> seperated_input);
    void edit_film(Publisher* publisher, ProgramData* program_data,
    std::vector<std::string> seperated_input);
    int cheak_id_in_film(Publisher* publisher, ProgramData* program_data,
    std::vector<std::string>seperated_input, std::string type, int &id);
    void set_film_changes(int j, Publisher* publisher, std::vector<std::string>seperated_input);
    void delete_film(Publisher* publisher, ProgramData* program_data,
    std::vector<std::string> seperated_input);
    void notification_add_film_to_followers(std::string name, int id,
    ProgramData* program_data, Publisher* publisher);
    void show_film_detail(Customer* customer, std::vector<std::string>seperated_input,
    ProgramData* program_data, Publisher* publisher);
    void print_film_detail(std::vector<Films*>films, std::string film_id, int film_code);
    void print_reply_for_customer(std::vector<Customer*>customers_in_system,
    std::vector<std::vector<std::string> >comments_of_film, int i, int &counter);
    void print_reply_for_publisher(std::vector<std::vector<std::string> >comments_of_film,
    int i, int &counter, std::vector<Publisher*> publisher_in_system);
    void print_comment(std::vector<Films*>films, int film_code, Customer* customer,
    ProgramData* program_data, Publisher* publisher);
    void print_recommend_film(std::string film_id, std::vector<Films*>films, Customer* customer);
    void print_recommend_film(std::string film_id, ProgramData* program_data);
    void error_cheaking_add_film(ProgramData* program_data, std::vector<std::string>seperated_input);
private:
    ErrorCheakingFilm error_cheaking_film;
};
#endif