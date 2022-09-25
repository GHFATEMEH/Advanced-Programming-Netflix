#include "Handler.h"
#include "MyServer.h"
#include "ProgramData.h"
#include "SignupHandler.h"
#include "LoginHandler.h"
#include "AddFilmHandler.h"
#include "LogoutHandler.h"
#include "PublisherHome.h"
#include "CustomerProfileHandler.h"
#include "DeleteFilmHandler.h"
#include "CustomerHomeHandler.h"
#include "FilmDetailsHandler.h"
#include "DetailsHandler.h"

Handler::Handler(ProgramData* _program_data, MyServer server) {
    server.setNotFoundErrPage("static/404.html");
    server.get("/home.jpg", new ShowImage("static/home.jpg"));
    server.get("/movie.jpg", new ShowImage("static/movie.jpg"));
    server.get("/profile.png", new ShowImage("static/profile.png"));
    server.get("/", new ShowPage("static/home_page.html"));
    server.get("/signup", new ShowPage("static/signup.html"));
    server.post("/signup", new SignupHandler(_program_data));
    server.get("/login", new ShowPage("static/login.html"));
    server.post("/login", new LoginHandler(_program_data));
    server.get("/add_film", new ShowPage("static/add_film.html"));
    server.post("/add_film", new AddFilmHandler(_program_data));
    server.get("/logout", new LogoutHandler(_program_data));
    server.get("/publisher_home", new PublisherHome("template/publisher_home.html", _program_data));
    server.get("/delete_film", new DeleteFilmHandler(_program_data));
    server.get("/customer_profile", new CustomerProfileHandler("template/customer_profile.html",
    _program_data));
    server.get("/customer_home", new CustomerHomeHandler("template/customer_home.html",
    _program_data));
    server.get("/film_details", new FilmDetailsHandler("template/film_details.html", _program_data));
    server.get("/see_film_details", new DetailsHandler("template/see_film_details.html",
    _program_data));
    server.run();
}
