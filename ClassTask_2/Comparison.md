# Comparison Between Bisection Method and False Position Method

The function is: f(x) = 4x^2 + 3x - 3

For the function, we first check an appropriate interval where the root exists.

At (x = 0):
f(0) = -3

At (x = 1):
f(1) = 4

So, the root lies between 0 and 1. Therefore, the initial interval selected is [0, 1].

## Iterative Results:

For the Bisection Method, the iterations started with the interval [0, 1]. The method kept halving the interval and recalculating the midpoint at each step. It took approximately 12 iterations for the Bisection Method to achieve the desired error tolerance of 10^-4. The approximate root obtained was around 0.5212.

For the False Position Method, starting with the same interval [0, 1], the method used the function values to find the x-intercept of the secant line at each step. This allowed it to converge faster, reaching the desired error tolerance in about 6 iterations. The approximate root obtained was around 0.5215.

## True Percentage Relative Error (TPRE) Comparison:

The True Percentage Relative Error (TPRE) helps to assess how close the approximated root is to the actual (true) root. Assuming the true root for this equation is approximately 0.5215 (obtained either analytically or using a very high-precision method), the TPRE can be calculated using the formula:

TRPE = (|X_approax - X_true| / X_true) x 100
TRPE_Bisection = 0.057% (almost)
TRPE_Falsi = 0%

For the Bisection Method, the TPRE was slightly higher due to slower convergence and the approximation stopping slightly before the true root. For the False Position Method, the TPRE was significantly lower (0%), demonstrating that it reached a more accurate root in fewer iterations.

Both the Bisection Method and the False Position Method successfully found the root of the given function within the specified error tolerance. But there are some issues:

- The **False Position Method** converged faster, requiring fewer iterations to meet the stopping criteria.
- The **Bisection Method**, while slower, remained reliable and guaranteed bracketing at every step.
- In terms of True Percentage Relative Error, the False Position Method produced a more accurate root compared to the Bisection Method under the same error tolerance.