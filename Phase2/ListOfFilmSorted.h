#ifndef LIST_OF_FILM_SORTED
#define LIST_OF_FILM_SORTED

#include <vector>
#include <string>
class Films;
class Publisher;
class ProgramData;

class ListOfFilmSorted {
public:
    void sort_list_of_film(std::vector<std::string>separated_input,ProgramData* program_data,
    std::string type_of_string);
    void print_list_of_film_publishned(std::vector<std::vector<std::string> >list_of_film_publishned);
    int search_for_property(Publisher* publisher, std::vector<std::vector<std::string> >
    &list_of_film_publishned, std::vector<std::string>separated_input, std::vector<Films*>all_films,
    std::string type_of_string);
    void sort_vector_with_id(std::vector<std::vector<std::string> >
    list_of_film_publishned);
    void sort_vector_of_propertys(int j, std::vector<std::vector<std::string> >
    &list_of_film_publishned, std::vector<std::string>seperated_input);
    void find_films_property(std::string type_of_property, Publisher* publisher,
    std::vector<std::vector<std::string> >&list_of_film_publishned, std::string property,
    std::vector<Films*>all_films, std::string type_of_string);
    void save_films_property(std::vector<Films*>films, int i,
    std::vector<std::vector<std::string> >&list_of_film_publishned);
    void print_title();
};
#endif