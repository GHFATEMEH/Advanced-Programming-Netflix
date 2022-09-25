#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>

class Not_Found_Exception : public std::exception {
public:
    virtual const char* what() const throw();
};

class Bad_Request_Exception : public std::exception {
public:
    virtual const char* what() const throw();
};

class Permission_Denied_Exception : public std::exception {
public:
    virtual const char* what() const throw();
};
#endif