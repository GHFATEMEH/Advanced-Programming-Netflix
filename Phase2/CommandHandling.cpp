  #include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "CommandHandling.h"
#include "Exception.h"
#include "define.h"
#include "HandlingOfCommandSignup.h"
#include "HandlingOfCommandLogin.h"
#include "ProgramData.h"
#include "Publisher.h"
#include "Customer.h"
#include "HandlingOfCommandFilm.h"
#include "HandlingOfCommandFollowers.h"
#include "HandlingOfCommandMoney.h"
#include "HandlingOfCommandBuy.h"
#include "HandlingOfCommandRate.h"
#include "HandlingOfCommandComments.h"
#include "HandlingOfCommandPublished.h"
#include "HandlingOfCommandReplies.h"
#include "HandlingOfCommandPurchased.h"
#include "ErrorHandlingLogout.h"

using namespace std;

CommandHandling::CommandHandling() {
    program_data = new ProgramData();
}

vector<string> save_command_before_question_mark() {
    vector<string>command_before_question_mark;
    command_before_question_mark.push_back(SIGNUP);
    command_before_question_mark.push_back(LOGIN);
    command_before_question_mark.push_back(FILMS);
    command_before_question_mark.push_back(FOLLOWERS);
    command_before_question_mark.push_back(MONEY);
    command_before_question_mark.push_back(PUBLISHED);
    command_before_question_mark.push_back(REPLIES);
    command_before_question_mark.push_back(COMMENTS);
    command_before_question_mark.push_back(BUY);
    command_before_question_mark.push_back(RATE);
    command_before_question_mark.push_back(PURCHASED);
    command_before_question_mark.push_back(NOTIFICATIONS);
    command_before_question_mark.push_back(DELETE_FILMS);
    command_before_question_mark.push_back(DELETE_COMMENTS);
    command_before_question_mark.push_back(LOGOUT);
    command_before_question_mark.push_back(PUT_FILMS);
    return command_before_question_mark;
}

bool CommandHandling::cheak_second_part_of_input(vector<string>separated_input) {
    vector<string>command_before_question_mark = save_command_before_question_mark();
    for(int i = 0; i < command_before_question_mark.size(); i++){
        if(separated_input[1] == command_before_question_mark[i])
            return true;
    }
    throw Not_Found_Exception();
}

bool CommandHandling::cheak_first_part_of_input(vector<string>separated_input) {
    if ((separated_input[0] == GET) || (separated_input[0] == POST )
    || (separated_input[0] == PUT ))
        return true;
    else 
        throw Bad_Request_Exception();
}

void CommandHandling::cheak_input_for_each_command(vector<string>separated_input) {
    if(separated_input[1] == SIGNUP) {
        HandlingOfCommandSignup command_signup;
        command_signup.input_signup(separated_input, program_data, 
        be_login_or_signup_for_handling_command);
        be_login_or_signup_for_handling_command = IN;
    }
    else  if(separated_input[1] == LOGIN) {
        HandlingOfCommandLogin command_login;
        command_login.cheak_input_for_login(separated_input, program_data,
        be_login_or_signup_for_handling_command);
        be_login_or_signup_for_handling_command = IN;
    }
    else  if((separated_input[1] == FILMS) || (separated_input[1] == DELETE_FILMS) ||
    ((separated_input[1] == PUT_FILMS))) {
            HandlingOfCommandFilm command_film;
            command_film.input_film(program_data,separated_input);
    }
    else  if(separated_input[1] == FOLLOWERS) {
            HandlingOfCommandFollowers command_followers;
            command_followers.input_followers(separated_input, program_data);
    }
    else  if(separated_input[1] == MONEY) {
            HandlingOfCommandMoney command_money;
            command_money.input_money(separated_input, program_data);
    }
    else  if(separated_input[1] == PUBLISHED) {
            HandlingOfCommandPublished command_published;
            command_published.input_published(separated_input, program_data);
    }
    else  if(separated_input[1] == REPLIES) {
            HandlingOfCommandReplies command_reply;
            command_reply.input_reply(separated_input, program_data);
    }
    else  if((separated_input[1] == COMMENTS) || ((separated_input[1] == DELETE_COMMENTS))) {
            HandlingOfCommandComments command_comments;
            command_comments.input_comments(separated_input, program_data);
    }
    else  if(separated_input[1] == BUY) {
            HandlingOfCommandBuy command_buy;
            command_buy.input_buy(separated_input, program_data);
    }
    else  if(separated_input[1] == RATE) {
        HandlingOfCommandRate command_rate;
        command_rate.input_rate(separated_input, program_data);
    }
    else  if(separated_input[1] == PURCHASED) {
        HandlingOfCommandPurchased command_purchased;
        command_purchased.input_purchased(separated_input, program_data);
    }
    else if(separated_input[1] == LOGOUT) {
        ErrorHandlingLogout command_logout;
        command_logout.cheak_logout_error(be_login_or_signup_for_handling_command);
        be_login_or_signup_for_handling_command = OUT;
    }
}

void CommandHandling::cheack_input_format(vector<string>separated_input) {
    cheak_first_part_of_input(separated_input);
    cheak_second_part_of_input(separated_input);
    cheak_input_for_each_command(separated_input);
}