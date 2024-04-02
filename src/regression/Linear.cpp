#include "Linear.h"

#include <cstdlib> 
#include <fstream>
#include <filesystem>

#include "util/Util.h"

#define MODEL_NAME "model.txt"
#define PLOT_NAME "plot.py"

namespace fs = std::filesystem;

namespace lr
{

LinearRegression::LinearRegression(const Matrix& _input, const Vector& _y) 
    : input(_input), y(_y) {

    size_t n = y.size();
    size_t k = input[0].size();

    for(size_t i = 0; i < n; i ++) epsilon.push_back((std::rand() % 10) / 10.0);

    for(size_t i = 0; i < k; i ++) {
        if(k > 1) theta.push_back(1 / (k - 1));
        else theta.push_back(1 / k);
    }

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

void LinearRegression::train(int epochs, double learningRate) {

    MSE mse;

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

void LinearRegression::load(const std::string& dir) {

    std::string filePath = dir + "/model/" + MODEL_NAME;

    auto loadVec = [&](std::string& line, std::vector<double>& vector) {

        std::string vec = Util::split(line, "=")[1];
        vec = vec.substr(1, vec.size() - 2);

        std::vector<std::string> elements = Util::split(vec, ",");
        for(auto& e : elements)
            vector.push_back(std::atof(e.c_str()));
    };

    std::ifstream file(filePath);
    if(file.is_open()) {

        bool first = true;
        std::string line;
        while(getline (file, line)) {

            if(first) loadVec(line, theta);
            else {
                loadVec(line, epsilon);
                break;
            }

            first = false;
        }

        file.close();
    }
}

void LinearRegression::save(const std::string& dir) {

    std::string modelPath = dir + "/model";
    fs::create_directories(modelPath);

    std::string plotPath = modelPath + "/plot";
    fs::create_directories(plotPath);

    std::ofstream file(modelPath + "/" + MODEL_NAME);

    if(file.is_open()) {

        file << "Weights(theta)=(";
        for(int i = 0; i < theta.size(); i ++) {
            if(i < theta.size() - 1)
                file << theta[i] << ",";
            else
                file << theta[i] << ")\n";
        }

        file << "Biases(epsilon)=(";
        for(int i = 0; i < epsilon.size(); i ++) {
            if(i < epsilon.size() - 1)
                file << epsilon[i] << ",";
            else
                file << epsilon[i] << ")\n";
        }

        file.close();
    }

    // Copy plot python program
    Util::copyFile("plot/plot.py", plotPath + "/" + PLOT_NAME);

    // Copy loss function 
    std::ofstream lossFile(plotPath + "/loss.txt");

    if(lossFile.is_open()) {

        for(int i = 0; i < loss.size(); i ++) {
            if(i < loss.size() - 1) lossFile << loss[i] << " ";
            else lossFile << loss[i];
        }

        lossFile.close();
    }

}

}