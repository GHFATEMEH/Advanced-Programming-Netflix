#include "DetailsHandler.h"
#include "ProgramData.h"
#include "define.h"
#include "Films.h"
#include "HandlingOfCommandFilm.h"
#include "HandlingOfCommandBuy.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

DetailsHandler::DetailsHandler(string filePath, ProgramData* _program_data) :
    TemplateHandler(filePath) {
        program_data = _program_data;
}

void DetailsHandler::cheak_error_customer_call_detail_page() {
    if(program_data->get_be_login_or_signup_for_handling_command() == OUT)
        throw Server::Exception("You should login first");
}

void set_information(Request* request, ProgramData* program_data, map<string, string> &context,
string _id, vector<Films*>film) {
    HandlingOfCommandFilm command_film;
    HandlingOfCommandBuy command_buy;
    if(request->getQueryParam("comment") != "\0") {
        command_film.add_and_show_comment(_id, program_data, context,
        request->getQueryParam("comment"));
        context["comment"] = "comment";
    }
    else
        if((request->getQueryParam("rate") != "\0")) {
            command_buy.buy_film(_id, request->getQueryParam("rate"), program_data);
            context["rate"] = "rate";
    }
    else
        if(request->getQueryParam("buy") != "\0") {
            command_buy.cheak_error_for_buy(_id, film, program_data);
            context["buy"] = "buy";
    }
}

map<string, string> DetailsHandler::handle(Request *request) {
    map<string, string> context;
    HandlingOfCommandFilm command_film;
    vector<Films*>film = program_data->get_film_vector();
    cheak_error_customer_call_detail_page();
    if(request->getQueryParam("id") != "\0")
        _id = request->getQueryParam("id");
    set_information(request, program_data, context, _id, film);
    command_film.print_recommended_film_details(film, context, _id);
    return context;
}
