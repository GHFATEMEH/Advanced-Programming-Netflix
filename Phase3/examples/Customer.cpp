#include "Customer.h"
#include "define.h"
#include "Films.h"

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

int Customer::get_id() {
    return id;
}

string Customer::get_email() {
    return email;
}

void Customer::add_to_money(int _money) {
    money += _money;
}

int Customer::get_money() {
    return money;
}

void Customer::save_bought_films(int _id, string _year, string _length, string _price, string _name,
string _summary, string _director, string exist_or_delete, string _rate) {
    films_that_customer_bought.push_back(new Films(_id, _year, _length, _price, _name, _summary,
    _director, EXIST, _rate));
}

void Customer::reduce_money_after_paid(int film_price) {
    money = money - film_price;
}

vector<Films*> Customer::get_films_that_customer_bought() {
    return films_that_customer_bought;
}
