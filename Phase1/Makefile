all: a.out

a.out: main.o GetInput.o CommandHandling.o HandlingOfCommandSignup.o Exception.o HandlingOfCommandLogin.o Films.o Publisher.o Customer.o ProgramData.o HandlingOfCommandFilm.o HandlingOfCommandFollowers.o HandlingOfCommandMoney.o HandlingOfCommandBuy.o HandlingOfCommandRate.o ErrorCheakingRate.o ErrorCheakingFilm.o HandlingOfCommandComments.o HandlingOfCommandPublished.o HandlingOfCommandReplies.o ErrorCheakingRepliesAndDeleteComments.o ListOfFilmSorted.o HandlingOfCommandPurchased.o ErrorCheakingSignup.o ErrorCheakingFollowers.o ErrorCheakingMoney.o ErrorCheakingComments.o ErrorCheakingBuy.o
	g++ -o a.out main.o GetInput.o CommandHandling.o HandlingOfCommandSignup.o Exception.o HandlingOfCommandLogin.o Films.o Publisher.o Customer.o ProgramData.o HandlingOfCommandFilm.o HandlingOfCommandFollowers.o HandlingOfCommandMoney.o HandlingOfCommandBuy.o HandlingOfCommandRate.o ErrorCheakingRate.o ErrorCheakingFilm.o HandlingOfCommandComments.o HandlingOfCommandPublished.o HandlingOfCommandReplies.o ErrorCheakingRepliesAndDeleteComments.o ListOfFilmSorted.o HandlingOfCommandPurchased.o ErrorCheakingSignup.o ErrorCheakingFollowers.o ErrorCheakingMoney.o ErrorCheakingComments.o ErrorCheakingBuy.o

main.o: main.cpp GetInput.h
	g++  -std=c++11 -c main.cpp

GetInput.o: GetInput.cpp CommandHandling.h define.h
	g++ -std=c++11 -c GetInput.cpp

CommandHandling.o: CommandHandling.cpp HandlingOfCommandSignup.h  Exception.h define.h HandlingOfCommandLogin.h ProgramData.h Publisher.h Customer.h HandlingOfCommandFilm.h HandlingOfCommandFollowers.h HandlingOfCommandMoney.h HandlingOfCommandBuy.o HandlingOfCommandRate.o HandlingOfCommandComments.o HandlingOfCommandPublished.h HandlingOfCommandReplies.h HandlingOfCommandPurchased.h
	g++ -std=c++11 -c CommandHandling.cpp

HandlingOfCommandSignup.o: HandlingOfCommandSignup.cpp  define.h Publisher.h ProgramData.h Customer.h ErrorCheakingSignup.h
	g++ -std=c++11 -c HandlingOfCommandSignup.cpp

HandlingOfCommandLogin.o: HandlingOfCommandLogin.cpp Exception.h define.h ProgramData.h
	g++ -std=c++11 -c HandlingOfCommandLogin.cpp

HandlingOfCommandFilm.o: HandlingOfCommandFilm.cpp ProgramData.h define.h Publisher.h Films.h Customer.h ErrorCheakingFilm.h Exception.h
	g++ -std=c++11 -c HandlingOfCommandFilm.cpp

Exception.o: Exception.cpp
	g++ -std=c++11 -c Exception.cpp

Publisher.o: Publisher.cpp Films.h Customer.h Exception.h define.h
	g++ -std=c++11 -c Publisher.cpp

Films.o: Films.cpp define.h
	g++ -std=c++11 -c Films.cpp

Customer.o: Customer.cpp define.h
	g++ -std=c++11 -c Customer.cpp

ProgramData.o: ProgramData.cpp Customer.h Films.h Publisher.h Exception.h
	g++ -std=c++11 -c ProgramData.cpp

HandlingOfCommandFollowers.o: HandlingOfCommandFollowers.cpp Publisher.h Customer.h ProgramData.h define.h Exception.h Publisher.h ErrorCheakingFollowers.h
	g++ -std=c++11 -c HandlingOfCommandFollowers.cpp

HandlingOfCommandMoney.o : HandlingOfCommandMoney.cpp ProgramData.h Customer.h Publisher.h define.h Films.h ErrorCheakingMoney.h
	g++ -std=c++11 -c HandlingOfCommandMoney.cpp

HandlingOfCommandBuy.o : HandlingOfCommandBuy.cpp ProgramData.h Customer.h Publisher.h Films.h Exception.h define.h ErrorCheakingBuy.h
	g++ -std=c++11 -c HandlingOfCommandBuy.cpp

HandlingOfCommandRate.o : HandlingOfCommandRate.cpp ErrorCheakingRate.h ProgramData.h define.h Customer.h Films.h
	g++ -std=c++11 -c HandlingOfCommandRate.cpp

HandlingOfCommandComments.o : HandlingOfCommandComments.cpp ErrorCheakingComments.h ProgramData.h Customer.h Films.h Publisher.h define.h ErrorCheakingRepliesAndDeleteComments.h
	g++ -std=c++11 -c HandlingOfCommandComments.cpp

HandlingOfCommandPublished.o : HandlingOfCommandPublished.cpp ProgramData.h define.h ListOfFilmSorted.h ErrorCheakingFilm.h
	g++ -std=c++11 -c HandlingOfCommandPublished.cpp

HandlingOfCommandReplies.o : HandlingOfCommandReplies.cpp ProgramData.h Publisher.h define.h Films.h Customer.h ErrorCheakingRepliesAndDeleteComments.h
	g++ -std=c++11 -c HandlingOfCommandReplies.cpp

HandlingOfCommandPurchased.o : HandlingOfCommandPurchased.cpp ProgramData.h Films.h define.h
	g++ -std=c++11 -c HandlingOfCommandPurchased.cpp

ErrorCheakingRate.o : ErrorCheakingRate.cpp ProgramData.h Exception.h Films.h Customer.h Publisher.h define.h
	g++ -std=c++11 -c ErrorCheakingRate.cpp

ErrorCheakingFilm.o : ErrorCheakingFilm.cpp ProgramData.h ProgramData.h Films.h define.h
	g++ -std=c++11 -c ErrorCheakingFilm.cpp

ErrorCheakingRepliesAndDeleteComments.o : ErrorCheakingRepliesAndDeleteComments.cpp Films.h Publisher.h Exception.h
	g++ -std=c++11 -c ErrorCheakingRepliesAndDeleteComments.cpp

ListOfFilmSorted.o : ListOfFilmSorted.cpp ProgramData.h Publisher.h define.h Films.h
	g++ -std=c++11 -c ListOfFilmSorted.cpp

ErrorCheakingSignup.o : ErrorCheakingSignup.cpp Exception.h define.h ProgramData.h
	g++ -std=c++11 -c ErrorCheakingSignup.cpp

ErrorCheakingFollowers.o : ErrorCheakingFollowers.cpp ProgramData.h define.h Exception.h Publisher.h
	g++ -std=c++11 -c ErrorCheakingFollowers.cpp

ErrorCheakingMoney.o : ErrorCheakingMoney.cpp ProgramData.h Exception.h define.h
	g++ -std=c++11 -c ErrorCheakingMoney.cpp

ErrorCheakingComments.o : ErrorCheakingComments.cpp ProgramData.h Exception.h Customer.h define.h
	g++ -std=c++11 -c ErrorCheakingComments.cpp

ErrorCheakingBuy.o : ErrorCheakingBuy.cpp Exception.h define.h
	g++ -std=c++11 -c ErrorCheakingBuy.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out