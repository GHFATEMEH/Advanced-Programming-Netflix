#ifndef PROGRAM_DATA_H
#define PROGRAM_DATA_H

#include <vector>
#include <string>

class Films;
class Publisher;
class Customer;

class ProgramData {
public:
    ProgramData();
    void add_new_film(Films* new_film);
    void add_new_publisher(Publisher* new_publisher);
    void add_new_customer(Customer* new_customer);
    std::vector<std::vector<std::string> > get_username_password();
    void set_username_password(std::string username, std::string password);
    Publisher* find_publisher_in_system();
    Customer* find_customer_in_system();
    void set_type_of_person_in_system(std::string _type_of_user_in_system);
    int get_film_id();
    std::string get_type_of_user_in_system();
    std::string set_username_in_system(std::string username);
    std::vector<Publisher*> get_publisher();
    int get_customer_id();
    std::string get_user_in_system();
    std::vector<Customer*> get_customer();
    std::vector<Films*> get_film_vector();
    std::string get_username_in_system();
    void add_to_money_of_system(int film_price);
    void reduce_system_money(int money_to_reduce);
    std::string get_be_login_or_signup_for_handling_command();
    void set_be_login_or_signup_for_handling_command(std::string in_or_out);
private:
    std::vector<Films*>films;
    std::vector<Publisher*>publisher;
    std::vector<Customer*>customer;
    std::vector<std::vector<std::string> >username_password;
    std::string type_of_user_in_system;
    std::string username_in_system;
    std::string be_login_or_signup_for_handling_command;
};
#endif