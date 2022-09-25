#include "HandlingOfCommandComments.h"
#include "ErrorCheakingComments.h"
#include "ErrorCheakingRepliesAndDeleteComments.h"
#include "ProgramData.h"
#include "Customer.h"
#include "Films.h"
#include "Publisher.h"
#include "define.h"
#include "ErrorCheakingComments.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int  HandlingOfCommandComments::find_publisher_with_this_id(ProgramData* program_data, string film_id) {
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

string HandlingOfCommandComments::find_name_of_film(string film_id, ProgramData* program_data) {
    string name_of_film;
    vector<Films*>films = program_data->get_film_vector();
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == film_id) {
            return films[i]->get_name();
        }
    }
    return "0";
}

void HandlingOfCommandComments::add_comment_notification(ProgramData* program_data,
string name_of_film, string film_id, int publisher_code, string customer_name,
    int customer_id) {
    vector<Publisher*>publisher = program_data->get_publisher();
    publisher[publisher_code]->notification_rate_and_comment_and_buy_film(customer_name, customer_id,
    name_of_film, film_id, COMMENT);
}

 void HandlingOfCommandComments::add_notification_for_comment(string film_id, Customer* customer,
    ProgramData* program_data) {
    string name_of_film;
    string customer_name = customer->get_username();
    int customer_id = customer->get_id();
    vector<Films*>films = program_data->get_film_vector();
    name_of_film = find_name_of_film(film_id, program_data);
    int publisher_code = find_publisher_with_this_id(program_data, film_id);
    add_comment_notification(program_data, name_of_film, film_id, publisher_code, customer_name,
    customer_id);
}   

void HandlingOfCommandComments::add_notification_for_comment_for_publisher(string film_id,
Publisher* publisher, ProgramData* program_data) {
    string name_of_film;
    string publisher_name = publisher->get_username();
    int publisher_id = publisher->get_id();
    vector<Films*>films = program_data->get_film_vector();
    name_of_film = find_name_of_film(film_id, program_data);
    int publisher_code = find_publisher_with_this_id(program_data, film_id);
    add_comment_notification(program_data, name_of_film, film_id, publisher_code, publisher_name,
    publisher_id);
}

void HandlingOfCommandComments::add_comments(vector<string>separated_input,
ProgramData *program_data, string id, int customer_id) {
    vector<Films*>films = program_data->get_film_vector();
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == id) {
            films[i]->set_comments_of_film(separated_input[6], customer_id);
            return;
        }
    }
}

void HandlingOfCommandComments::delete_comment_from_customer_comments(string id, Publisher* publisher,
vector<string>separated_input) {
    vector<Films*>films = publisher->get_films();
    std::vector<std::vector<std::string> > customer_notifications;
    for(int i = 0; i < films.size(); i++) {
        if(to_string(films[i]->get_id()) == id)
            films[i]->delete_notification_film(separated_input[6]);
    }
}

void HandlingOfCommandComments::cheak_all_error_for_post_comments(vector<string>separated_input,
string id, ProgramData* program_data) {
    error_cheaking_comments.cheak_number_of_input_post_comments(separated_input);
    error_cheaking_comments.cheak_post_comments_format(separated_input);
    error_cheaking_replie_and_delete_comments.cheak_all_error_film(id, program_data);
    error_cheaking_comments.cheak_film_has_bought_for_post(id, program_data);
}

void HandlingOfCommandComments::post_comment(string id, ProgramData* program_data,
vector<string>separated_input, Customer* customer, Publisher* publisher) {
    cheak_all_error_for_post_comments(separated_input, id, program_data);
    if(program_data->get_type_of_user_in_system() == CUSTOMER) {
        add_comments(separated_input, program_data, id, customer->get_id());
        add_notification_for_comment(id, customer, program_data);
    }
    else {
        add_comments(separated_input, program_data, id, publisher->get_id());
        add_notification_for_comment_for_publisher(id, publisher, program_data);
    }
}

void HandlingOfCommandComments::error_cheaking_delete_comments(ProgramData* program_data,
vector<string>separated_input, string id, Publisher* publisher) {
    error_cheaking_comments.cheak_publisher_in(program_data);
    error_cheaking_comments.cheak_number_of_input_delete_comments(separated_input);
    error_cheaking_comments.cheak_delete_comments_format(separated_input);
    error_cheaking_replie_and_delete_comments.cheak_all_error_film(id, program_data);
    error_cheaking_replie_and_delete_comments.cheak_film_id_and_comment_is_for_publisher(id,
    publisher, separated_input[6]);
}

void HandlingOfCommandComments::delete_comment(string id, ProgramData* program_data,
vector<string>separated_input, Publisher* publisher) {
    error_cheaking_delete_comments(program_data, separated_input, id, publisher);
    delete_comment_from_customer_comments(id, publisher, separated_input);
}

void HandlingOfCommandComments::input_comments(vector<string> separated_input,
ProgramData* program_data) {
    string id = separated_input[4];
    Customer* customer = program_data->find_customer_in_system();
    Publisher* publisher = program_data->find_publisher_in_system();
    if((separated_input[0] == POST) && ((separated_input[1] == COMMENTS))) 
        post_comment(id, program_data, separated_input, customer, publisher);
    if((separated_input[0] == POST) && ((separated_input[1] == DELETE_COMMENTS)))
        delete_comment(id, program_data, separated_input, publisher);
    cout << OK << "\n";
}
