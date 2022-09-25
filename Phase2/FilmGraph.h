#ifndef FILM_GRAPH_H
#define FILM_GRAPH_H

#include <vector>
#include <string>

class FilmGraph {
public:
    void add_film_to_graph();
    void update_film_graph(std::vector<int>films_that_customer_bought);
    std::vector<std::vector<int> >find_recommend_film(int film_id);
    void print();
    void sort_recommend_film();
    void change_place_of_films(int i, int j);
private:
    std::vector<std::vector<int> >film_graph;
    std::vector<std::vector<int> >recommend_film;
};
#endif