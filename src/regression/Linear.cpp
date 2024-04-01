#include "Linear.h"

#include <cstdlib> 

namespace lr
{

LinearRegression::LinearRegression(const Matrix& _input, const Vector& _y) 
    : input(_input), y(_y) {

    size_t n = y.size();
    size_t k = input[0].size();

    for(size_t i = 0; i < n; i ++) epsilon.push_back((std::rand() % 10) / 10.0);
    for(size_t i = 0; i < k; i ++) theta.push_back(0.5);

}
LinearRegression::LinearRegression(const LinearRegression& linearRegression) 
    : input(linearRegression.input), y(linearRegression.y), 
    theta(linearRegression.theta), epsilon(linearRegression.epsilon) {
}

LinearRegression::LinearRegression(LinearRegression&& linearRegression) noexcept
    : input(std::move(linearRegression.input)), y(std::move(linearRegression.y)), 
    theta(std::move(linearRegression.theta)), epsilon(std::move(linearRegression.epsilon)) {
}

LinearRegression& LinearRegression::operator=(const LinearRegression& linearRegression) {

    input = linearRegression.input;
    y = linearRegression.y;
    theta = linearRegression.theta;
    epsilon = linearRegression.epsilon;
    return *this;
}

LinearRegression& LinearRegression::operator=(LinearRegression&& linearRegression) noexcept {

    input = std::move(linearRegression.input);
    y = std::move(linearRegression.y);
    theta = std::move(linearRegression.theta);
    epsilon = std::move(linearRegression.epsilon);
    return *this;
}

Vector LinearRegression::train(int epochs, double learningRate) {

    Vector loss;
    lr::MSE mse;

    for(int epoch = 0; epoch < epochs; epoch ++) {

        // Compute prediction
        Vector pred = predict(input);

        // Gradient descent
        double _loss = mse.evaluate(y, pred);
        Vector gradient = mse.gradient(input, y, pred);

        for(auto& t : theta) t -= learningRate * gradient[0];
        for(auto& e : epsilon) e -= learningRate * gradient[1];

        loss.push_back(_loss);
    }

    return loss;
}

Vector LinearRegression::predict(const Matrix& input) {

    Vector pred(input.size());

    for(int i = 0; i < input.size(); i ++) {

        double sum = 0.0;

        for(int j = 0; j < input[i].size(); j ++)
            sum += theta[j] * input[i][j];

        pred[i] = sum + epsilon[i];
    }

    return pred;
}

}