## Bisection Method and approaches
The bisection method is based on the **Intermediate Value Theorem**, which states that if a continuous function f(x) changes sign over an interval [a, b], then there exists at least one root between (a) and (b).

Mathematically, the condition for applying the bisection method is: f(a) * f(b) < 0

The method works by repeatedly halving the interval [a, b] and selecting the subinterval in which the sign change occurs. This process continues until the interval becomes sufficiently small, or until the function value at the midpoint becomes acceptably close to zero.

The main limitation of the traditional bisection method lies in selecting a proper initial interval. If the chosen [a, b] does not bracket the root, the method cannot proceed. In practice, manually identifying such an interval is not always straightforward, especially for complex functions or functions with multiple roots. A poor choice of the initial range may also result in unnecessary iterations, thereby increasing computational cost.

To overcome the difficulty of manually guessing a suitable initial interval, an improved approach involves automating the process of range selection. This method scans a predefined domain for points where the function changes sign.

The improved bisection method begins by defining a large interval, and then incrementally checks subintervals of small width such as 0.1 unit. The algorithm evaluates the function at each step and identifies two consecutive points where a sign change occurs. This newly detected interval [a, b] is then used as the starting point for the standard bisection method. This automatic interval detection ensures that the root is bracketed correctly and often results in a better choice of initial interval, potentially reducing the total number of iterations required.

## Implementation in Code

Both the traditional and improved bisection methods have been implemented. In the traditional version, the user is asked to manually input the initial guesses for (a) and (b). In the improved version, the program automatically searches for a suitable interval within a predefined domain. In both cases, the user is allowed to set the desired error tolerance and the maximum number of iterations to control the stopping criteria.

To compare the performance of the two methods, we measured the number of iterations required to find the root of the example function: f(x) = 2x^2 - x - 3

Using an error tolerance of (0.0001), the traditional method required 15 to 18 iterations starting from a well guessed interval by the user, while the improved method converged in 12 to 16 iterations after automatically detecting a better initial interval. It is important to note that while the improved method adds some computational overhead during the scanning phase, this overhead is often negligible compared to the gain achieved by faster convergence during the actual bisection process.

The bisection method remains a fundamental technique for root-finding due to its simplicity and reliability. However, its effectiveness greatly depends on the choice of the initial interval. The improved approach, with automatic interval detection, helps address this issue and typically results in fewer iterations for convergence.
