#ifndef FILMS_H
#define FILMS_H

#include <string>
#include <vector>

class Films {
public:
    Films(int _id, std::string _year, std::string _length, std::string _price,
    std::string _name, std::string _summary, std::string _director, std::string exist_or_delete);
    int get_id();
    void set_year(std::string _year);
    void set_length(std::string _length);
    void set_name(std::string _name);
    void set_summary(std::string _summary);
    void set_director(std::string _director);
    void delete_film();
    int get_price();
    std::string get_name();
    std::string get_exist_or_delete();
    void set_customers_rate_to_film(int rate, int customer_id);
    void set_rate();
    void set_comments_of_film(std::string content, int customer_id);
    float get_rate();
    std::string get_length();
    std::string get_year();
    std::string get_director();
    std::string get_summary();
    std::vector<std::vector<std::string> > get_comments_of_film();
    void delete_notification_film(std::string comment_id);
private:
    int id;
    std::string year;
    std::string length;
    std::string price;
    std::string name;
    std::string summary;
    std::string director;
    std::string exist_or_delete;
    float rate;
    std::vector<std::vector<int> > customers_rate_to_film;
    std::vector<std::vector<std::string> > comments_of_film;
};
#endif