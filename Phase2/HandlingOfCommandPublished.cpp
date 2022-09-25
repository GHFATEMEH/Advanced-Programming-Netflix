#include "HandlingOfCommandPublished.h"
#include "ProgramData.h"
#include "define.h"
#include "ListOfFilmSorted.h"
#include "ErrorCheakingFilm.h"

#include <string>
#include <vector>

using namespace std;

void HandlingOfCommandPublished::input_published(vector<string>separated_input,
ProgramData* program_data) {
    error_cheaking_film.cheak_publisher_in(program_data);
    list_of_film_sorted.sort_list_of_film(separated_input, program_data, PUBLISHER);
}