#include "HandlingOfCommandFollowers.h"
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "Publisher.h"
#include "Customer.h"
#include "ProgramData.h"
#include "Exception.h"
#include "Publisher.h"
#include "define.h"
#include "ErrorCheakingFollowers.h"

using namespace std;

bool HandlingOfCommandFollowers::cheak_id_in_publishers(string publisher_id, ProgramData* program_data) {
    vector<Publisher*> publishers_in_system = program_data->get_publisher();
    int id = stoi(publisher_id);
    for(int i = 0; i < publishers_in_system.size(); i++) {
        if (publishers_in_system[i]->get_id() == id)
            return true;
    }
    throw Not_Found_Exception();
}

bool HandlingOfCommandFollowers::cheak_id_is_digit(string publisher_id) {
    for(int i = 0; i < publisher_id.length(); i++) {
        if (('0' < publisher_id[i]) && (publisher_id[i] <= '9' ))
            continue;
        else
            throw Bad_Request_Exception();
    }
    return true;
}

void HandlingOfCommandFollowers::cheak_id_is_available(string &publisher_id, ProgramData* program_data,
vector<string>separated_input) {
    for(int i = 0; i < separated_input.size(); i++) {
        if(separated_input[i] == USER_ID)
            publisher_id = separated_input[i + 1];
    }
    cheak_id_is_digit(publisher_id);
    cheak_id_in_publishers(publisher_id, program_data);
}

void HandlingOfCommandFollowers::save_publisher_followers(int publisher_id, Customer* customer,
ProgramData* program_data) {
    string username = customer->get_username();
    string email = customer->get_email();
    int customer_id = customer->get_id();
    vector<Publisher*>  publisher_followe =  program_data->get_publisher();
    for(int i = 0; i < publisher_followe.size(); i++) {
        if(publisher_followe[i]->get_id() == publisher_id){
            publisher_followe[i]->add_followers(customer_id, username, email);
            publisher_followe[i]->notification_you_followed(username,customer_id);
            break;
        }
    }
}

bool HandlingOfCommandFollowers::did_not_followe_before(string publisher_id, Customer* customer) {
    vector<int>list_of_publisher_followed = customer->get_list_of_publisher_followed();
    int id = stoi(publisher_id);
    for(int i = 0; i < list_of_publisher_followed.size(); i++) {
        if(list_of_publisher_followed[i] == id)
            return false;
    }
    return true;

}

void HandlingOfCommandFollowers::followe_publisher(vector<string>separated_input,
ProgramData* program_data, Customer* customer) {
    error_cheaking_followers.cheak_customer_in(program_data);
    error_cheaking_followers.cheak_user_id_exist(program_data, separated_input[4]);
    string publisher_id;
    cheak_id_is_available(publisher_id, program_data, separated_input);
    if(did_not_followe_before(publisher_id, customer)) {
        customer->followe_publisher(stoi(publisher_id));
        save_publisher_followers(stoi(publisher_id), customer, program_data);
    }
}

void sort_id(vector<vector<string> > &followers, int i, int j) {
    string id = followers[j][0];
    string name = followers[j][1];
    string email = followers[j][2];
    followers[j][0] = followers[i][0];
    followers[j][1] = followers[i][1];
    followers[j][2] = followers[i][2];
    followers[i][0] = id;
    followers[i][1] = name;
    followers[i][2] = email;
}

vector<vector<string> > compare_id(Publisher* publisher) {
    vector<vector<string> > followers = publisher->get_followers();
    for(int i = 0; i < followers.size(); i++) {
        for(int j = i + 1; j < followers.size(); j++) {
            if(stoi(followers[i][0]) > stoi(followers[j][0]))
                sort_id(followers, i, j);
        }
    }
    return followers;
}

void print_title_followed() {
    cout << "List of Followers" << "\n";
    cout << "#" << DOT << SPACE << USER_ID_PRINT << SPACE << LINE << SPACE << USER_USERNAME <<
    SPACE << LINE << SPACE << USER_MAIL << "\n";
}

void HandlingOfCommandFollowers::print_publisher_followers(Publisher* publisher,
ProgramData* program_data) {
    error_cheaking_followers.cheak_publisher_in(program_data);
    print_title_followed();
    vector<vector<string> > list_of_followers = compare_id(publisher);
    for(int i = 0; i < list_of_followers.size(); i++) {
        cout << i + 1 << DOT << SPACE << list_of_followers[i][0] << SPACE << LINE << SPACE <<
        list_of_followers[i][1] << SPACE << LINE << SPACE << list_of_followers[i][2] << "\n";
    }
}

void HandlingOfCommandFollowers::input_followers(vector<string>separated_input,
ProgramData* program_data) {
    Publisher* publisher = program_data->find_publisher_in_system();
    Customer* customer = program_data->find_customer_in_system();
        if(separated_input[0] == POST) {
            followe_publisher(separated_input, program_data, customer);
            cout << OK << "\n";
        }
        if(separated_input[0] == GET) {
            print_publisher_followers(publisher, program_data);
        }
}

