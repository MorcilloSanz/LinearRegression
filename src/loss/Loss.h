#pragma once

#include <iostream>
#include <vector>

namespace lr
{

using Vector = std::vector<double>;
using Matrix = std::vector<std::vector<double>>;

class Loss {
public:
    Loss() = default;
    ~Loss() = default;
public:
    virtual double evaluate(const Vector& y, const Vector& pred) = 0;
    virtual Vector gradient(const Matrix& input, const Vector& y, const Vector& pred) = 0;
};

class MSE : public Loss {
public:
    MSE() = default;
    ~MSE() = default;
public:
    double evaluate(const Vector& y, const Vector& pred) override;
    Vector gradient(const Matrix& input, const Vector& y, const Vector& pred) override;
};

}