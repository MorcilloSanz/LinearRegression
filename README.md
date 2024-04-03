# LinearRegression
In statistics, linear regression is a statistical model which estimates the linear
relationship between a scalar response and one or more explanatory variables. In
linear regression, the relationships are modeled using linear predictor functions
whose unknown model parameters are estimated from the data.

$$\hat{y} = X\theta + \varepsilon$$

[Take a look at the math](Linear_regression.pdf)

## Features
* **Train** the model with gradient descent.
* **Learning rate adjustment** using exponential decay learning rate schedule.
* **Predict** using the linear regression.
* **Plot** (`Python` and `matplotlib` needed) loss function.
* **Save** the model in order to use it later.
* **Load** saved model.

# Test: stock price forecast

### Stock data
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

### Prediction
<img align="right" src="img/loss.png"/>

|Ground truth  | Prediction   |
|------------- | -------------|
| 50           | 47           |  
| 55           | 56           |  
| 52           | 51           |  
| 58           | 60           |  
| 54           | 53           |  
| 51           | 49           |  
| 56           | 58           |  
| 60           | 63           |  
| 53           | 52           |  
| 57           | 59           |  
| 48           | 44           |  
| 54           | 55           |  
| 50           | 48           |  
| 58           | 58           |  
| 52           | 51           |  
| 49           | 47           |  
| 55           | 56           |  
| 60           | 61           |  
| 51           | 49           |  
| 57           | 59           |  