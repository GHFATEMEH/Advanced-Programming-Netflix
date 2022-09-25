#include "ErrorHandlingLogout.h"
#include "define.h"
#include "Exception.h"

#include <string>
#include <iostream>

using namespace std;

void ErrorHandlingLogout::cheak_logout_error(std::string user_in_or_out) {
    if(user_in_or_out == OUT)
        throw Bad_Request_Exception();
    cout << OK << "\n";
}
