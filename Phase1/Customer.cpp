#include "Customer.h"
#include "define.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Customer::Customer(string _email, string _username, string _password, string _age, int _id) {
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    id = _id;
    money = 0;
}

string Customer::get_username() {
    return username;
}

void Customer::followe_publisher(int id) {
    list_of_publisher_followed.push_back(id);
}

int Customer::get_id() {
    return id;
}

string Customer::get_email() {
    return email;
}

vector<int> Customer::get_list_of_publisher_followed() {
    return list_of_publisher_followed;
}

void Customer::notification_register_new_film(string publisher_username, int publisher_id) {
    string id_of_publisher = to_string(publisher_id);
    customer_notifications.push_back(vector<string>());
    int size_of_row = customer_notifications.size();
    customer_notifications[size_of_row - 1].push_back(REGISTER_FILM);
    customer_notifications[size_of_row - 1].push_back(publisher_username);
    customer_notifications[size_of_row - 1].push_back(id_of_publisher);
}

void Customer::add_to_money(int _money) {
    money += _money;
}

int Customer::get_money() {
    return money;
}

void Customer::save_bought_films(int id) {
    films_that_customer_bought.push_back(id);
}

void Customer::reduce_money_after_payed(int film_price) {
    int money = money - film_price;
}

vector<int> Customer::get_films_that_customer_bought() {
    return films_that_customer_bought;
}

void Customer::set_customer_notifications(string publisher_username, string publisher_id,
string content, string customer_id) {
    customer_notifications.push_back(vector<string>());
    int size_of_row = customer_notifications.size();
    customer_notifications[size_of_row - 1].push_back(CONTENT);
    customer_notifications[size_of_row - 1].push_back(publisher_username);
    customer_notifications[size_of_row - 1].push_back(publisher_id);
    customer_notifications[size_of_row - 1].push_back(content);
    customer_notifications[size_of_row - 1].push_back(customer_id);
}

vector<vector<string> > Customer::get_customer_notifications() {
    return customer_notifications;
}
