#include "ErrorCheakingFilm.h"
#include "ProgramData.h"
#include "Exception.h"
#include "Films.h"
#include "define.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool ErrorCheakingFilm::cheak_id_is_digit(string film_id) {
    for(int i = 0; i < film_id.length(); i++) {
        if (('0' < film_id[i]) && (film_id[i] <= '9' ))
            continue;
        else
            throw Bad_Request_Exception();
    }
    return true;
}

void ErrorCheakingFilm::cheak_film_id_exist(string id, ProgramData* program_data) {
    int film_id;
    stringstream int_id(id); 
    int_id >> film_id;
    vector<Films*>film = program_data->get_film_vector();
    for(int i = 0; i < film.size(); i++) {
        if((film[i]->get_id() == film_id) && ((film[i]->get_exist_or_delete() == EXIST)))
            return;
    }
    throw Not_Found_Exception();
}

void ErrorCheakingFilm::cheak_number_of_input_add_film(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == 15)
        return;
    else
        throw Bad_Request_Exception();
}

void ErrorCheakingFilm::cheak_film_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if ((separated_input[2*i + 1] == NAME) || (separated_input[2*i + 1] == YEAR) ||
        (separated_input[2*i + 1] == LENGTH) || (separated_input[2*i + 1] == PRICE) ||
        (separated_input[2*i + 1] == SUMMARY_FILM) || (separated_input[2*i + 1] == DIRECTOR))
        continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingFilm::cheak_customer_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == PUBLISHER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingFilm::cheak_publisher_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == CUSTOMER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingFilm::cheak_all_error_film(string film_id, ProgramData* program_data) {
    cheak_id_is_digit(film_id);
    cheak_film_id_exist(film_id, program_data);
}

void ErrorCheakingFilm::cheak_film_delete_format(vector<string>seperated_input) {
    if(seperated_input[3] == FILM_ID)
        return;
    throw Bad_Request_Exception();
}
