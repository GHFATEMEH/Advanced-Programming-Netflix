#include "DeleteFilmHandler.h"
#include "ProgramData.h"
#include "Films.h"

#include <string>
#include <vector>

using namespace std;

DeleteFilmHandler::DeleteFilmHandler(ProgramData* _program_data) {
    program_data = _program_data;
}

Response* DeleteFilmHandler::callback(Request* request) {
    vector<Films*>films = program_data->get_film_vector();
    string id = request->getQueryParam("id");
    for(int i = 0; i < films.size(); i++) {
        if(films[i]->get_id() == stoi(id))
            films[i]->delete_film();
    }
    Response *response = Response::redirect("/publisher_home");
    return response;
}
