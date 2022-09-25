#include "ProgramData.h"
#include "Films.h"
#include "Publisher.h"
#include "Customer.h"
#include "Exception.h"
#include "FilmGraph.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

ProgramData::ProgramData() {
    money_of_system = 0;
    film_graph = new FilmGraph();
}

void ProgramData::add_new_film(Films* new_film) {
    films.push_back(new_film);
}

void ProgramData::add_new_publisher(Publisher* new_publisher) {
    publisher.push_back(new_publisher);
}

void ProgramData::add_new_customer(Customer* new_customer) {
    customer.push_back(new_customer);
}

vector<vector<string> > ProgramData::get_username_password() {
    return username_password;
}

void ProgramData::set_username_password(vector<string>saved_usernames_and_passwords) {
    username_password.push_back(vector<string>());
    int size_of_row = username_password.size();
    username_password[size_of_row-1].push_back(saved_usernames_and_passwords[0]);
    username_password[size_of_row-1].push_back(saved_usernames_and_passwords[1]);
}

void ProgramData::set_type_of_person_in_system(string _type_of_user_in_system) {
    type_of_user_in_system = _type_of_user_in_system;
}

Publisher* ProgramData::find_publisher_in_system() {
    for(int i = 0; i < publisher.size(); i++) {
        if(publisher[i]->get_username() == username_in_system)
            return publisher[i];
    }
}

Customer* ProgramData::find_customer_in_system() {
    for(int i = 0; i < customer.size(); i++) {
        if(customer[i]->get_username() == username_in_system)
            return customer[i];
    }
}

int ProgramData::get_film_id() {
    return films.size() + 1;
}

int ProgramData::get_customer_id() {
    return customer.size() + 1;
}

string ProgramData::get_type_of_user_in_system() {
    return type_of_user_in_system;
}

string ProgramData::set_username_in_system(string username) {
    username_in_system = username;
}

bool ProgramData::cheak_id_of_film_exist(int id) {
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id)
            return true;
    }
    throw Not_Found_Exception();
}

Films* ProgramData::get_film(int id) {
    Films* film;
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id) {
            film = films[i];
            return film;
        }
    }
}

vector<Publisher*> ProgramData::get_publisher() {
    return publisher;
}

string ProgramData::get_user_in_system() {
    return type_of_user_in_system;
}

vector<Customer*> ProgramData::get_customer() {
    return customer;
}

vector<Films*> ProgramData::get_film_vector() {
    return films;
}

std::string ProgramData::get_username_in_system() {
    return username_in_system;
}

void ProgramData::add_to_money_of_system(int film_price) {
    money_of_system += film_price;
}

void ProgramData::reduce_system_money(int money_to_reduce) {
    money_of_system = money_of_system - money_to_reduce;
}

int ProgramData::get_money_in_system() {
    return money_of_system;
}

void ProgramData::add_film_to_graph() {
    film_graph->add_film_to_graph();
}

void ProgramData::update_film_graph(vector<int>film_that_customer_bought) {
    film_graph->update_film_graph(film_that_customer_bought);
}

vector<vector<int> > ProgramData::find_recommend_film(int film_id) {
    return film_graph->find_recommend_film(film_id);
}