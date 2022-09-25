#include "ErrorCheakingRate.h"
#include "ProgramData.h"
#include "Exception.h"
#include "Films.h"
#include "Customer.h"
#include "define.h"

#include <vector>
#include <string>
#include <sstream> 

using namespace std;

void ErrorCheakingRate::cheak_film_has_bought(string id, ProgramData* program_data) {
    int film_id;
    stringstream int_id(id); 
    int_id >> film_id;
    Customer* customer = program_data->find_customer_in_system();
    vector<int>film_bought = customer->get_films_that_customer_bought();
    for(int i = 0; i < film_bought.size(); i++) {
        if(film_bought[i] == film_id)
        return;
    }
    throw Not_Found_Exception();
}

void ErrorCheakingRate::cheak_rote_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if ((separated_input[2*i + 1] == FILM_ID) || (separated_input[2*i + 1] == SCORE))
        continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingRate::cheak_number_of_input_rote(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == SEVEN )
        return;
    else
        throw Bad_Request_Exception();
}

