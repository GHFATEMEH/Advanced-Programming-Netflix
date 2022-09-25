#include "HandlingOfCommandBuy.h"
#include "ProgramData.h"
#include "Customer.h"
#include "Publisher.h"
#include "Films.h"
#include "Exception.h"
#include "define.h"
#include "ErrorCheakingBuy.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream> 

using namespace std;

void cheak_having_money(int money, int film_price) {
    if(film_price <= money)
        return;
    else
        throw Permission_Denied_Exception();
}

void HandlingOfCommandBuy::reduce_customer_money(int film_price, Customer* customer) {
    customer->reduce_money_after_payed(film_price);
}

void HandlingOfCommandBuy::cheak_for_user_have_money_and_reduce_money(Customer *customer,
ProgramData* program_data, int id) {
    Films* films = program_data->get_film(id);
    int film_price = films->get_price();
    int money = customer->get_money();
    cheak_having_money(money, film_price);
    reduce_customer_money(film_price, customer);
}

int  HandlingOfCommandBuy::save_film_bought_for_publisher(int id, Customer* customer, ProgramData*
program_data) {
    vector<Publisher*> publisher = program_data->get_publisher();
    for(int i = 0; publisher.size(); i++) {
        for(int j = 0; j < publisher[i]->get_films().size(); j++){
                if(publisher[i]->get_films()[j]->get_id() == id) {
                    publisher[i]->add_to_film_bought(id);
                    return i;
                }
        }
    }
}

void HandlingOfCommandBuy::save_buy_notifacation(int user_id, string username, string film_id, 
string film_name, int number_of_publisher, ProgramData* program_data) {
    vector<Publisher*>publisher = program_data->get_publisher();
    publisher[number_of_publisher]->notification_rote_and_comment_and_buy_film(username,
    user_id, film_name, film_id, BUY_FILM);
}

void HandlingOfCommandBuy::notification_film_bought(Customer* customer, string film_id,
ProgramData* program_data, int number_of_publisher, int id) {
    int user_id = customer->get_id();
    string username = customer->get_username();
    Films* films = program_data->get_film(id);
    string film_name = films->get_name();
    save_buy_notifacation(user_id, username, film_id, film_name, number_of_publisher, program_data);
}

void HandlingOfCommandBuy::cheak_all_errors_for_buy(vector<string>seperated_input,
ProgramData* program_data) {
    error_cheaking_buy.cheak_customer_in(program_data);
    error_cheaking_buy.cheak_number_of_input_buy(seperated_input);
    error_cheaking_buy.cheak_buy_format(seperated_input);
    error_cheaking_buy.cheak_all_error_film(seperated_input[4], program_data);
}

void HandlingOfCommandBuy::input_buy(vector<string>seperated_input, ProgramData* program_data) {
    cheak_all_errors_for_buy(seperated_input, program_data);
    Customer* customer  = program_data->find_customer_in_system();
    stringstream film_id(seperated_input[4]); 
    int id;
    film_id >> id;
    cheak_for_user_have_money_and_reduce_money(customer, program_data, id);
    customer->save_bought_films(id);
    int number_of_publisher = save_film_bought_for_publisher(id, customer, program_data);
    notification_film_bought(customer, seperated_input[4], program_data, number_of_publisher, id);
    cout << OK <<"\n";
}
