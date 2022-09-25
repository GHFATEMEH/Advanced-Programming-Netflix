#include "HandlingOfCommandMoney.h"
#include <iostream>
#include <vector>
#include <string>
#include "ProgramData.h"
#include "Customer.h"
#include "Publisher.h"
#include "define.h"
#include "Films.h"
#include "ErrorCheakingMoney.h"

using namespace std;

void HandlingOfCommandMoney::error_cheaking_post_money(ProgramData* program_data,
vector<string>separated_input) {
    error_cheaking_money.cheak_number_of_input_money(separated_input);
    error_cheaking_money.cheak_input_for_money(separated_input);
}

void HandlingOfCommandMoney::increase_money(ProgramData* program_data, Customer* customer,
vector<string>separated_input, Publisher* publisher) {
    error_cheaking_post_money(program_data, separated_input);
    string amount = separated_input[4];
    int _money = stoi(amount);
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        customer->add_to_money(_money);
    else
        publisher->add_to_money(_money);
}

void HandlingOfCommandMoney::calculate_money(Publisher* publisher, ProgramData* program_data) {
    vector<vector<int> >films_of_publisher_that_bought = publisher->
    get_films_of_publisher_that_bought();
    error_cheaking_money.cheak_publisher_in(program_data);
    for(int i = 0; i < films_of_publisher_that_bought.size(); i++) {
        if(films_of_publisher_that_bought[i][3] == NOT_GET_MONEY) {
            int price = films_of_publisher_that_bought[i][1];
            int rate = films_of_publisher_that_bought[i][2];
            publisher->add_to_film_money(rate, price, program_data, i); 
        }
    }
}

void HandlingOfCommandMoney::post_money(ProgramData* program_data,
vector<string>separated_input) {
    Customer* customer = program_data->find_customer_in_system();
    Publisher* publisher = program_data->find_publisher_in_system();
    if(separated_input[2] == QUESTION_MARK)
            increase_money(program_data, customer, separated_input, publisher);
        else
            calculate_money(publisher, program_data); 
            cout << OK << "\n";
}

void HandlingOfCommandMoney::show_money_of_customer(ProgramData* program_data) {
    Customer* customer = program_data->find_customer_in_system();
    cout << customer->get_money() << "\n";
}

void HandlingOfCommandMoney::show_money_of_publisher(ProgramData * program_data) {
    Publisher* publisher = program_data->find_publisher_in_system();
    cout << (publisher->get_money() + publisher->get_money_of_selling_films()) << "\n";
}

void HandlingOfCommandMoney::show_money(ProgramData* program_data) {
    if(program_data->get_username_in_system() == ADMIN)
        cout << program_data->get_money_in_system() << "\n";
    if(program_data->get_type_of_user_in_system() == CUSTOMER)
        show_money_of_customer(program_data);
    else if(program_data->get_type_of_user_in_system() == PUBLISHER)
            show_money_of_publisher(program_data);
}

void HandlingOfCommandMoney::input_money(vector<string>separated_input,
ProgramData* program_data) {
    if(separated_input[0] == POST)
        post_money(program_data, separated_input);
    if(separated_input[0] == GET) 
        show_money(program_data);
}

