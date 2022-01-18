#include <iostream>
#include "equation.h"
#include "help.h"
#include "cli.h"

// main function
int main(int argc, char** argv) {
    // invalid arguments count
    if(argc >= 3) {
        std::cout << "Invalid arguments count.\n";
        std::cout << "Type console-calc --help to learn how to use console-calc.";
    }
    // help message (-h)
    else if(argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        help();
    }
    // cli mode (no arguments)
    else if(argc == 1) {
        cli();
    }
    // calculate equation
    else if(argc == 2) {
        Equation eq(argv[1]);
        std::cout << eq.getEquation() << " = " << eq.evaluate();
    }
    return 0;
}
