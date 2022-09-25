#ifndef PUBLISHER_HOME_H
#define PUBLISHER_HOME_H

#include "../server/server.hpp"

#include <map>
#include <string>

class ProgramData;

class PublisherHome : public TemplateHandler {
public:
  PublisherHome(std::string filePath, ProgramData* _program_data);
  std::map<std::string, std::string> handle(Request *request);
  void cheak_error_publisher_home_page();
private:
    ProgramData* program_data;
};
#endif