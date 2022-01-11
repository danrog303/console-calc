#ifndef CONSOLE_CALC_EQUATION_H
#define CONSOLE_CALC_EQUATION_H
#include <stack>
#include <algorithm>
#include <sstream>
#include <string>
#include <utility>

class Equation {
private:
    std::string equation;
    static bool hasPrecedence(char op1, char op2);
    static long double applyOperator(char op, long double a, long double b);
public:
    explicit Equation(std::string equation);
    long double evaluate();
    std::string getEquation();
};

#endif //CONSOLE_CALC_EQUATION_H
