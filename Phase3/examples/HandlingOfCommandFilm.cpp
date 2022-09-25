#include "HandlingOfCommandFilm.h"
#include "Publisher.h"
#include "ProgramData.h"
#include "Films.h"
#include "define.h"
#include "Customer.h"
#include "ErrorCheakingFilm.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void HandlingOfCommandFilm::add_film(string year, string length, string price, string name,
string summary, string director, ProgramData* program_data, string rate) {
    error_cheaking_film.cheak_all_error_film(program_data);
    Publisher* publisher = program_data->find_publisher_in_system();
    int id = program_data->get_film_id();
    Films* new_film = new Films(id, year, length, price, name, summary, director, EXIST, rate);
    publisher->add_film(new_film);
    program_data->add_new_film(new_film);
    cout << OK << "\n";
}

void HandlingOfCommandFilm::print_publisher_films_filter_director(vector<Films*>films,
string director_name, map<string, string> &context) {
    vector<Films*> filter_films;
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_director() == director_name)
            filter_films.push_back(films[i]);
    }
    print_films(filter_films, context);   
}

vector<Films*> delete_deleted_films(vector<Films*>films) {
    vector<Films*>film;
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_exist_or_delete() == EXIST)
            film.push_back(films[i]);
    }
    return film;
}

void HandlingOfCommandFilm::print_films(vector<Films*>films, map<string, string> &context) {
    string information;
    string  number_of_film;
    vector<Films*>film = delete_deleted_films(films);
    context["size_of_context"] = to_string(film.size());
    for(int i = 0; i < film.size(); i++){
        number_of_film = to_string(i);
        information = film[i]->get_name() + SPACELINE + PRICE + SPACE +
        ":" + SPACE + to_string(film[i]->get_price()) + SPACELINE + YEAR + SPACE + ":" + SPACE +
        film[i]->get_year() + SPACELINE + LENGTH + SPACE + ":" + SPACE + film[i]->get_length() +
        SPACELINE + RATE + SPACE + ":" + SPACE + film[i]->get_rate() + SPACELINE + DIRECTOR +
        SPACE + ":" + SPACE + film[i]->get_director();
        context[number_of_film] = information;
        context[number_of_film + "id"] = to_string(film[i]->get_id());
    }
}

void HandlingOfCommandFilm::find_films_that_can_buy(Customer* customer, vector<Films*>
films_that_did_not_bought, map<string, string> &context) {
    int money = customer->get_money();
    vector<Films*>films;
    for(int i = 0; i < films_that_did_not_bought.size(); i++) {
        if(films_that_did_not_bought[i]->get_price() <= money)
            films.push_back(films_that_did_not_bought[i]);
    }
    print_films(films, context);
}

vector<Films*> HandlingOfCommandFilm::films_that_did_not_bought(Customer* customer,
vector<Films*>films, vector<Films*>films_bought, map<string, string> &context) {
    vector<Films*>films_that_not_bought;
    int counter;
    for(int i = 0; i < films.size(); i++) {
        counter = 0;
        for(int j = 0; j < films_bought.size(); j++) {
            if(films[i]->get_id() == films_bought[j]->get_id())
                break;
            else
                counter++;
        }
        if(counter == films_bought.size())
            films_that_not_bought.push_back(films[i]);
    }
    return films_that_not_bought;
}

void HandlingOfCommandFilm::print_films_did_not_bought_and_can_buy(Customer* customer,
vector<Films*>films, vector<Films*>films_bought, map<string, string> &context) {
    vector<Films*>films_that_not_bought = films_that_did_not_bought(customer, films, films_bought,
    context);
    find_films_that_can_buy(customer, films_that_not_bought, context);
}

