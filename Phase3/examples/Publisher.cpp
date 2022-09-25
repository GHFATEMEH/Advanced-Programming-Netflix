#include "Publisher.h"
#include "Films.h"
#include "Customer.h"
#include "define.h"
#include "ProgramData.h"

#include <vector>
#include <string>

using namespace std;

Publisher::Publisher(string _email, string _username, string _password, string _age, int _id)
    : Customer(_email, _username, _password, _age, _id) {}

void Publisher::add_film(Films * new_film) {
    films.push_back(new_film);
}

vector<Films*> Publisher::get_films() {
    return films;
}