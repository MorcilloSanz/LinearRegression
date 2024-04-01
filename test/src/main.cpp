#include <iostream>

#include <loss/Loss.h>
#include <regression/Linear.h>

int main() {

    // Input data
    const lr::Matrix trainingInput = {
        { 1, 0.5, 0.5, 0.5 },
        { 1, 0.7, 0.3, 0.6 },
        { 1, 0.8, 0.9, 0.6 },
        { 1, 0.3, 0.2, 0.4 }
    };

    const lr::Vector trainingOutput = { 0.5, 0.65, 0.80, 0.60 };

    lr::LinearRegression linearRegression(trainingInput, trainingOutput);

    // Linear regression training
    int epochs = 50;
    double learningRate = 0.001;

    lr::Vector loss = linearRegression.train(epochs, learningRate);

    for(int i = 0; i < loss.size(); i ++) 
        std::cout << "Epoch " << i + 1 << ": loss -> " << loss[i] << std::endl;

    // Linear regression prediction
    lr::Vector prediction = linearRegression.predict(trainingInput); // Predict with training data to see if the prediction matches the output

    std::cout << "Prediction: ";
    for(auto& pred : prediction) std::cout << pred << " ";
    std::cout << std::endl;

    return 0;
}