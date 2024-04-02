#pragma once

#include <iostream>
#include <vector>

#include "loss/Loss.h"

namespace lr
{

class LinearRegression {
private:
    Matrix input;
    Vector y;
    Vector theta, epsilon;
    Vector loss;
public:
    LinearRegression(const Matrix& _input, const Vector& _y);
    LinearRegression(const LinearRegression& linearRegression);
    LinearRegression(LinearRegression&& linearRegression) noexcept;

    LinearRegression() = default;
    ~LinearRegression() = default;

    LinearRegression& operator=(const LinearRegression& linearRegression);
    LinearRegression& operator=(LinearRegression&& linearRegression) noexcept;
public:
    void train(int epochs, double learningRate = 0.1);
    Vector predict(const Matrix& input);

    void load(const std::string& dir);
    void save(const std::string& dir);
public:
    inline Vector& getLoss() { return loss; }
    inline Vector& getTheta() { return theta; }
    inline Vector& getEpsilon() { return epsilon; }
};

}