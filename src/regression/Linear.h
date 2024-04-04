#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "loss/Loss.h"

namespace lr
{

class LinearRegression {
public:
    struct ExponentialDecay {

        double initialLearningRate;
        double decayRate;

        ExponentialDecay(double _initialLearningRate, double _decayRate)
            : initialLearningRate(_initialLearningRate), decayRate(_decayRate) { 
        }

        ExponentialDecay() = default;
        ~ExponentialDecay() = default;

        inline double getLearningRate(double t) {
            return initialLearningRate * exp(-decayRate * t);
        }
    };
private:
    Matrix input;
    Vector y;

    Vector theta, epsilon;
    Vector loss;

    ExponentialDecay exponentialDecay;
    bool hasExponentialDecay;
public:
    LinearRegression(const Matrix& _input, const Vector& _y);
    LinearRegression(const LinearRegression& linearRegression);
    LinearRegression(LinearRegression&& linearRegression) noexcept;

    LinearRegression() = default;
    ~LinearRegression() = default;

    LinearRegression& operator=(const LinearRegression& linearRegression);
    LinearRegression& operator=(LinearRegression&& linearRegression) noexcept;
public:
    void setExponentialDecay(const ExponentialDecay& exponentialDecay);
    void train(int epochs, double learningRate = 0.001);
    Vector predict(const Matrix& input);
    void load(const std::string& dir);
    void save(const std::string& dir);
public:
    inline Vector& getLoss() { return loss; }
    inline Vector& getTheta() { return theta; }
    inline Vector& getEpsilon() { return epsilon; }
};

}