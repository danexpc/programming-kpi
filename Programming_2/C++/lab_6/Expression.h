//
// Created by Danil on 21.04.2020.
//

#ifndef LAB_6_EXPRESSION_H
#define LAB_6_EXPRESSION_H


#include <iosfwd>
#include <string>
#include <ostream>

class Expression {
public:
    Expression();
    Expression(double a, double b, double c, double d);

    void set_a(double value);
    void set_b(double value);
    void set_c(double value);
    void set_d(double value);

    double get_a() const;
    double get_b() const;
    double get_c() const;
    double get_d() const;

    friend std::ostream &operator<< (
            std::ostream &out,
            const Expression &expression
            );

private:
    mutable double *_a{nullptr};
    mutable double *_b{nullptr};
    mutable double *_c{nullptr};
    mutable double *_d{nullptr};
    [[nodiscard]] std::string valueExpression() const;
};


#endif //LAB_6_EXPRESSION_H
