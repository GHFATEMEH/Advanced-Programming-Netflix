#ifndef CUSSTOMER_PROFILE_HANDLER_H
#define CUSSTOMER_PROFILE_HANDLER_H

#include "../server/server.hpp"

#include <map>
#include <string>

class ProgramData;

class CustomerProfileHandler : public TemplateHandler {
public:
  CustomerProfileHandler(std::string filePath, ProgramData* _program_data);
  std::map<std::string, std::string> handle(Request *request);
  void cheak_error_user_in_for_customer_profile();
private:
    ProgramData* program_data;
};
#endif



