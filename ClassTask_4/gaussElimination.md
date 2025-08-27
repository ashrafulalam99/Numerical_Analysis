# Overview of Gauss Elimination
Gauss Elimination is a method for solving systems of linear equations by transforming the coefficient matrix into an upper triangular matrix and solving using back substitution.

Pivoting improves stability by rearranging rows so that the largest available coefficient becomes the pivot. This reduces rounding errors and prevents division by very small numbers.

# Gauss Elimination (No Pivoting)

Steps:

    For each pivot element (diagonal element), eliminate elements below it in the same column.

    Use back substitution to find the solution.

Limitations:

    Sensitive to small pivot elements.

    Can produce large numerical errors in some systems.

# Gauss Elimination with Partial Pivoting

Steps:

    For each pivot column, find the row with the largest absolute value in that column.

    Swap that row with the current row.

    Eliminate elements below the pivot.

    Back substitution to solve.

Limmitations:

    Comparatively more calculation

    Increases complexity

# Advantags of Pivoting

    Reduces rounding errors.

    Prevents division by very small numbers or zero.

    More stable for practical computations.