#include "ErrorCheakingBuy.h"
#include "Exception.h"
#include "define.h"

#include <string>
#include <vector>

using namespace std;

void ErrorCheakingBuy::cheak_buy_format(vector<string>separated_input) {
    for(int i = 1; (2*i + 1) < separated_input.size(); i++){
        if (separated_input[2*i + 1] == FILM_ID)
            return;
        else
            throw Bad_Request_Exception();
    }
}

void ErrorCheakingBuy::cheak_number_of_input_buy(vector<string>separated_input) {
    int number_of_input = separated_input.size();
    if(number_of_input == 5)
        return;
    else
        throw Bad_Request_Exception();
}