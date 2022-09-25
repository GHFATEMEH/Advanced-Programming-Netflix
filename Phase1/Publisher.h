#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Customer.h"

#include <vector>
#include <string>

class Films;

class Publisher : public Customer {
public:
    Publisher(std::string _email, std::string _username, std::string _password, std::string _age
    , int id);
    void add_film(Films * new_film);
    int cheak_film_id_exist_for_publisher(int id);
    void change_year(std::string _year, int i);
    void change_length(std::string _length, int i);
    void change_name(std::string _name, int i);
    void change_summery(std::string _summery, int i);
    void change_director(std::string _director, int i);
    void add_followers(int id, std::string username, std::string email);
    void notification_you_followed(std::string username, int id);
    std::vector<std::vector<std::string> > get_followers();
    std::vector<Films*> get_films();
    void add_to_film_bought(int id);
    std::vector<std::vector<int> > get_films_of_publisher_that_bought();
    void notification_rote_and_comment_and_buy_film(std::string customer_name, int customer_id,
    std::string name_of_film, std::string film_id, std::string rote_commend_buy);
    void add_to_film_money(int time_of_bought, float rate, int price);
private:
    int money_of_selling_films;
    std::vector<Films*>films;
    std::vector<std::vector<std::string> > followers;
    std::vector<std::vector<std::string> > publisher_notifications;
    std::vector<std::vector<int> > films_of_publisher_that_bought;
};
#endif