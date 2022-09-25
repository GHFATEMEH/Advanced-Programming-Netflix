#ifndef HANDLER_H
#define HANDLER_H

#include "MyServer.h"

class ProgramData;

class Handler {
public:
    Handler(ProgramData* _program_data, MyServer server);
};
#endif