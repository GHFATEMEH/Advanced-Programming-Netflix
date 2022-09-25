#include <cstdlib>
#include "GetInput.h"
using namespace std;
int main() {
    GetInput* get_input = new GetInput();
    get_input->get_input_from_user();
    return 0;
}