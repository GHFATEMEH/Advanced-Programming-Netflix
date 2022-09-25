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
ProgramData* program_data) {
    int rote;
    int id;
    stringstream film_rote(separated_input[6]);
    film_rote >> rote;
    stringstream film_id(separated_input[4]); 
    film_id >> id;
    Films* films = program_data->get_film(id) ;
    films->set_customers_rote_to_film(rote, customer->get_id());
    films->set_rote();
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
}

string HandlingOfCommandRate::find_name_of_film(string film_id, ProgramData* program_data) {
    string name_of_film;
    vector<Films*>films = program_data->get_film_vector();
    for(int i=0;i<films.size();i++) {
        if(to_string(films[i]->get_id()) == film_id) {
            return films[i]->get_name();
        }
    }
}

void HandlingOfCommandRate::add_rate_notification(ProgramData* program_data, string name_of_film,
    string film_id, int publisher_code, string customer_name, int customer_id) {
        vector<Publisher*>publisher = program_data->get_publisher();
        publisher[publisher_code]->notification_rote_and_comment_and_buy_film(customer_name,
        customer_id, name_of_film, film_id, ROTE);
}

void HandlingOfCommandRate::send_notification_to_publisher(string film_id, Customer* customer,
ProgramData* program_data) {
    string name_of_film;
    string customer_name = customer->get_username();
    int customer_id = customer->get_id();
    vector<Films*>films = program_data->get_film_vector();
    name_of_film = find_name_of_film(film_id, program_data);
    int publisher_code = find_publisher_with_this_id(program_data, film_id);
    add_rate_notification(program_data, name_of_film, film_id, publisher_code, customer_name,
    customer_id);

}

void HandlingOfCommandRate::cheak_all_error_for_rate(vector<string>separated_input,
ProgramData* program_data, string id) {
    error_cheaking_rate.cheak_customer_in(program_data);
    error_cheaking_rate.cheak_number_of_input_rote(separated_input);
    error_cheaking_rate.cheak_rote_format(separated_input);
    error_cheaking_rate.cheak_all_error_film(id, program_data);
    error_cheaking_rate.cheak_film_has_bought(id, program_data);
}

void HandlingOfCommandRate::input_rate(vector<string>separated_input, ProgramData* program_data) {
    string id = separated_input[4];
    Customer* customer = program_data->find_customer_in_system();
    cheak_all_error_for_rate(separated_input, program_data, id);
    add_to_rate(separated_input, customer, program_data);
    send_notification_to_publisher(id, customer, program_data);
    cout << OK <<"\n";
}
