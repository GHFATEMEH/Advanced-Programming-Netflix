#include "ListOfFilmSorted.h"
#include "ProgramData.h"
#include "Publisher.h"
#include "define.h"
#include "Films.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void ListOfFilmSorted::save_films_property(vector<Films*>films, int i,
vector<vector<string> >&list_of_film_publishned) {
    list_of_film_publishned.push_back(vector<string>());
    int size_of_row = list_of_film_publishned.size();
    list_of_film_publishned[size_of_row-1].push_back(to_string(films[i]->get_id()));
    list_of_film_publishned[size_of_row-1].push_back(films[i]->get_name());
    list_of_film_publishned[size_of_row-1].push_back(films[i]->get_length());
    list_of_film_publishned[size_of_row-1].push_back(to_string(films[i]->get_price()));
    list_of_film_publishned[size_of_row-1].push_back(to_string(films[i]->get_rate()));
    list_of_film_publishned[size_of_row-1].push_back(films[i]->get_year());
    list_of_film_publishned[size_of_row-1].push_back(films[i]->get_director());
}

void ListOfFilmSorted::find_films_property(string type_of_property, Publisher* publisher,
vector<vector<string> >&list_of_film_publishned, string property, vector<Films*>all_films,
string type_of_string) {
    vector<Films*> search_film;
    if(type_of_string == PUBLISHER) 
        search_film = publisher->get_films();
    else 
        search_film = all_films;
    if(type_of_property == NAME) {
        for(int i = 0; i < search_film.size(); i++) {
            if(search_film[i]->get_name() == property){
                save_films_property(search_film, i, list_of_film_publishned);}
        }
    }
    if(type_of_property == LENGTH) {
        for(int i = 0; i < search_film.size(); i++) {
            if(search_film[i]->get_length() == property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }
    if(type_of_property == MIN_RATE) {
        for(int i = 0; i < search_film.size(); i++) {
            if(to_string(search_film[i]->get_rate()) >= property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }
    if(type_of_property == MIN_YEAR) {
        for(int i = 0; i < search_film.size(); i++) {
            if(search_film[i]->get_year() >= property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }
    if(type_of_property == PRICE) {
        for(int i = 0; i < search_film.size(); i++) {
            if(to_string(search_film[i]->get_price()) == property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }
    if(type_of_property == Max_YEAR) {
        for(int i = 0; i < search_film.size(); i++) {
            if(search_film[i]->get_year() <= property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }
    if(type_of_property == DIRECTOR) {
        for(int i = 0; i < search_film.size(); i++) {
            if(search_film[i]->get_director() == property)
                save_films_property(search_film, i, list_of_film_publishned);
        }
    }

}

void delete_property(vector<vector<string> >&list_of_film_publishned,
int i) {
    for(int k = 0; k < 7; k++)
        list_of_film_publishned[i].erase(list_of_film_publishned[i].begin() + k);
    list_of_film_publishned.erase(list_of_film_publishned.begin() + i);
}

void cheak_propertys_for_name(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input){
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][1] != seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }     
}

void cheak_propertys_for_lenght(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input){
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][2] != seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void cheak_propertys_for_min_rate(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input) {
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][4] < seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void cheak_propertys_for_min_year(int j, vector<vector<string> >&list_of_film_publishned,
vector<string>seperated_input){
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][5] < seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void cheak_propertys_for_max_year(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input) {
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][5] > seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void cheak_propertys_for_price(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input) {
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][3] != seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void cheak_propertys_for_director(int j,vector<vector<string> >
&list_of_film_publishned, vector<string>seperated_input) {
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        if(list_of_film_publishned[i][6] != seperated_input[j + 1])
            delete_property(list_of_film_publishned, i);
    }
}

void ListOfFilmSorted::sort_vector_of_propertys(int j,vector<vector<string> >&list_of_film_publishned, vector<string>seperated_input) {
    while(j < seperated_input.size()) {
        if(seperated_input[j] == NAME)
            cheak_propertys_for_name(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == LENGTH)
            cheak_propertys_for_lenght(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == MIN_RATE)
            cheak_propertys_for_min_rate(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == MIN_YEAR)
            cheak_propertys_for_min_year(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == PRICE)
            cheak_propertys_for_price(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == Max_YEAR)
            cheak_propertys_for_max_year(j, list_of_film_publishned, seperated_input);
        if(seperated_input[j] == DIRECTOR)
            cheak_propertys_for_director(j, list_of_film_publishned, seperated_input);
        j++;
    }
}

void find_property_in_vector(vector<vector<string> > list_of_film_publishned, int i, int j, string &id, string &name,
string &length, string &film_price, string &rate, string &production_year, string &film_director) {
    id = list_of_film_publishned[j][0];
    name = list_of_film_publishned[j][1];
    length = list_of_film_publishned[j][2];
    film_price = list_of_film_publishned[j][3];
    rate = list_of_film_publishned[j][4];
    production_year = list_of_film_publishned[j][5];
    film_director = list_of_film_publishned[j][6];
}

void sort_id_film(vector<vector<string> > &list_of_film_publishned, int i, int j) {
    string id, name, length, film_price, rate, production_year, film_director;
    find_property_in_vector(list_of_film_publishned, i, j, id, name, length, film_price, rate, production_year,
    film_director);
    list_of_film_publishned[j][0] = list_of_film_publishned[i][0];
    list_of_film_publishned[j][1] = list_of_film_publishned[i][1];
    list_of_film_publishned[j][2] = list_of_film_publishned[i][2];
    list_of_film_publishned[j][3] = list_of_film_publishned[i][3];
    list_of_film_publishned[j][4] = list_of_film_publishned[i][4];
    list_of_film_publishned[j][5] = list_of_film_publishned[i][5];
    list_of_film_publishned[j][6] = list_of_film_publishned[i][6];
    list_of_film_publishned[i][0] = id;
    list_of_film_publishned[i][1] = name;
    list_of_film_publishned[i][2] = length;
    list_of_film_publishned[i][3] = film_price;
    list_of_film_publishned[i][4] = rate;
    list_of_film_publishned[i][5] = production_year;
    list_of_film_publishned[i][6] = film_director;
}

void ListOfFilmSorted::sort_vector_with_id(vector<vector<string> >
list_of_film_publishned) {
    for(int i=0; i<list_of_film_publishned.size();i++) {
        for(int j = i + 1; j < list_of_film_publishned.size(); j++) {
            if(stoi(list_of_film_publishned[i][0]) > stoi(list_of_film_publishned[j][0]))
                sort_id_film(list_of_film_publishned, i, j);
        }
    }
}

int ListOfFilmSorted::search_for_property(Publisher* publisher, vector<vector<string> >
&list_of_film_publishned, vector<string>separated_input, vector<Films*>all_films,
string type_of_string) {
    for(int i = 0; i < separated_input.size(); i++){
        if((separated_input[i]== NAME) || (separated_input[i]== MIN_RATE)
        || (separated_input[i]== MIN_YEAR) || (separated_input[i]== PRICE) 
        || (separated_input[i]== Max_YEAR) || (separated_input[i]==DIRECTOR)) {
            find_films_property(separated_input[i], publisher, list_of_film_publishned,
            separated_input[i + 1], all_films, type_of_string);
            return i + 1;
        }
    }
}

void ListOfFilmSorted::print_title() {
    cout << "#" << DOT << SPACE << FILM_ID_PRINT << SPACE << LINE << SPACE << FILM_NAME <<
    SPACE << LINE << SPACE << FILM_LENGTH << SPACE << LINE << SPACE << FILM_PRICE <<
    SPACE << LINE << SPACE << FILM_RATE << SPACE << LINE << SPACE << FILM_PRODUCTION_YEAR << SPACE << LINE << SPACE
    << FILM_DIRECTORY << "\n";
}

void ListOfFilmSorted::print_list_of_film_publishned(vector<vector<string> >
list_of_film_publishned) {
    print_title();
    for(int i = 0; i < list_of_film_publishned.size(); i++) {
        cout << i + 1 << DOT << SPACE << list_of_film_publishned[i][0] << SPACE << LINE << SPACE 
        << list_of_film_publishned[i][1] << SPACE << LINE << SPACE <<
        list_of_film_publishned[i][2] << SPACE << LINE << SPACE << list_of_film_publishned[i][3] <<
        SPACE << LINE << SPACE << list_of_film_publishned[i][4] << SPACE << LINE << SPACE <<
        list_of_film_publishned[i][5] << SPACE << LINE << SPACE << list_of_film_publishned[i][6] <<
        "\n";
    }
}

void ListOfFilmSorted::sort_list_of_film(vector<string>separated_input,
ProgramData* program_data, string type_of_string) {
    int j = 0;
    vector<vector<string> >list_of_film_publishned;
    Publisher* publisher = program_data->find_publisher_in_system();
    vector<Films*>all_films = program_data->get_film_vector();
    j = search_for_property(publisher, list_of_film_publishned, separated_input, all_films, 
    type_of_string);
    sort_vector_of_propertys(j, list_of_film_publishned, separated_input);
    sort_vector_with_id(list_of_film_publishned);
    print_list_of_film_publishned(list_of_film_publishned);
}