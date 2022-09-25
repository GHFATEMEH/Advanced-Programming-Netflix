#ifndef GET_INPUT_H
#define GET_INPUT_H

#include <vector>
#include <string>

class CommandHandling;

class GetInput {
public:
    GetInput();
    void get_input_from_user();
    void separate_input_by_delimiters(std::string input);
private:
    std::vector<std::string>separated_input;
    CommandHandling* command_handling; 
};
#endif