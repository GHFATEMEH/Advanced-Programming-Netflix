#include "MyServer.h"
#include "ProgramData.h"
#include "Handler.h"

using namespace std;

int main(int argc, char **argv) {
    try {
        MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
        ProgramData* _program_data = new ProgramData();
        Handler(_program_data, server);
    }catch(Server::Exception exception) {
        cerr << exception.getMessage() << "\n";
    }
    return 0;
}