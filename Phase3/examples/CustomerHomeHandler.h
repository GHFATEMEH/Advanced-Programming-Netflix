#ifndef PUBLISHER_HOME_HANDLER_H
#define PUBLISHER_HOME_HANDLER_H

#include "../server/server.hpp"

#include <map>
#include <string>

class ProgramData;

class CustomerHomeHandler : public TemplateHandler {
public:
  CustomerHomeHandler(std::string filePath, ProgramData* _program_data);
  std::map<std::string, std::string> handle(Request *request);
  void cheak_error_customer_home_page();
private:
    ProgramData* program_data;
};
#endif