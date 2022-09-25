#include "Films.h"
#include "define.h"
#include <vector>
#include <string>
#include <sstream> 
#include <iostream>

using namespace std;

Films::Films(int _id, string _year, string _length, string _price,
    string _name, string _summery, string _director, string _exist_or_delete) {
    id = _id;
    year = _year;
    length = _length;
    price = _price;
    name = _name;
    summery = _summery;
    director = _director;
    exist_or_delete = _exist_or_delete;
    rate = 0;
}

int Films::get_id(){
    return id;
}

void Films::set_year(string _year) {
    year = _year;
}

void Films::set_length(string _length) {
    length = _length;
}

void Films::set_name(string _name) {
    name = _name;
}

void Films::set_summery(string _summery) {
    summery = _summery;
}

void Films::set_director(string _director) {
    director = _director;
}

void Films::delete_film() {
    exist_or_delete = DELETE_FILM;
}

int Films::get_price() {
    int price_of_film ;
    stringstream film_price(price); 
    film_price >> price_of_film;
    return price_of_film;
}

string Films::get_name() {
    return name;
}

string Films::get_exist_or_delete() {
    return exist_or_delete;
}

void Films::set_customers_rote_to_film(int rote, int customer_id) {
    for(int i = 0; i < customers_rote_to_film.size(); i++) {
        if(customers_rote_to_film[i][0] == customer_id) {
            customers_rote_to_film[i][1] = rote;
            return;
        }
    }
    customers_rote_to_film.push_back(vector<int>());
    int size_of_row = customers_rote_to_film.size();
    customers_rote_to_film[size_of_row - 1].push_back(customer_id);
    customers_rote_to_film[size_of_row - 1].push_back(rote);
}

void Films::set_rote() {
    int number_of_rote = customers_rote_to_film.size();
    int sum_of_rote = 0;
    for(int i=0;i<customers_rote_to_film.size();i++){
        sum_of_rote += customers_rote_to_film[i][1];
    rate = (sum_of_rote/number_of_rote);
    }
}

void Films::set_comments_of_film(string content, int customer_id) {
    comments_of_film.push_back(vector<string>());
    int comments_size = comments_of_film.size();
    string comments_id = to_string(comments_size);
    string id = to_string(customer_id);
    comments_of_film[comments_size - 1].push_back(comments_id);
    comments_of_film[comments_size - 1].push_back(id);
    comments_of_film[comments_size - 1].push_back(content);
    comments_of_film[comments_size - 1].push_back(EXIST);
}

void  Films::delete_notification_film(string comment_id) {
    for(int i=0;i<comments_of_film.size();i++) {
        if(comments_of_film[i][0] == comment_id) {
            comments_of_film[i][3] = DELETE_FILM;
        return;
        }
    }
}

float Films::get_rate() {
    return rate;
}

string Films::get_length() {
    return length;
}

string Films::get_year() {
    return year;
}

string Films::get_director() {
    return director;
}

vector<vector<string> > Films::get_comments_of_film() {
    return comments_of_film;
}

string Films::get_summery() {
    return summery;
}


