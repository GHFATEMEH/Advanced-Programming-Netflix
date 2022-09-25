#include "Exception.h"

#include <iostream>

using namespace std;

const char* Not_Found_Exception::what() const throw() {
    return "Not Found";
}

const char* Bad_Request_Exception::what() const throw() {
    return "Bad Request";
}

const char* Permission_Denied_Exception::what() const throw() {
    return "Permission Denied";
}