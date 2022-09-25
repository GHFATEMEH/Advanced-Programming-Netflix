#include "HandlingOfCommandReplies.h"
#include "ProgramData.h"
#include "Publisher.h"
#include "define.h"
#include "Films.h"
#include "Customer.h"
#include "ErrorCheakingRepliesAndDeleteComments.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string HandlingOfCommandReplies::find_customer_id_that_comment_film(string comment_id,
string film_id, ProgramData* program_data) {
    string comment_of_film;
    Films* films = program_data->get_film(stoi(film_id));
    vector<vector<string> >comment_of_films = films->get_comments_of_film();
    for(int i = 0; i < comment_of_films.size(); i++) {
        if(comment_of_films[i][0] == comment_id) {
            comment_of_film = comment_of_films[i][1];
            return comment_of_film;
        }
    }
    return comment_of_film;
}

void HandlingOfCommandReplies::set_notification_for_customer(string customer_id,
string publisher_name, string publisher_id, ProgramData* program_data, string content) {
    vector<Customer*>customer = program_data->get_customer();
    for(int i = 0; i < customer.size(); i++) {
        if(to_string(customer[i]->get_id()) == customer_id) {
            customer[i]->set_customer_notifications(publisher_name, publisher_id, content,
            to_string(customer[i]->get_id()));
            return;
        }
    }
}

void HandlingOfCommandReplies::add_notification_reply(Publisher* publisher, string film_id,
ProgramData* program_data, string comment_id, string content) {
    string publisher_id = to_string(publisher->get_id());
    string publisher_name = publisher->get_username();
    string customer_id = find_customer_id_that_comment_film(comment_id, film_id , program_data);
    set_notification_for_customer(customer_id, publisher_name, publisher_id, program_data, content);
}

void HandlingOfCommandReplies::input_reply(vector<string>separated_input,
ProgramData* program_data) {
    Publisher* publisher = program_data->find_publisher_in_system();
    string film_id = separated_input[4];
    string comment_id = separated_input[6];
    string content = separated_input[8];
    error_cheaking_replies.cheak_publisher_in(program_data);
    error_cheaking_replies.cheak_all_error_film(film_id, program_data);
    error_cheaking_replies.cheak_film_id_and_comment_is_for_publisher(film_id, publisher, comment_id);
    add_notification_reply(publisher, film_id, program_data, comment_id, content);
    cout << OK << "\n";
}
