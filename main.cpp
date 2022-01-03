#include <iostream>
#include "equation.h"
#include "help.h"
#include "cli.h"

using namespace std;
int main(int argc, char** argv) {
    if(argc >= 3) {
        cout << "Invalid arguments count.\n";
        cout << "Type console-calc --help to learn how to use console-calc.";
    }
    else if(argc == 2 && (string(argv[1]) == "--help" || string(argv[1]) == "-h")) {
        help();
    }
	
	return 0;
}