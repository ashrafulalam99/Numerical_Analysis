#include <bits/stdc++.h>
using namespace std;

// Define the function f(x) = ln(3x) - 3
double f(double x) {
    return log(3 * x) - 3;
}

int main() {
    double a, b, x_new, x_old;
    double error = 1e-4; 
    double ea = 1.0;      
    int max_iter = 100;
    int iter = 0;

    cout << "Enter initial guess for a & b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "f(a) and f(b) should have opposite signs." << endl;
        return -1;
    }

    x_new = a;

     while (ea > error && iter < max_iter) {
        x_old = x_new;

        // False Position formula
        x_new = b - (f(b) * (a - b)) / (f(a) - f(b));

        if (f(a) * f(x_new) < 0) {
            b = x_new;
        } else {
            a = x_new;
        }

        if (iter > 0) {
            ea = fabs((x_new - x_old) / x_new);
        }

        iter++;
    }

    if (iter >= max_iter) 
    {
        cout << "Method did not converge within maximum iterations." << endl;
    } 
    
    else {
        cout << "Approximate root is found at x = : " << x_new << " after" << iter << "iterations." << endl;
    }

    return 0;
}
