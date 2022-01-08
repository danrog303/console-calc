#include "cli.h"

[[noreturn]] void cli() {
    std::cout << "Welcome to console-calc's CLI mode.\n";
    std::cout << "Please type any equation you want to calculate and press enter to get a result.\n";
    std::cout << "Press Ctrl+C to close the application.\n\n";

    do {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);

        Equation equation(line);
        std::cout << equation.getEquation() << " = " << equation.evaluate() << "\n\n";
    } while(true);
}
