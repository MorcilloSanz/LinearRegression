#include "Loss.h"

#include <cmath>

namespace lr
{

double MSE::evaluate(const Vector& y, const Vector& pred) {

    double sum = 0.0;

    for(size_t i = 0; i < y.size(); i ++)
        sum += pow(y[i] - pred[i], 2);

    return sum / y.size();
}

Vector MSE::gradient(const Matrix& input, const Vector& y, const Vector& pred) {

    double partialTheta = 0.0;
    double partialEpsilon = 0.0;

    for(int i = 0; i < y.size(); i ++) {
        
        double diff = y[i] - pred[i];

        double inputSum = 0.0;
        for(const auto& vec : input) {
            for(const auto& e : vec) inputSum += e;
        }

        partialTheta += diff * inputSum;
        partialEpsilon += diff;
    }

    partialTheta /= -(2.0 / y.size());
    partialEpsilon /= -(2.0 / y.size());

    return { partialTheta, partialEpsilon };
}

}