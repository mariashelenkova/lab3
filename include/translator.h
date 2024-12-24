#include <iostream>
#include <string>
#include "stack.h"

class Translator
{
public:
    virtual std::string convertToPostfix(const std::string& expression) = 0;
    virtual double evaluatePostfix(const std::string& postfix) = 0;
    virtual ~Translator() = default;
};

class PostfixCalculator : public Translator
{
public:
    bool isOperator(char symbol)
    {
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }

    int getPrecedence(char operation)
    {
        if (operation == '+' || operation == '-') return 1;
        if (operation == '*' || operation == '/') return 2;
        return 0;
    }

    bool isDigit(char symbol)
    {
        return (symbol >= '0' && symbol <= '9') || symbol == '.';
    }

    double performOperation(double left, double right, char operation)
    {
        switch (operation)
        {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if (right == 0) throw "Division by zero";
            return left / right;
        default: throw "Invalid operator";
        }
    }

    std::string convertToPostfix(const std::string& expression) override
    {
        Stack<char> operators;
        std::string result;

        for (size_t i = 0; i < expression.size(); ++i)
        {
            char symbol = expression[i];

            if (isDigit(symbol))
            {
                result += symbol;
                while (i + 1 < expression.size() && isDigit(expression[i + 1]))
                {
                    result += expression[++i];
                }
                result += ' ';
            }

            else if (isOperator(symbol))
            {
                while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(symbol))
                {
                    result += operators.top();
                    result += ' ';
                    operators.pop();
                }
                operators.push(symbol);
            }

            else if (symbol == '(')
            {
                operators.push(symbol);
            }

            else if (symbol == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    result += operators.top();
                    result += ' ';
                    operators.pop();
                }
                if (operators.empty() || operators.top() != '(')
                {
                    throw "Mismatched parentheses";
                }
                operators.pop();
            }
            else
            {
                throw "Invalid character in expression";
            }
        }

        while (!operators.empty())
        {
            if (operators.top() == '(') throw "Mismatched parentheses";
            result += operators.top();
            result += ' ';
            operators.pop();
        }

        return result;
    }

    double evaluatePostfix(const std::string& postfix) override
    {
        Stack<double> values;
        for (size_t i = 0; i < postfix.size(); ++i)
        {
            char symbol = postfix[i];
            if (isDigit(symbol))
            {
                double num = 0;
                bool decimalPoint = false;
                double fractionPart = 0.1;
                while (i < postfix.size() && isDigit(postfix[i]))
                {
                    if (postfix[i] == '.')
                    {
                        decimalPoint = true;
                    }
                    else
                    {
                        if (decimalPoint)
                        {
                            num += (postfix[i] - '0') * fractionPart;
                            fractionPart *= 0.1;
                        }
                        else
                        {
                            num = num * 10 + (postfix[i] - '0');
                        }
                    }
                    ++i;
                }
                values.push(num);
            }
            else if (isOperator(symbol))
            {
                if (values.size() < 2) throw "Invalid postfix expression";
                double right = values.top();
                values.pop();
                double left = values.top();
                values.pop();
                values.push(performOperation(left, right, symbol));
            }
        }
        if (values.size() != 1) throw "Invalid postfix expression";
        return values.top();
    }
};
