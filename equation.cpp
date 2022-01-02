#include "equation.h"

Equation::Equation(std::string equation) {
    this->equation = std::move(equation);
}

std::string Equation::getEquation() {
    return this->equation;
}

long double Equation::evaluate() {
    std::stack<long double> values;
    std::stack<char> operators;

    for (int i = 0; i < this->equation.length(); i++) {
        if (this->equation[i] == ' ') {
            continue;
        }

        if ((this->equation[i] >= '0' && this->equation[i] <= '9') || this->equation[i] == '.') {
            std::stringstream buffer;
            while (i < this->equation.length() && ((this->equation[i] >= '0' &&
                  this->equation[i] <= '9') || this->equation[i] == '.')) {
                buffer << this->equation[i++];
            }
            values.push(std::stold(buffer.str()));
            i--;
        }
        else if (this->equation[i] == '(') {
            operators.push(this->equation[i]);
        }

        else if (this->equation[i] == ')') {
            while (operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                long double value2 = values.top();
                values.pop();
                long double value1 = values.top();
                values.pop();

                values.push(applyOperator(op, value1, value2));
            }
            operators.pop();
        }

        else if (this->equation[i] == '+' || this->equation[i] == '-' ||
                this->equation[i] == '*' || this->equation[i] == '/') {
            while (!operators.empty() && hasPrecedence(this->equation[i], operators.top())) {
                char op = operators.top();
                operators.pop();

                long double value2 = values.top();
                values.pop();
                long double value1 = values.top();
                values.pop();

                values.push(Equation::applyOperator(op, value1, value2));
            }

            operators.push(this->equation[i]);
        }
    }

    while(!operators.empty()){
        long double value2 = values.top();
        values.pop();
        long double value1 = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(Equation::applyOperator(op, value1, value2));
    }

    return values.top();
}

long double Equation::applyOperator(char op, long double a, long double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool Equation::hasPrecedence(char operator1, char operator2) {
    if (operator2 == '(' || operator2 == ')')
        return false;
    if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'))
        return false;
    else
        return true;
}
