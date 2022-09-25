#include "Publisher.h"
#include "Films.h"
#include "Customer.h"
#include "Exception.h"
#include "define.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Publisher::Publisher(string _email, string _username, string _password, string _age, int _id)
    : Customer(_email, _username, _password, _age, _id) {
        money_of_selling_films = 0;
    }

void Publisher::add_film(Films * new_film) {
    films.push_back(new_film);
}

int Publisher::cheak_film_id_exist_for_publisher(int id) {
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id)
            return i;
    }
    throw Permission_Denied_Exception();
}

void Publisher::change_year(string _year, int i) {
    films[i]->set_year(_year);
}

void Publisher::change_length(string _length, int i) {
    films[i]->set_length(_length);
}

void Publisher::change_name(string _name, int i) {
    films[i]->set_name(_name);
}

void Publisher::change_summery(string _summery, int i) {
    films[i]->set_summery(_summery);
}

void Publisher::change_director(string _director, int i) {
    films[i]->set_director(_director);
}

void Publisher::add_followers(int id, string username, string email) {
    string follower_id = to_string(id);
    followers.push_back(vector<string>());
    int size_of_row = followers.size();
    followers[size_of_row - 1].push_back(follower_id);
    followers[size_of_row - 1].push_back(username);
    followers[size_of_row - 1].push_back(email);
}
 
void Publisher::notification_you_followed(string username, int id) {
    publisher_notifications.push_back(vector<string> ());
    string follower_id = to_string(id);
    int size_of_row = publisher_notifications.size();
    publisher_notifications[size_of_row - 1].push_back(FOLLOWE);
    publisher_notifications[size_of_row - 1].push_back(username);
    publisher_notifications[size_of_row - 1].push_back(follower_id);
}

vector<vector<string> > Publisher::get_followers() {
    return followers;
}

vector<Films*> Publisher::get_films() {
    return films;
}

void Publisher::add_to_film_bought(int id) {
    for(int i = 0; i < films_of_publisher_that_bought.size(); i++) {
        if(films_of_publisher_that_bought[i][0] == id) {
            films_of_publisher_that_bought[i][1] += 1;
            return;
        }
    }
    films_of_publisher_that_bought.push_back(vector<int>());
    int size_of_row = films_of_publisher_that_bought.size();
    films_of_publisher_that_bought[size_of_row - 1].push_back(id);
    films_of_publisher_that_bought[size_of_row - 1].push_back(1);
}

vector<vector<int> > Publisher::get_films_of_publisher_that_bought() {
    return films_of_publisher_that_bought;
}

void Publisher::notification_rote_and_comment_and_buy_film(string customer_name, int customer_id,
string name_of_film, string film_id, string rote_commend_buy) {
    publisher_notifications.push_back(vector<string>());
    int size_of_row = publisher_notifications.size();
    if(rote_commend_buy == ROTE)
        publisher_notifications[size_of_row - 1].push_back(ROTE);
    if(rote_commend_buy == COMMENT)
        publisher_notifications[size_of_row - 1].push_back(COMMENT);
    if(rote_commend_buy == BUY_FILM)
        publisher_notifications[size_of_row - 1].push_back(BUY_FILM);
    publisher_notifications[size_of_row - 1].push_back(customer_name);
    publisher_notifications[size_of_row - 1].push_back(to_string(customer_id));
    publisher_notifications[size_of_row - 1].push_back(name_of_film);
    publisher_notifications[size_of_row - 1].push_back(film_id);
}

void Publisher::add_to_film_money(int time_of_bought, float rate, int price) {
    if( rate < 5)
        money_of_selling_films += (EIGHT/HUNDERED) * price * time_of_bought;
    if ((5 <= rate) && (rate < EIGHT))
        money_of_selling_films += (NINETY/HUNDERED) * price * time_of_bought;
    if( rate >= EIGHT)
        money_of_selling_films += (NINTY_FIVE/HUNDERED) * price * time_of_bought;
}
