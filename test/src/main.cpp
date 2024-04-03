#include <iostream>

#include <loss/Loss.h>
#include <regression/Linear.h>

/*
Stock price forecast

| Income (millions USD) | Earnings (millions USD) | P/E Ratio | P/B Ratio | Interest Rate (%)  | Inflation Rate (%) | Closing Price (USD) |
|-----------------------|-------------------------|-----------|-----------|--------------------|--------------------|---------------------|
| 100                   | 20                      | 15        | 2.5       | 3.5                | 2                  | 50                  |
| 120                   | 25                      | 16        | 2.7       | 4.0                | 2.2                | 55                  |
| 110                   | 22                      | 14        | 2.4       | 3.7                | 2.1                | 52                  |
| 130                   | 28                      | 17        | 2.9       | 4.2                | 2.4                | 58                  |
| 115                   | 24                      | 15.5      | 2.6       | 3.8                | 2.3                | 54                  |
| 105                   | 21                      | 14.5      | 2.3       | 3.6                | 2.0                | 51                  |
| 125                   | 26                      | 16.5      | 2.8       | 4.1                | 2.3                | 56                  |
| 135                   | 30                      | 18        | 3.0       | 4.3                | 2.5                | 60                  |
| 112                   | 23                      | 15        | 2.5       | 3.6                | 2.1                | 53                  |
| 128                   | 27                      | 17.5      | 2.7       | 4.0                | 2.2                | 57                  |
| 95                    | 18                      | 14        | 2.3       | 3.2                | 1.8                | 48                  |
| 118                   | 24                      | 16.2      | 2.6       | 3.9                | 2.0                | 54                  |
| 107                   | 20                      | 13.5      | 2.2       | 3.4                | 1.9                | 50                  |
| 125                   | 26                      | 17.2      | 2.7       | 4.1                | 2.2                | 58                  |
| 112                   | 22                      | 15        | 2.4       | 3.7                | 2.1                | 52                  |
| 102                   | 19                      | 13.8      | 2.1       | 3.3                | 1.7                | 49                  |
| 122                   | 25                      | 16.7      | 2.8       | 4.0                | 2.3                | 55                  |
| 130                   | 28                      | 18.5      | 3.1       | 4.3                | 2.4                | 60                  |
| 108                   | 21                      | 14.2      | 2.5       | 3.5                | 1.8                | 51                  |
| 127                   | 27                      | 17.8      | 2.9       | 4.2                | 2.1                | 57                  |

*/

lr::Matrix input = {
    { 1, 100, 20, 15  , 2.5, 3.5, 2   },
    { 1, 120, 25, 16  , 2.7, 4.0, 2.2 },
    { 1, 110, 22, 14  , 2.4, 3.7, 2.1 },
    { 1, 130, 28, 17  , 2.9, 4.2, 2.4 },
    { 1, 115, 24, 15.5, 2.6, 3.8, 2.3 },
    { 1, 105, 21, 14.5, 2.3, 3.6, 2.0 },
    { 1, 125, 26, 16.5, 2.8, 4.1, 2.3 },
    { 1, 135, 30, 18  , 3.0, 4.3, 2.5 },
    { 1, 112, 23, 15  , 2.5, 3.6, 2.1 },
    { 1, 128, 27, 17.5, 2.7, 4.0, 2.2 },
    { 1, 95 , 18, 14  , 2.3, 3.2, 1.8 },
    { 1, 118, 24, 16.2, 2.6, 3.9, 2.0 },
    { 1, 107, 20, 13.5, 2.2, 3.4, 1.9 },
    { 1, 125, 26, 17.2, 2.7, 4.1, 2.2 },
    { 1, 112, 22, 15  , 2.4, 3.7, 2.1 },
    { 1, 102, 19, 13.8, 2.1, 3.3, 1.7 },
    { 1, 122, 25, 16.7, 2.8, 4.0, 2.3 },
    { 1, 130, 28, 18.5, 3.1, 4.3, 2.4 },
    { 1, 108, 21, 14.2, 2.5, 3.5, 1.8 },
    { 1, 127, 27, 17.8, 2.9, 4.2, 2.1 }
};

lr::Vector output = { 50, 55, 52, 58, 54, 51, 56, 60, 53, 57, 48, 54, 50, 58, 52, 49, 55, 60, 51, 57 };

void training() {

    lr::LinearRegression linearRegression(input, output);

    // Linear regression training
    int epochs = 800;
    double learningRate = 1e-10;

    // Exponential decay (OPTIONAL. Improves training)
    lr::LinearRegression::ExponentialDecay exponentialDecay(learningRate, 0.75, 225);
    linearRegression.setExponentialDecay(exponentialDecay);

    // Train
    linearRegression.train(epochs, learningRate);

    // Show loss
    for(const auto& l : linearRegression.getLoss())
        std::cout  << "Loss: " << l << std::endl;

    // Prediction
    lr::Vector prediction = linearRegression.predict(input); // Predict with training data to see if the prediction matches the output

    // Show prediction
    std::cout << "Prediction: ";
    for(auto& pred : prediction) std::cout << pred << " ";
    std::cout << std::endl;

    // Save model
    linearRegression.save("/home/morcillosanz/Desktop/");
}

void loadModel() {

    // Load model
    lr::LinearRegression linearRegression;
    linearRegression.load("/home/morcillosanz/Desktop/");

    // Prediction
    lr::Vector prediction = linearRegression.predict(input);

    // Show prediction
    std::cout << "Prediction: ";
    for(auto& pred : prediction) std::cout << pred << " ";
    std::cout << std::endl;
}


int main() {

    training();
    loadModel();

    return 0;
}