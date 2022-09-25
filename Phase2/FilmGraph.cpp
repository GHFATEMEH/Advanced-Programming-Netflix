#include "FilmGraph.h"
#include "define.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void FilmGraph::add_film_to_graph() {
    film_graph.push_back(vector<int>());
    int size_of_row = film_graph.size();
    for(int k = 0; k < size_of_row - 1; k++)
        film_graph[k].push_back(ZERO);
    for(int i = 0; i < film_graph.size();i++)
        film_graph[size_of_row - 1].push_back(ZERO);
}

void FilmGraph::update_film_graph(std::vector<int>films_that_customer_bought) {
    int size = films_that_customer_bought.size();
    int film_id_bought = films_that_customer_bought[size - 1];
    for(int i = 0; i < films_that_customer_bought.size() - 1; i++) {
        int row = films_that_customer_bought[i] - 1;
        int column = film_id_bought - 1;
        film_graph[row][column] ++;
        film_graph[column][row] ++;
    }
}

void FilmGraph::print() {
    for(int i =0; i<film_graph.size();i++) {
        for(int j=0;j<film_graph[i].size();j++) {
            cout << film_graph[i][j];
        }
        cout << "\n";
    }
}

void FilmGraph::change_place_of_films(int i, int j) {
    int id = recommend_film[i][0];
    int time_of_film_bought = recommend_film[i][1];
    recommend_film[i][0] = recommend_film[j][0];
    recommend_film[i][1] = recommend_film[j][1];
    recommend_film[j][0] = id;
    recommend_film[j][1] = time_of_film_bought;
}

void FilmGraph::sort_recommend_film() {
    for(int i = 0; i < recommend_film.size(); i++) {
        for(int j = i + 1; j < recommend_film.size(); j++) {
            if(recommend_film[i][1] > recommend_film[j][1])
                change_place_of_films(i, j);
        }
    }
}

vector<vector<int> >FilmGraph::find_recommend_film(int film_id) {
    for(int i = 0; i < film_graph.size(); i++) {
        recommend_film.push_back(vector<int>());
        recommend_film[i].push_back(i + 1);
        recommend_film[i].push_back(film_graph[film_id - 1][i]);
    }
    sort_recommend_film();
    return recommend_film;
}


