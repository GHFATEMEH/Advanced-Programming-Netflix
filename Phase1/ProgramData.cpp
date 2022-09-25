#include "ProgramData.h"
#include "Films.h"
#include "Publisher.h"
#include "Customer.h"
#include "Exception.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

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
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id)
            return films[i];
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
