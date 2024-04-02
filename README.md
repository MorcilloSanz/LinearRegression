# LinearRegression
Linear regression and gradient descent in C++.

## Features
* Train the model
* Predict
* Plot (`Python` and `matplotlib` needed)
* Save model
* Load saved model

# Algorithm

**Weights and biases**

* Generate weights vector (uniformly distributed): $\theta$
* Generate the biases vector with random numbers [0,1]: $\varepsilon$.

**Training**

* (1) Compute linear regression: 
$$\hat{y} = X \theta + \varepsilon$$
* (2) Compute loss function and its gradient:
$$\nabla L = \left( \frac{\partial L}{\partial \theta_{j}}, \frac{\partial L}{\partial \varepsilon_{i}} \right)$$
* (3) Apply gradient descent: 
$$\theta^{t+1}_{j} = \theta^{t}_{j} + \gamma \frac{\partial L}{\partial \theta_{j}}$$
$$\varepsilon^{t+1}_{i} = \varepsilon^{t}_{i} + \gamma \frac{\partial L}{\partial \varepsilon_{i}}$$
* (4) Go back to step 1 for a specified number of epochs.

# Test

Ground truth  | Prediction
------------- | -------------
0.5 0.65 0.80 0.60  | 0.40 0.71 0.84 0.58

![](img/loss.png)