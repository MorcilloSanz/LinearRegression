# LinearRegression
LinearRegression and gradient descent from scratch.

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

# Math
![](img/math.png)

# Test

Ground truth  | Prediction
------------- | -------------
0.5 0.65 0.80 0.60  | 0.40 0.71 0.84 0.58

![](img/loss.png)

```
Epoch 1: loss -> 0.015625
Epoch 2: loss -> 0.010727
Epoch 3: loss -> 0.00778853
Epoch 4: loss -> 0.00603281
Epoch 5: loss -> 0.00498947
Epoch 6: loss -> 0.00437399
Epoch 7: loss -> 0.00401452
Epoch 8: loss -> 0.00380747
Epoch 9: loss -> 0.00369056
Epoch 10: loss -> 0.00362649
Epoch 11: loss -> 0.00359301
.
.
.
Epoch 50: loss -> 0.00359054
```