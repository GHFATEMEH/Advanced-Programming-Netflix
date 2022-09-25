CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/SignupHandler.o: examples/SignupHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/ProgramData.h examples/HandlingOfCommandSignup.h examples/define.h
	$(CC) $(CF) -c examples/SignupHandler.cpp -o $(BUILD_DIR)/SignupHandler.o

$(BUILD_DIR)/LoginHandler.o: examples/LoginHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/ProgramData.h examples/HandlingOfCommandLogin.h examples/define.h
	$(CC) $(CF) -c examples/LoginHandler.cpp -o $(BUILD_DIR)/LoginHandler.o

$(BUILD_DIR)/AddFilmHandler.o: examples/AddFilmHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/ProgramData.h examples/define.h examples/HandlingOfcommandFilm.h
	$(CC) $(CF) -c examples/AddFilmHandler.cpp -o $(BUILD_DIR)/AddFilmHandler.o

$(BUILD_DIR)/LogoutHandler.o: examples/LogoutHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/ProgramData.h examples/define.h
	$(CC) $(CF) -c examples/LogoutHandler.cpp -o $(BUILD_DIR)/LogoutHandler.o 

$(BUILD_DIR)/PublisherHome.o: examples/PublisherHome.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/ProgramData.h examples/define.h examples/Publisher.h examples/Films.h examples/ErrorCheakingFilm.h examples/HandlingOfCommandFilm.h
	$(CC) $(CF) -c examples/PublisherHome.cpp -o $(BUILD_DIR)/PublisherHome.o 

$(BUILD_DIR)/CustomerProfileHandler.o : examples/CustomerProfileHandler.cpp examples/ProgramData.h examples/define.h examples/Customer.h examples/Films.h examples/HandlingOfCommandFilm.h server/server.hpp
	$(CC) $(CF) -c examples/CustomerProfileHandler.cpp -o $(BUILD_DIR)/CustomerProfileHandler.o 

$(BUILD_DIR)/DeleteFilmHandler.o : examples/DeleteFilmHandler.cpp examples/ProgramData.h examples/Films.h server/server.hpp examples/Customer.h server/server.hpp
	$(CC) $(CF) -c examples/DeleteFilmHandler.cpp -o $(BUILD_DIR)/DeleteFilmHandler.o 

$(BUILD_DIR)/CustomerHomeHandler.o : examples/CustomerHomeHandler.cpp examples/ProgramData.h examples/define.h examples/Films.h examples/HandlingOfCommandFilm.h server/server.hpp
	$(CC) $(CF) -c examples/CustomerHomeHandler.cpp -o $(BUILD_DIR)/CustomerHomeHandler.o 

$(BUILD_DIR)/FilmDetailsHandler.o : examples/FilmDetailsHandler.cpp examples/define.h examples/ProgramData.h examples/HandlingOfCommandFilm.h examples/Customer.h server/server.hpp
	$(CC) $(CF) -c examples/FilmDetailsHandler.cpp -o $(BUILD_DIR)/FilmDetailsHandler.o 

$(BUILD_DIR)/DetailsHandler.o : examples/DetailsHandler.cpp examples/ProgramData.h examples/define.h examples/Films.h examples/HandlingOfCommandFilm.h server/server.hpp examples/HandlingOfCommandBuy.h
	$(CC) $(CF) -c examples/DetailsHandler.cpp -o $(BUILD_DIR)/DetailsHandler.o

$(BUILD_DIR)/MyServer.o: examples/MyServer.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/MyServer.cpp -o $(BUILD_DIR)/MyServer.o

$(BUILD_DIR)/Publisher.o: examples/Publisher.cpp examples/Customer.h  examples/define.h examples/ProgramData.h examples/Films.h
	$(CC) $(CF) -c examples/Publisher.cpp -o $(BUILD_DIR)/Publisher.o

$(BUILD_DIR)/ProgramData.o: examples/ProgramData.cpp examples/Publisher.h examples/Customer.h examples/define.h examples/Films.h
	$(CC) $(CF) -c examples/ProgramData.cpp -o $(BUILD_DIR)/ProgramData.o

$(BUILD_DIR)/HandlingOfCommandSignup.o: examples/HandlingOfCommandSignup.cpp examples/define.h examples/ProgramData.h examples/Publisher.h examples/Customer.h examples/ErrorCheakingSignup.h
	$(CC) $(CF) -c examples/HandlingOfCommandSignup.cpp -o $(BUILD_DIR)/HandlingOfCommandSignup.o

$(BUILD_DIR)/HandlingOfCommandLogin.o: examples/HandlingOfCommandLogin.cpp examples/define.h examples/ProgramData.h examples/ErrorCheakingLogin.h examples/Publisher.h
	$(CC) $(CF) -c examples/HandlingOfCommandLogin.cpp -o $(BUILD_DIR)/HandlingOfCommandLogin.o

$(BUILD_DIR)/HandlingOfCommandFilm.o : examples/HandlingOfCommandFilm.cpp examples/Publisher.h examples/ProgramData.h examples/Films.h examples/define.h examples/Customer.h
	$(CC) $(CF) -c examples/HandlingOfCommandFilm.cpp -o $(BUILD_DIR)/HandlingOfCommandFilm.o

