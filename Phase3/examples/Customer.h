#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Films;

class Customer {
public:
    Customer(std::string _email, std::string _username, std::string _password, std::string _age,
    int _id);
    std::string get_username();
    int get_id();
    std::string get_email();
    void add_to_money(int _money);
    int get_money();
    void save_bought_films(int _id, std::string _year, std::string _length, std::string _price,
    std::string _name, std::string _summary, std::string _director, std::string exist_or_delete,
    std::string _rate);
    void reduce_money_after_paid(int film_price);
    std::vector<Films*> get_films_that_customer_bought();
private:
    int id;
    int money;
    std::string email;
    std::string username;
    std::string password;
    std::string age;
    std::vector<Films*> films_that_customer_bought;
};
#endif