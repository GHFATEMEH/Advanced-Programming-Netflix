#include "HandlingOfCommandBuy.h"
#include "Customer.h"
#include "define.h"
#include "Films.h"
#include "ProgramData.h"

#include <string>
#include <vector>

using namespace std;

void HandlingOfCommandBuy::find_film_details(string id, string &year, string &length, string &price,
string &name, string &summary, string &director, vector<Films*>film) {
    for(int i = 0; i < film.size(); i++) {
        if(to_string(film[i]->get_id()) == id)
            year = film[i]->get_year();
            length = film[i]->get_length();
            price = to_string(film[i]->get_price());
            name = film[i]->get_name();
            summary = film[i]->get_summary();
            director = film[i]->get_director();
    }
}

void HandlingOfCommandBuy::buy_film(std::string id, string rate,
ProgramData* program_data) {
    string year, length, price, name, summary, director;
    vector<Films*>film = program_data->get_film_vector();
    Customer* customer = program_data->find_customer_in_system();
    find_film_details(id, year, length, price, name, summary, director, film);
    customer->save_bought_films(stoi(id), year, length, price, name, summary, director, EXIST, rate);
    customer->reduce_money_after_paid(stoi(price));
}

void HandlingOfCommandBuy::cheak_error_for_buy(string film_id, vector<Films*>film,
ProgramData* program_data) {
    error_cheaking_buy.cheak_money_to_buy_film(film_id, film, program_data);
}
