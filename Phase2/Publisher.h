#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Customer.h"

#include <vector>
#include <string>

class Films;
class ProgramData;

class Publisher : public Customer {
public:
    Publisher(std::string _email, std::string _username, std::string _password, std::string _age
    , int id);
    void add_film(Films * new_film);
    int cheak_film_id_exist_for_publisher(int id);
    void change_year(std::string _year, int i);
    void change_length(std::string _length, int i);
    void change_name(std::string _name, int i);
    void change_summary(std::string _summary, int i);
    void change_director(std::string _director, int i);
    void add_followers(int id, std::string username, std::string email);
    void notification_you_followed(std::string username, int id);
    std::vector<std::vector<std::string> > get_followers();
    std::vector<Films*> get_films();
    void add_to_film_bought(int id, int price_of_film, int rate);
    std::vector<std::vector<int> > get_films_of_publisher_that_bought();
    void notification_rate_and_comment_and_buy_film(std::string customer_name, int customer_id,
    std::string name_of_film, std::string film_id, std::string rate_commend_buy);
    void add_to_film_money(int rate, int price, ProgramData* program_data, int i);
    int get_money_of_selling_films();
    std::vector<std::vector<std::string> > get_publisher_notifications();

private:
    int money_of_selling_films;
    std::vector<Films*>films;
    std::vector<std::vector<std::string> > followers;
    std::vector<std::vector<std::string> > publisher_notifications;
    std::vector<std::vector<int> > films_of_publisher_that_bought;
};
#endif