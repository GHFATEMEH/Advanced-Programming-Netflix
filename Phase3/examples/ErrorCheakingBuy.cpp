#include "ErrorCheakingBuy.h"
#include "Films.h"
#include "../server/server.hpp"
#include "define.h"
#include "Customer.h"
#include "ProgramData.h"

#include <string>
#include <vector>

using namespace std;

int ErrorCheakingBuy::find_price_of_film(string film_id, vector<Films*>film) {
    int price;
    for(int i = 0; i < film.size(); i++) {
        if(to_string(film[i]->get_id()) == film_id)
            price = film[i]->get_price();
    }
    return price;
}

void ErrorCheakingBuy::cheak_money_to_buy_film(string film_id, vector<Films*>film,
ProgramData* program_data) {
    int money;
    Customer* customer = program_data->find_customer_in_system();
    money = customer->get_money();
    int price = find_price_of_film(film_id, film);
    if(price > money)
        throw Server::Exception("Permission denied : You have not enough money.");
}