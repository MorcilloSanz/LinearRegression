#pragma once

#include <iostream>
#include <vector>

#include <loss/Loss.h>

namespace lr
{

class LinearRegression {
private:
    Matrix input;
    Vector y;
    Vector theta, epsilon;
public:
    LinearRegression(const Matrix& _input, const Vector& _y);
    LinearRegression(const LinearRegression& linearRegression);
    LinearRegression(LinearRegression&& linearRegression) noexcept;

    LinearRegression() = default;
    ~LinearRegression() = default;

    LinearRegression& operator=(const LinearRegression& linearRegression);
    LinearRegression& operator=(LinearRegression&& linearRegression) noexcept;
public:
    Vector train(int epochs, double learningRate = 0.1);
    Vector predict(const Matrix& input);
};

}