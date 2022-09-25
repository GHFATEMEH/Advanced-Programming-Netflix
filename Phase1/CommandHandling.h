#ifndef COMMAND_HANDLING_H
#define COMMAND_HANDLING_H

#include <vector>
#include <string>
#include <cstdlib>

class HandlingOfCommandSignup;
class HandlingOfCommandLogin;
class ProgramData;

class CommandHandling {
public:
    CommandHandling();
    void cheack_input_format(std::vector<std::string>separated_input);
    bool cheak_first_part_of_input(std::vector<std::string>separated_input);
    bool cheak_second_part_of_input(std::vector<std::string>separated_input);
    void cheak_input_for_each_command(std::vector<std::string>separated_input);
private:
    ProgramData* program_data;
};
#endif