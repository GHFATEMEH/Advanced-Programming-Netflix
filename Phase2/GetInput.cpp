#include "GetInput.h"
#include "CommandHandling.h"
#include "define.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

GetInput::GetInput(){
    command_handling = new CommandHandling();
}

void GetInput::separate_input_by_delimiters(string input){
    int start_of_separate_input=0;
    int size_of_separate_input=0;
    for (int i = 0; i < input.size(); i++){
        if(input[i] == SPACE_CHAR){
            if(size_of_separate_input == 0){ 
                start_of_separate_input ++;
                continue;
            }
            else{
                separated_input.push_back(input.substr(start_of_separate_input,
                size_of_separate_input));
                size_of_separate_input = 0;
                start_of_separate_input = i + 1;
                continue;
            }
        }
        size_of_separate_input++;
    }
    separated_input.push_back(input.substr(start_of_separate_input,size_of_separate_input));
}

void GetInput::get_input_from_user() {
    string input;
    while(getline(cin, input)) {
        separate_input_by_delimiters(input);
        try {
            command_handling->cheack_input_format(separated_input);
        }catch(exception& new_exeption){
            cout << new_exeption.what() << "\n";
        }
        separated_input.clear();
    }
}