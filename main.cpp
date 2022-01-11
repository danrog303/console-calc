#include <iostream>
#include "equation.h"
#include "help.h"
#include "cli.h"

int main(int argc, char** argv) {
    if(argc >= 3) {
        std::cout << "Invalid arguments count.\n";
        std::cout << "Type console-calc --help to learn how to use console-calc.";
    }
    else if(argc == 2 && (string(argv[1]) == "--help" || string(argv[1]) == "-h")) {
        help();
    }
	else if(argc == 1) {
        cli();
    }
    else if(argc == 2) {
        Equation eq(argv[1]);
        std::cout << eq.getEquation() << " = " << eq.evaluate();
    }
	return 0;
}