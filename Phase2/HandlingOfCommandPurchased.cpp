#include "HandlingOfCommandPurchased.h"
#include "ProgramData.h"
#include "Films.h"
#include "define.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void HandlingOfCommandPurchased::print_all_films(ProgramData* program_data) {
    vector<Films*>films = program_data->get_film_vector();
    list_of_film_sorted.print_title();
    for(int i = 0; i < films.size(); i++) {
        cout << i + 1 << DOT << SPACE << to_string(films[i]->get_id()) << SPACE << LINE << SPACE 
        << films[i]->get_name() << SPACE << LINE << SPACE <<films[i]->get_length() 
        << SPACE << LINE << SPACE << films[i]->get_price() <<
        SPACE << LINE << SPACE << films[i]->get_rate() << SPACE << LINE << SPACE <<
        films[i]->get_year() << SPACE << LINE << SPACE << films[i]->get_director() <<
        "\n";
    }
}

void HandlingOfCommandPurchased::input_purchased(vector<string>separated_input,
ProgramData* program_data) {
    if(separated_input[3] == "\0")
        print_all_films(program_data);
    else 
        list_of_film_sorted.sort_list_of_film(separated_input, program_data, CUSTOMER);
}