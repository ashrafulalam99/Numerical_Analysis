#include <bits/stdc++.h>
using namespace std;

const int n = 3;

// Back substitution
void backsub(double a[n][n], double b[n], double x[n]) 
{
    for (int i = n-1; i >= 0; i--) 
    {
        x[i] = b[i];
        for (int j = i+1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
}

// Standard Gauss Elimination
void gauss(double a[n][n], double b[n], double x[n]) 
{
    for (int k = 0; k < n-1; k++) {
        for (int i = k+1; i < n; i++) {
            double f = a[i][k] / a[k][k];
            for (int j = k; j < n; j++)
                a[i][j] -= f * a[k][j];
            b[i] -= f * b[k];
        }
    }
    backsub(a, b, x);
}

// Gauss Elimination with Partial Pivoting
void gausspivot(double a[n][n], double b[n], double x[n]) 
{
    for (int k = 0; k < n-1; k++) {
        // Find pivot
        int maxrow = k;
        for (int i = k+1; i < n; i++)
            if (fabs(a[i][k]) > fabs(a[maxrow][k])) maxrow = i;
        // Swap rows
        if (maxrow != k) {
            for (int j = 0; j < n; j++) swap(a[k][j], a[maxrow][j]);
            swap(b[k], b[maxrow]);
        }
        // Eliminate
        for (int i = k+1; i < n; i++) {
            double f = a[i][k] / a[k][k];
            for (int j = k; j < n; j++)
                a[i][j] -= f * a[k][j];
            b[i] -= f * b[k];
        }
    }
    backsub(a, b, x);
}

int main() 
{
    double a[n][n], b[n], x1[n], x2[n];

    cout << "Enter the 3x3 coefficient matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter the constants vector:\n";
    for (int i = 0; i < n; i++) cin >> b[i];

    // Copy original for pivoting
    double a2[n][n], b2[n];
    for (int i = 0; i < n; i++) {
        b2[i] = b[i];
        for (int j = 0; j < n; j++) a2[i][j] = a[i][j];
    }

    gauss(a, b, x1);
    gausspivot(a2, b2, x2);

    cout << "Solution without pivoting: ";
    for (int i = 0; i < n; i++) cout << x1[i] << " ";

    cout << "\nSolution with pivoting: ";
    for (int i = 0; i < n; i++) cout << x2[i] << " ";

    return 0;
}
