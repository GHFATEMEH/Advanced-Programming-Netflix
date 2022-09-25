#ifndef HANDLING_OF_COMMAND_FILM
#define HANDLING_OF_COMMAND_FILM

#include "ErrorCheakingFilm.h"
#include <string>
#include <map>
#include <vector>

class ProgramData;
class Films;
class Customer;

class HandlingOfCommandFilm {
public:
    void add_film(std::string year, std::string length, std::string price, std::string name,
    std::string summary, std::string director, ProgramData* program_data, std::string rate);
    void print_publisher_films_filter_director(std::vector<Films*>films, 
    std::string director_name, std::map<std::string, std::string> &context);
    void print_films(std::vector<Films*>films, std::map<std::string, std::string> &context);
    std::vector<Films*> films_that_did_not_bought(Customer* customer, std::vector<Films*>films, 
    std::vector<Films*>films_bought, std::map<std::string, std::string> &context);
    void find_films_that_can_buy(Customer* customer, std::vector<Films*>
    films_that_did_not_bought, std::map<std::string, std::string> &context);
    void print_film_details(std::vector<Films*>films, std::string id,
    std::map<std::string, std::string> &context);
    void print_films_did_not_bought_and_can_buy(Customer* customer, std::vector<Films*>films,
    std::vector<Films*>films_bought, std::map<std::string, std::string> &context);
    void print_recommended_movies(std::vector<Films*>films, ProgramData* program_data,
    std::map<std::string, std::string> &context, std::string id);
    void delete_film_id_customer_saw(std::vector<Films*>&films_exist, std::string id);
    void print_recommended_film_details(std::vector<Films*>film, std::map<std::string, 
    std::string> &context, std::string id);
    int find_film_and_add_comment(std::string _id, std::string comment, std::vector<Films*>film);
    void add_and_show_comment(std::string _id, ProgramData* program_data,
    std::map<std::string, std::string> &context, std::string comment);
private:
    ErrorCheakingFilm error_cheaking_film;
};
#endif