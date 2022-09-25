#ifndef DELETE_FILM_HANDLER_H
#define DELETE_FILM_HANDLER_H

#include "../server/server.hpp"

class ProgramData;

class DeleteFilmHandler : public RequestHandler {
public:
  DeleteFilmHandler(ProgramData* _program_data);
  Response *callback(Request* request);
private:
  ProgramData* program_data;
};
#endif