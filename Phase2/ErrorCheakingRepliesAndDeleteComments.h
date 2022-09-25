#ifndef ERROR_CHEAKING_REPLIES_AND_DELETE_COMMENT_H
#define ERROR_CHEAKING_REPLIES_AND_DELETE_COMMENT_H

#include "ErrorCheakingFilm.h"

#include <string>

class ProgramData;
class Publisher;
class Films;

class ErrorCheakingRepliesAndDeleteComments : public ErrorCheakingFilm {
public:
    void cheak_film_id_and_comment_is_for_publisher(std::string film_id, Publisher* publisher,
    std::string commant_id);
    bool cheak_comment_id(std::string commant_id, std::vector<Films*>films, int i);
};
#endif