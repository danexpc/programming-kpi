//
// Created by Danil on 21.04.2020.
//
#include "Expression.h"
#include <string>
#include <ostream>
#include <iostream>
#include <cmath>

Expression::Expression() = default;
Expression::Expression(
        double a,
        double b,
        double c,
        double d){
    _a = &a;
    _b = &b;
    _c = &c;
    _d = &d;
}

void Expression::set_a(double value) {
    _a = &value;
}

void Expression::set_b(double value) {
    _b = &value;
}

void Expression::set_c(double value) {
    _c = &value;
}

void Expression::set_d(double value) {
    _d = &value;
}

double Expression::get_a() const {
    return *_a;
}

double Expression::get_b() const {
    return *_b;
}

double Expression::get_c() const {
    return *_c;
}

double Expression::get_d() const {
    return *_d;
}

std::ostream &operator<<(std::ostream &out, const Expression &expression) {
    out << expression.valueExpression() << std::endl;
    return out;
}

std::string Expression::valueExpression() const {
    while (true)
    {
        try {
            if (_a == nullptr)
            {
                std::cout << "a = null! Input value: \n";
                double temp;
                std::cin >> temp;
                if (std::cin.fail())
                {
                    throw std::runtime_error("Incorrect input");
                }
                _a = &temp;
            }
            if (_b == nullptr)
            {
                std::cout << "b = null! Input value: \n";
                double temp;
                std::cin >> temp;
                if (std::cin.fail())
                {
                    throw std::runtime_error("Incorrect input");
                }
                _b = &temp;
            }
            if (_c == nullptr)
            {
                std::cout << "c = null! Input value: \n";
                double temp;
                std::cin >> temp;
                if (std::cin.fail())
                {
                    throw std::runtime_error("Incorrect input");
                }
                _c = &temp;
            }
            if (_d == nullptr)
            {
                std::cout << "d = null! Input value: \n";
                double temp;
                std::cin >> temp;
                if (std::cin.fail())
                {
                    throw std::runtime_error("Incorrect input");
                }
                _d = &temp;
            }
            break;
        }
        catch (std::runtime_error& error)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << error.what() << std::endl;
        }
    }

    if ((*_d) == 0 || (*_b) + (*_c)/(*_d) - 1 == 0 || (*_b) * 4 - (*_c) == 0)
    {
        return "Undefined";
    }

    double result = log10(((*_b) * 4 - (*_c))) * (*_a) / ((*_b) + (*_c)/(*_d) - 1);
    return std::to_string(result);
}
