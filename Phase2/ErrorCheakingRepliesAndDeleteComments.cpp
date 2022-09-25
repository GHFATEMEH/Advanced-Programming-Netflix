#include "ErrorCheakingRepliesAndDeleteComments.h"
#include "Films.h"
#include "Publisher.h"
#include "Exception.h"

#include <string>
#include <vector>

using namespace std;

bool ErrorCheakingRepliesAndDeleteComments::cheak_comment_id(string commant_id, vector<Films*>films,
int i) {
    vector<vector<string> >comments_of_film = films[i]->get_comments_of_film();
    for(int i = 0; i < comments_of_film.size(); i++) {
        if(comments_of_film[i][0] == commant_id)
            return true;
    }
    return false;
}

void ErrorCheakingRepliesAndDeleteComments::cheak_film_id_and_comment_is_for_publisher(string film_id,
Publisher* publisher, string commant_id) {
    int id = stoi(film_id);
    vector<Films*>films = publisher->get_films();
    for(int i = 0; i < films.size(); i++) {
        if((films[i]->get_id() == id) && (cheak_comment_id(commant_id, films, i)));
            return;
    }
    throw Permission_Denied_Exception();
}

