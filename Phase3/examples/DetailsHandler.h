#ifndef DETAILS_HANDLER_H
#define DETAILS_HANDLER_H

#include "../server/server.hpp"

#include <string>
#include <map>

class ProgramData;

class DetailsHandler : public TemplateHandler {
public:
  DetailsHandler(std::string filePath, ProgramData* _program_data);
  std::map<std::string, std::string> handle(Request *request);
  void cheak_error_customer_call_detail_page();
private:
    ProgramData* program_data;
    std::string _id;
};
#endif