$(BUILD_DIR)/HandlingOfCommandBuy.o : examples/HandlingOfCommandBuy.cpp examples/Customer.h examples/define.h examples/Films.h examples/ProgramData.h
	$(CC) $(CF) -c examples/HandlingOfCommandBuy.cpp -o $(BUILD_DIR)/HandlingOfCommandBuy.o

$(BUILD_DIR)/ErrorCheakingSignup.o: examples/ErrorCheakingSignup.cpp  examples/define.h examples/ProgramData.h server/server.hpp
	$(CC) $(CF) -c examples/ErrorCheakingSignup.cpp -o $(BUILD_DIR)/ErrorCheakingSignup.o

$(BUILD_DIR)/ErrorCheakingLogin.o: examples/ErrorCheakingLogin.cpp examples/ProgramData.h server/server.hpp
	$(CC) $(CF) -c examples/ErrorCheakingLogin.cpp -o $(BUILD_DIR)/ErrorCheakingLogin.o

$(BUILD_DIR)/ErrorCheakingFilm.o: examples/ErrorCheakingFilm.cpp examples/ProgramData.h examples/define.h server/server.hpp
	$(CC) $(CF) -c examples/ErrorCheakingFilm.cpp -o $(BUILD_DIR)/ErrorCheakingFilm.o

$(BUILD_DIR)/ErrorCheakingBuy.o: examples/ErrorCheakingBuy.cpp examples/Films.h examples/define.h examples/Customer.h examples/ProgramData.h server/server.hpp
	$(CC) $(CF) -c examples/ErrorCheakingBuy.cpp -o $(BUILD_DIR)/ErrorCheakingBuy.o

$(BUILD_DIR)/Films.o: examples/Films.cpp examples/define.h
	$(CC) $(CF) -c examples/Films.cpp -o $(BUILD_DIR)/Films.o

$(BUILD_DIR)/Customer.o: examples/Customer.cpp examples/define.h examples/Films.h
	$(CC) $(CF) -c examples/Customer.cpp -o $(BUILD_DIR)/Customer.o

$(BUILD_DIR)/Handler.o: examples/Handler.cpp examples/MyServer.h examples/ProgramData.h examples/SignupHandler.h examples/LoginHandler.h examples/AddFilmHandler.h examples/LogoutHandler.h examples/PublisherHome.h examples/CustomerProfileHandler.h examples/DeleteFilmHandler.h examples/CustomerHomeHandler.h examples/FilmDetailsHandler.h examples/DetailsHandler.h
	$(CC) $(CF) -c examples/Handler.cpp -o $(BUILD_DIR)/Handler.o

$(BUILD_DIR)/main.o: examples/main.cpp examples/MyServer.h examples/ProgramData.h examples/Handler.h
	$(CC) $(CF) -c examples/main.cpp -o $(BUILD_DIR)/main.o

myserver.out: $(BUILD_DIR)/MyServer.o $(BUILD_DIR)/main.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Publisher.o $(BUILD_DIR)/ProgramData.o $(BUILD_DIR)/HandlingOfCommandSignup.o $(BUILD_DIR)/ErrorCheakingSignup.o $(BUILD_DIR)/Customer.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/ErrorCheakingLogin.o $(BUILD_DIR)/HandlingOfCommandLogin.o $(BUILD_DIR)/AddFilmHandler.o $(BUILD_DIR)/Films.o $(BUILD_DIR)/HandlingOfCommandFilm.o $(BUILD_DIR)/ErrorCheakingFilm.o $(BUILD_DIR)/LogoutHandler.o $(BUILD_DIR)/PublisherHome.o $(BUILD_DIR)/CustomerProfileHandler.o $(BUILD_DIR)/DeleteFilmHandler.o $(BUILD_DIR)/CustomerHomeHandler.o $(BUILD_DIR)/FilmDetailsHandler.o  $(BUILD_DIR)/DetailsHandler.o $(BUILD_DIR)/HandlingOfCommandBuy.o $(BUILD_DIR)/ErrorCheakingBuy.o $(BUILD_DIR)/Handler.o
	$(CC) $(CF) $(BUILD_DIR)/MyServer.o $(BUILD_DIR)/main.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Publisher.o $(BUILD_DIR)/ProgramData.o $(BUILD_DIR)/HandlingOfCommandSignup.o $(BUILD_DIR)/ErrorCheakingSignup.o $(BUILD_DIR)/Customer.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/ErrorCheakingLogin.o  $(BUILD_DIR)/HandlingOfCommandLogin.o $(BUILD_DIR)/AddFilmHandler.o $(BUILD_DIR)/Films.o $(BUILD_DIR)/HandlingOfCommandFilm.o $(BUILD_DIR)/ErrorCheakingFilm.o $(BUILD_DIR)/LogoutHandler.o $(BUILD_DIR)/PublisherHome.o $(BUILD_DIR)/CustomerProfileHandler.o $(BUILD_DIR)/DeleteFilmHandler.o $(BUILD_DIR)/CustomerHomeHandler.o $(BUILD_DIR)/FilmDetailsHandler.o $(BUILD_DIR)/DetailsHandler.o $(BUILD_DIR)/HandlingOfCommandBuy.o $(BUILD_DIR)/ErrorCheakingBuy.o $(BUILD_DIR)/Handler.o -o myserver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
