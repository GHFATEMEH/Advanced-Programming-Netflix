#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
public:
    Customer(std::string _email, std::string _username, std::string _password, std::string _age,
    int _id);
    std::string get_username();
    void followe_publisher(int id);
    int get_id();
    std::string get_email();
    std::vector<int> get_list_of_publisher_followed();
    void notification_register_new_film(std::string publisher_username, int publisher_id);
    void add_to_money(int _money);
    int get_money();
    void save_bought_films(int id);
    void reduce_money_after_payed(int film_price);
    std::vector<int> get_films_that_customer_bought();
    void set_customer_notifications(std::string publisher_username, std::string publisher_id,
    std::string content, std::string customer_id);
    std::vector<std::vector<std::string> > set_customer_notifications();
    std::vector<std::vector<std::string> > get_customer_notifications();
private:
    int id;
    int money;
    std::string email;
    std::string username;
    std::string password;
    std::string age;
    std::vector<int> list_of_publisher_followed;
    std::vector<std::vector<std::string> > customer_notifications;
    std::vector<int> films_that_customer_bought;
};
#endif