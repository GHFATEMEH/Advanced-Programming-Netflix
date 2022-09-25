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

void HandlingOfCommandMoney::increase_money(ProgramData* program_data, Customer* customer,
vector<string>separated_input) {
    string amount = separated_input[4];
    int _money = stoi(amount);
    customer->add_to_money(_money);
}

void  HandlingOfCommandMoney::find_rate_and_price(int film_id, Publisher* publisher, int &price,
float &rate) {
    vector<Films*>films = publisher->get_films();
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == film_id)
            rate = films[i]->get_rate();
            price = films[i]->get_price();
            return;
    }
}

void HandlingOfCommandMoney::calculate_money(Publisher* publisher) {
    float rate;
    int price;
    vector<vector<int> >films_of_publisher_that_bought = publisher->
    get_films_of_publisher_that_bought();
    for(int i = 0; i < films_of_publisher_that_bought.size(); i++) {
        int film_id = films_of_publisher_that_bought[i][0];
        find_rate_and_price(film_id, publisher, price, rate);
        int time_of_bought = films_of_publisher_that_bought[i][1];
        publisher->add_to_film_money(time_of_bought, rate, price); 
    }
}

void HandlingOfCommandMoney::input_money(vector<string>separated_input,
ProgramData* program_data) {
    error_cheaking_money.cheak_customer_in(program_data);
    error_cheaking_money.cheak_number_of_input_money(separated_input);
    error_cheaking_money.cheak_input_for_money(separated_input);
    Customer* customer = program_data->find_customer_in_system();
    Publisher* publisher = program_data->find_publisher_in_system();
    if(separated_input[2] == QUESTION_MARK) {
        increase_money(program_data, customer, separated_input);
    }
    else
        calculate_money(publisher);
    cout << OK << "\n";
}

