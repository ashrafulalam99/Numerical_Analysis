#include <bits/stdc++.h>
using namespace std;

// Function: x^5 - 3*x + 5
double func(double x) {
    return pow(x, 5) - 3*x + 5;
}

//Derivation
double func_der(double x) {
    return 5*pow(x, 4) - 3;
}

int main() 
{
    double x0, x1, es = 1e-3, ea = 1;
    cout << "Enter first guess: ";
    cin >> x0;
    
    while (ea > es) 
    {
        x1 = x0 - func(x0) / func_der(x0);
        ea = fabs((x1 - x0) / x1);
        x0 = x1;
    }

    cout << "Root = " << x1 << endl;
    return 0;
}
