#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Customer.h"

#include <vector>
#include <string>

class Films;

class Publisher : public Customer {
public:
    Publisher(std::string _email, std::string _username, std::string _password, std::string _age
    , int id);
    void add_film(Films * new_film);
    std::vector<Films*> get_films();
private:
    std::vector<Films*>films;
};
#endif