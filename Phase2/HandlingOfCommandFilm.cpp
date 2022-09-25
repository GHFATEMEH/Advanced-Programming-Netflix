#include "HandlingOfCommandFilm.h"
#include "Publisher.h"
#include "ProgramData.h"
#include "Films.h"
#include "define.h"
#include "Customer.h"
#include "ErrorCheakingFilm.h"
#include "Exception.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void HandlingOfCommandFilm::notification_add_film_to_followers(string name, int id,
ProgramData* program_data, Publisher* publisher) {
    vector<vector<string> > publisher_followers = publisher->get_followers();
    vector<Customer*>customer = program_data->get_customer();
    for(int i = 0; i < publisher_followers.size(); i++){
        for(int j = 0; j < customer.size(); j++){
            if(customer[j]->get_id() == stoi(publisher_followers[i][0]))
                customer[j]->notification_register_new_film(name, id);
        }
    }
}

void set_information(string &name, string &year, string &length, string &price, string &summary,
string &director, vector<string>seperated_input) {
    for(int i = 0; i < seperated_input.size(); i++) {
        if(seperated_input[i] == NAME)
            name = seperated_input[i + 1];
        if(seperated_input[i] == YEAR)
            year = seperated_input[i + 1];
        if(seperated_input[i] == LENGTH)
            length = seperated_input[i + 1];
        if(seperated_input[i] == PRICE)
            price = seperated_input[i + 1];
        if(seperated_input[i] == SUMMARY)
            summary = seperated_input[i + 1];
        if(seperated_input[i] == DIRECTOR)
            director = seperated_input[i + 1];
    }
}

void HandlingOfCommandFilm::error_cheaking_add_film(ProgramData* program_data,
vector<string>seperated_input) {
    error_cheaking_film.cheak_publisher_in(program_data);
    error_cheaking_film.cheak_number_of_input_add_film(seperated_input);
    error_cheaking_film.cheak_film_format(seperated_input);
}

void HandlingOfCommandFilm::add_film(Publisher* publisher, ProgramData* program_data,
vector<string> seperated_input) {
    error_cheaking_add_film(program_data, seperated_input);
    string name,year,length,price,summary,director;
    set_information(name, year, length, price, summary, director, seperated_input);
    int id = program_data->get_film_id();
    Films* new_film = new Films(id, year, length, price, name, summary, director,EXIST);
    publisher->add_film(new_film);
    program_data->add_new_film(new_film);
    notification_add_film_to_followers(name, publisher->get_id(), program_data, publisher);
    program_data->add_film_to_graph();
    cout << OK << "\n";
}

int HandlingOfCommandFilm::cheak_id_in_film(Publisher* publisher, ProgramData* program_data,
vector<string> seperated_input, string type, int &id) {
    string film_id;
    for(int i = 0; i < seperated_input.size(); i++) {
        if(seperated_input[i] == FILM_ID)
            film_id = seperated_input[i + 1];
    }
    id = stoi(film_id);
    if(type == DELETE)
        program_data->cheak_id_of_film_exist(id);
    return publisher->cheak_film_id_exist_for_publisher(id);
}

void HandlingOfCommandFilm::set_film_changes(int j, Publisher* publisher, vector<string> seperated_input) {
    for(int i = 0; i < seperated_input.size(); i++) {
        if(seperated_input[i] == NAME)
            publisher->change_name(seperated_input[i + 1], j);
        if(seperated_input[i] == YEAR)
            publisher->change_year(seperated_input[i + 1], j);
        if(seperated_input[i] == LENGTH)
            publisher->change_length(seperated_input[i + 1], j);
        if(seperated_input[i] == SUMMARY)
            publisher->change_summary(seperated_input[i + 1], j);
        if(seperated_input[i] == DIRECTOR)
            publisher->change_director(seperated_input[i + 1], j);
    }
}

void HandlingOfCommandFilm::edit_film(Publisher* publisher, ProgramData* program_data,
vector<string> seperated_input) {
    error_cheaking_film.cheak_publisher_in(program_data);
    int id;
    int j = cheak_id_in_film(publisher, program_data, seperated_input, EDIT, id);
    set_film_changes(j, publisher, seperated_input);
    cout << OK << "\n";
}

void HandlingOfCommandFilm::delete_film(Publisher* publisher, ProgramData* program_data,
vector<string> seperated_input) {
    error_cheaking_film.cheak_publisher_in(program_data);
    int id;
    cheak_id_in_film(publisher, program_data, seperated_input, DELETE, id);
    program_data->get_film(id)->delete_film();
    cout << OK << "\n";
}

int find_film(vector<Films*>films, vector<string>seperated_input) {
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == seperated_input[4])
            return i;
    }
    return 0;
}

void HandlingOfCommandFilm::print_film_detail(vector<Films*>films, string film_id,
int film_code) {
    cout << "Details of Film" << SPACE << films[film_code]->get_name() << "\n";
    if(films[film_code]->get_exist_or_delete() == EXIST) {
        cout << ID << SPACE << EQUAL << SPACE << film_id << "\n";
        cout << DIRECTOR_OF_FILM << SPACE << EQUAL << SPACE << films[film_code]->get_director() << "\n";
        cout << LENGTH_PRINT << SPACE << EQUAL << SPACE << films[film_code]->get_length() << "\n";
        cout << YEAR_PRINT << SPACE << EQUAL << SPACE << films[film_code]->get_year() << "\n";
        cout << SUMMARY << SPACE << EQUAL << SPACE << films[film_code]->get_summary() << "\n";
        cout << RATE_PRINT << SPACE << EQUAL << SPACE << to_string(films[film_code]->get_rate()) << "\n";
        cout << PRICE_PRINT << SPACE << EQUAL << SPACE << to_string(films[film_code]->get_price()) << "\n";
        cout << "\n";
    }
    else
        throw Not_Found_Exception();
}

