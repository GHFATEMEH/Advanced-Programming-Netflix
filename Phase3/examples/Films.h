#ifndef FILMS_H
#define FILMS_H

#include <string>
#include <vector>

class Films {
public:
    Films(int _id, std::string _year, std::string _length, std::string _price,
    std::string _name, std::string _summary, std::string _director, std::string exist_or_delete,
    std::string _rate);
    int get_id();
    void delete_film();
    int get_price();
    std::string get_name();
    std::string get_exist_or_delete();
    std::string  get_rate();
    std::string get_length();
    std::string get_year();
    std::string get_director();
    std::string get_summary();
    std::vector<std::string> get_comment();
    void add_comment(std::string _comment);
private:
    int id;
    std::string year;
    std::string length;
    std::string price;
    std::string name;
    std::string summary;
    std::string director;
    std::string exist_or_delete;
    std::string  rate;
    std::vector<std::string>comment;
};
#endif