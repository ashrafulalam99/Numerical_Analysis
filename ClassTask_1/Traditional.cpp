#include <iostream>
#include <cmath>

using namespace std;

// Function: f(x) = 2x^3 - x - 3
double f(double x) {
    return 2 * x * x * x - x - 3;
}

int main() {
    double a, b, c, tolerance;
    int max_iterations, iterations = 0;

    cout << "Enter initial guess for a & b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter maximum number of iterations: ";
    cin >> max_iterations;

    while (iterations < max_iterations)
    {
        c = (a + b) / 2;
        iterations++;

        if (fabs(f(c)) < tolerance) {
            cout << "Root found at x = " << c << " after " << iterations << " iterations." << endl;
            return 0;
        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    }

    cout << "Approximate root at x = " << c << " after " << iterations << " iterations." << endl;
    return 0;
}
