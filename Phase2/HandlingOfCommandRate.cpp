#include "HandlingOfCommandRate.h"
#include "ErrorCheakingRate.h"
#include "ProgramData.h"
#include "define.h"
#include "Customer.h"
#include "Films.h"
#include "Publisher.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream> 


using namespace std;

void HandlingOfCommandRate::add_to_rate(vector<string>separated_input, Customer* customer,
ProgramData* program_data, Publisher* publisher) {
    int id_for_save;
    int rate;
    int id;
    stringstream film_rate(separated_input[6]);
    film_rate >> rate;
    stringstream film_id(separated_input[4]); 
    film_id >> id;
    Films* films = program_data->get_film(id) ;
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        id_for_save = customer->get_id();
    else
        id_for_save = publisher->get_id();
    films->set_customers_rate_to_film(rate, id_for_save);
    films->set_rate();
}

int  HandlingOfCommandRate::find_publisher_with_this_id(ProgramData* program_data, string film_id) {
    vector<Publisher*> publisher = program_data->get_publisher();
    for(int i = 0; publisher.size(); i++) {
        for(int j = 0; j < publisher[i]->get_films().size(); j++){
                if(to_string(publisher[i]->get_films()[j]->get_id()) == film_id) {
                    return i;
                }
        }
    }
    return 0;
}

string HandlingOfCommandRate::find_name_of_film(string film_id, ProgramData* program_data) {
    string name_of_film;
    vector<Films*>films = program_data->get_film_vector();
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == film_id) {
            name_of_film = films[i]->get_name();
            return name_of_film;
        }
    }
    return name_of_film;
}

void HandlingOfCommandRate::add_rate_notification(ProgramData* program_data, string name_of_film,
    string film_id, int publisher_code, string customer_name, int customer_id) {
        vector<Publisher*>publisher = program_data->get_publisher();
        publisher[publisher_code]->notification_rate_and_comment_and_buy_film(customer_name,
        customer_id, name_of_film, film_id, RATE);
}

void HandlingOfCommandRate::send_notification_to_publisher_by_customer(string film_id,
Customer* customer, ProgramData* program_data) {
    string name_of_film;
    string customer_name = customer->get_username();
    int customer_id = customer->get_id();
    vector<Films*>films = program_data->get_film_vector();
    name_of_film = find_name_of_film(film_id, program_data);
    int publisher_code = find_publisher_with_this_id(program_data, film_id);
    add_rate_notification(program_data, name_of_film, film_id, publisher_code, customer_name,
    customer_id);
}

void HandlingOfCommandRate::send_notification_to_publisher_by_publisher(string film_id,
Publisher* publisher, ProgramData* program_data) {
    string name_of_film;
    string publisher_name = publisher->get_username();
    int publisher_id = publisher->get_id();
    vector<Films*>films = program_data->get_film_vector();
    name_of_film = find_name_of_film(film_id, program_data);
    int publisher_code = find_publisher_with_this_id(program_data, film_id);
    add_rate_notification(program_data, name_of_film, film_id, publisher_code, publisher_name,
    publisher_id);
}

void HandlingOfCommandRate::send_notification(string id, Customer* customer,
ProgramData* program_data, Publisher* publisher) {
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        send_notification_to_publisher_by_customer(id, customer, program_data);
    else
        send_notification_to_publisher_by_publisher(id, publisher, program_data);
}

void HandlingOfCommandRate::cheak_all_error_for_rate(vector<string>separated_input,
ProgramData* program_data, string id, Publisher* publisher) {
    error_cheaking_rate.cheak_number_of_input_rate(separated_input);
    error_cheaking_rate.cheak_rate_format(separated_input);
    error_cheaking_rate.cheak_all_error_film(id, program_data);
    error_cheaking_rate.cheak_film_has_bought(id, program_data);
}

void HandlingOfCommandRate::input_rate(vector<string>separated_input, ProgramData* program_data) {
    string id = separated_input[4];
    Customer* customer = program_data->find_customer_in_system();
    Publisher* publisher = program_data->find_publisher_in_system();
    cheak_all_error_for_rate(separated_input, program_data, id, publisher);
    add_to_rate(separated_input, customer, program_data, publisher);
    send_notification(id, customer, program_data, publisher);
    cout << OK <<"\n";
}
