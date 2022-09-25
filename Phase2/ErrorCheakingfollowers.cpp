#include "ErrorCheakingFollowers.h"
#include "ProgramData.h"
#include "define.h"
#include "Exception.h"
#include "Publisher.h"

using namespace std;

void ErrorCheakingFollowers::cheak_customer_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == PUBLISHER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingFollowers::cheak_publisher_in(ProgramData* program_data) {
    if(program_data->get_user_in_system() == CUSTOMER)
        throw Permission_Denied_Exception();
}

void ErrorCheakingFollowers::cheak_user_id_exist(ProgramData* program_data, string user_id) {
    vector<Publisher*>publisher = program_data->get_publisher();
    for(int i = 0; i < publisher.size(); i++) {
        if(to_string(publisher[i]->get_id()) == user_id)
            return;
    }
    throw Not_Found_Exception();
}