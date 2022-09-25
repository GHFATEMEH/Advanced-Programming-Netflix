#include "Films.h"
#include "define.h"

#include <vector>
#include <string>
#include <sstream> 

using namespace std;

Films::Films(int _id, string _year, string _length, string _price,
    string _name, string _summary, string _director, string _exist_or_delete, string _rate) {
    id = _id;
    year = _year;
    length = _length;
    price = _price;
    name = _name;
    summary = _summary;
    director = _director;
    exist_or_delete = _exist_or_delete;
    rate = _rate ;
}

int Films::get_id(){
    return id;
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

string Films::get_rate() {
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

string Films::get_summary() {
    return summary;
}

void Films::add_comment(string _comment) {
    comment.push_back(_comment);
}

vector<string> Films::get_comment() {
    return comment;
}