void HandlingOfCommandFilm::print_film_details(vector<Films*>films, string id,
std::map<std::string, std::string> &context) {
    string information;
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == id) {
            information = films[i]->get_name() + SPACELINE + PRICE + SPACE +
            ":" + SPACE + to_string(films[i]->get_price()) + SPACELINE + YEAR + SPACE + ":" +
            SPACE + films[i]->get_year() + SPACELINE + LENGTH + SPACE + ":" + SPACE +
            films[i]->get_length() + SPACELINE + RATE + SPACE + ":" + SPACE + films[i]->get_rate()
            + SPACELINE + DIRECTOR + SPACE + ":" + SPACE + films[i]->get_director() + SPACELINE +
            SUMMARY + SPACE + ":" + SPACE + films[i]->get_summary();
            context["film"] = information;
        }
    }
}

void HandlingOfCommandFilm::delete_film_id_customer_saw(vector<Films*>&films_exist, string id) {
    vector<Films*>::iterator it;
    it = films_exist.begin(); 
    for(int i = 0; i < films_exist.size(); i++) {
        if(to_string(films_exist[i]->get_id()) == id)
            films_exist.erase(it + i);
    }
}

bool sortcolumn( const vector<int>& v1, const vector<int>& v2 ) { 
        return v1[1] > v2[1]; 
}

vector<vector<int> > sort_by_rate(vector<Films*>films_exist) {
    vector<vector<int> >film;
    for(int i = 0; i < films_exist.size(); i++) {
        film.push_back(vector<int>());
        film[i].push_back(films_exist[i]->get_id());
        film[i].push_back(stoi(films_exist[i]->get_rate()));
    }
    sort(film.begin(), film.end(),sortcolumn);
    return film;
}

int cheak_size_of_film(vector<vector<int> >film) {
    if((film.size() == FOUR) || (film.size() > FOUR))
        return FOUR;
    else
        return film.size();
}

void find_four_films(vector<Films*>films_exist, map<string, string> &context) {
    string number_of_film;
    vector<vector<int> > film = sort_by_rate(films_exist);
    int size = cheak_size_of_film(film);
    context["size_of_context"] = to_string(size);
    for(int i = 0; i < film.size(); i++) {
        number_of_film = to_string(i);
        if(i == FOUR)
            break;
        context[number_of_film] = to_string(film[i][0]);
    }
}

void HandlingOfCommandFilm::print_recommended_movies(vector<Films*>films, ProgramData* program_data,
map<string, string> &context, string id) {
    Customer* customer = program_data->find_customer_in_system();
    vector<Films*>films_bought = customer->get_films_that_customer_bought();
    vector<Films*>films_that_not_bought = films_that_did_not_bought(customer, films, films_bought,
    context);
    vector<Films*>films_exist = delete_deleted_films(films_that_not_bought);
    delete_film_id_customer_saw(films_exist, id);
    find_four_films(films_exist, context);
}

void HandlingOfCommandFilm::print_recommended_film_details(vector<Films*>film,
map<string, string> &context, string id) {
    string information;
    for(int i = 0; i < film.size(); i++) {
        if(to_string(film[i]->get_id()) == id) {
            information = film[i]->get_name() + SPACELINE + LENGTH + SPACE + ":" + SPACE + 
            film[i]->get_length() + SPACELINE + DIRECTOR + SPACE + ":" + SPACE + 
            film[i]->get_director();
            context["film"] = information;
        }
    }
}

int HandlingOfCommandFilm::find_film_and_add_comment(string _id, string comment,
vector<Films*>film) {
    for(int i = 0; i < film.size(); i++) {
        if(to_string(film[i]->get_id()) == _id) {
            film[i]->add_comment(comment);
            return i;
        }
    }
}

void HandlingOfCommandFilm::add_and_show_comment(string _id, ProgramData* program_data,
map<string, string> &context, string comment) {
    string information;
    string  number_of_film;
    vector<Films*>film = program_data->get_film_vector();
    int i = find_film_and_add_comment(_id, comment, film);
    context["size_of_context"] = to_string(film[i]->get_comment().size());
    for(int j = 0; j < film[i]->get_comment().size(); j++){
        number_of_film = to_string(j);
        information = film[i]->get_comment()[j];
        context[number_of_film] = information;
    }
}