bool customer_in_system(ProgramData* program_data) {
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        return true;
    else
        return false;
}

void HandlingOfCommandFilm::print_reply_for_customer(vector<Customer*>customers_in_system,
vector<vector<string> >comments_of_film, int i, int &counter) {
    for(int j = 0; j < customers_in_system.size(); j++) {
        for(int k = 0; k < customers_in_system[j]->get_customer_notifications().size(); k++) {
            if(customers_in_system[j]->get_customer_notifications()[k][4] == comments_of_film[i][1]) {
                cout << comments_of_film[i][0]<< DOT << counter << DOT<<SPACE<<customers_in_system[j]->
                get_customer_notifications()[k][3] << "\n";
                counter++;
            }
        }   
    }
    cout << "\n";
}

void HandlingOfCommandFilm::print_reply_for_publisher(vector<vector<string> >comments_of_film,
int i, int &counter, vector<Publisher*> publisher_in_system) {
    for(int j = 0; j < publisher_in_system.size(); j++) {
        for(int k = 0; k < publisher_in_system[j]->get_customer_notifications().size(); k++) {
            if(publisher_in_system[j]->get_customer_notifications()[k][4] == comments_of_film[i][1]) {
                cout << comments_of_film[i][0]<< DOT << counter << DOT<<SPACE<<publisher_in_system[j]->
                get_customer_notifications()[k][3] << "\n";
                counter++;
            }
        }   
    }
    cout << "\n";
}

void HandlingOfCommandFilm::print_comment(vector<Films*>films, int film_code, Customer* customer,
ProgramData* program_data, Publisher* publisher) {
    int counter = 1;
    cout << COMMENTS_PRINT << "\n";
    vector<vector<string> >comments_of_film = films[film_code]->get_comments_of_film();
    vector<Customer*>customers_in_system = program_data->get_customer();
    vector<Publisher*>publisher_in_system = program_data->get_publisher();
    for(int i = 0; i < comments_of_film.size(); i++) {
        if(comments_of_film[i][3] == EXIST) {
            cout << comments_of_film[i][0] << DOT << SPACE << comments_of_film[i][2] << "\n";
            if(customer_in_system(program_data))
                print_reply_for_customer(customers_in_system, comments_of_film, i, counter);
            else
                print_reply_for_publisher(comments_of_film, i, counter, publisher_in_system);
        }
        else
            throw Not_Found_Exception();
    }
    cout << "\n";
}

bool cheak_film_did_not_delete(int id, ProgramData* program_data) {
    vector<Films*>films = program_data->get_film_vector();
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id) {
            if(films[i]->get_exist_or_delete() == EXIST)
                return true;
        }
    }
    return false;
}

void print_details(string film_id, string film_name, string film_length, string film_director,
int counter) {
    cout << counter << DOT << SPACE << film_id << SPACE << LINE << SPACE << film_name << SPACE 
    << LINE << SPACE << film_length << SPACE << LINE << SPACE << film_director << "\n";
}

void print_film(int id, ProgramData* program_data, int counter) {
    string  film_id, film_name, film_length, film_director;
    vector<Films*>films = program_data->get_film_vector();
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == id) {
            film_id = to_string(films[i]->get_id());
            film_name = films[i]->get_name();
            film_length = films[i]->get_length();
            film_director = films[i]->get_director();
            print_details(film_id, film_name, film_length, film_director, counter);
        }
    }
}

void print_title() {
    cout << "Recommendation Film" << "\n";
    cout << "#" << "." << SPACE << FILM_ID_PRINT << SPACE << LINE << SPACE << FILM_NAME << 
    SPACE << LINE << SPACE << FILM_LENGTH << SPACE << LINE << SPACE << FILM_DIRECTOR << "\n";
}

void HandlingOfCommandFilm::print_recommend_film(string film_id, ProgramData* program_data) {
    print_title();
    int counter = 0;
    vector<vector<int> >recommend_film = program_data->find_recommend_film(stoi(film_id));
    for(int i = recommend_film.size() - 1; i < recommend_film.size(); i++) {
        int id = recommend_film[i][0];
        if(film_id != to_string(id)) {
            if(cheak_film_did_not_delete(id, program_data)) {
                if((counter < FOUR) && (counter < recommend_film.size())) {
                counter++;
                print_film(id, program_data, counter);
                }
            }
        }
    }
}

void HandlingOfCommandFilm::show_film_detail(Customer* customer,
vector<string>seperated_input, ProgramData* program_data, Publisher* publisher) {
    string film_id = seperated_input[4];
    vector<Films*>films = program_data->get_film_vector();
    int film_code = find_film(films, seperated_input);
    error_cheaking_film.cheak_all_error_film(seperated_input[4], program_data);
    print_film_detail(films, film_id, film_code);
    print_comment(films, film_code, customer, program_data, publisher);
    print_recommend_film(film_id, program_data);
}

void HandlingOfCommandFilm::input_film(ProgramData* program_data,
vector<string> seperated_input) {
    Publisher* publisher = program_data->find_publisher_in_system();
    Customer* customer = program_data->find_customer_in_system();
    if((seperated_input[0] == POST) && (seperated_input[1] == FILMS))
        add_film(publisher, program_data, seperated_input);
    if((seperated_input[0] == POST) && (seperated_input[1] == PUT_FILMS)) {
        edit_film(publisher, program_data, seperated_input);}
    if((seperated_input[0] == POST) && (seperated_input[1] == DELETE_FILMS))
        delete_film(publisher, program_data, seperated_input);
    if(seperated_input[0] ==  GET)
        show_film_detail(customer, seperated_input, program_data, publisher);
}


