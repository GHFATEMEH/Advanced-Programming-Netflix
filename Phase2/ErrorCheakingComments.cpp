#include "ErrorCheakingComments.h"
#include "ProgramData.h"
#include "Exception.h"
#include "Customer.h"
#include "define.h"
#include "Publisher.h"

#include <vector>
#include <string>
#include <sstream> 

using namespace std;

void ErrorCheakingComments::cheak_film_has_bought(string id, ProgramData* program_data) {
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

void ErrorCheakingComments::cheak_delete_comments_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if ((separated_input[2*i + 1] == FILM_ID) || (separated_input[2*i + 1] == COMMENT_ID))
        continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingComments::cheak_number_of_input_delete_comments(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == 7)
        return;
    else
        throw Bad_Request_Exception();
}

vector<int> find_film_bought_for_customer_or_publisher(ProgramData* program_data) {
    Customer* customer = program_data->find_customer_in_system();
    Publisher* publisher = program_data->find_publisher_in_system();
    if(program_data->get_type_of_user_in_system() == CUSTOMER) {
        return customer->get_films_that_customer_bought();
    }
    else
        return publisher->get_films_that_customer_bought();
}

void ErrorCheakingComments::cheak_film_has_bought_for_post(string id, ProgramData* program_data) {
    int film_id;
    stringstream int_id(id); 
    int_id >> film_id;
    vector<int>film_bought = find_film_bought_for_customer_or_publisher(program_data);
    for(int i = 0; i < film_bought.size(); i++) {
        if(film_bought[i] == film_id)
        return;
    }
    throw Not_Found_Exception();
}

void ErrorCheakingComments::cheak_post_comments_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if ((separated_input[2*i + 1] == FILM_ID) || (separated_input[2*i + 1] == CONTENT))
        continue;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingComments::cheak_number_of_input_post_comments(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == SEVEN)
        return;
    else
        throw Bad_Request_Exception();
}