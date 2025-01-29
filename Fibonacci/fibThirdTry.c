#include <stdio.h>
#include <limits.h>
#include <math.h>

// Matrix multiplication for Fibonacci
void matrix_multiply(unsigned long long a[2][2], unsigned long long b[2][2], unsigned long long result[2][2]) {
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

// Matrix exponentiation by squaring
void matrix_power(unsigned long long matrix[2][2], int n, unsigned long long result[2][2]) {
    unsigned long long temp[2][2];

    // Initialize result to the identity matrix
    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            matrix_multiply(result, matrix, temp);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    result[i][j] = temp[i][j];
                }
            }
        }
        matrix_multiply(matrix, matrix, temp);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
        n /= 2;
    }
}

// Compute Fibonacci number using matrix exponentiation
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;

    unsigned long long matrix[2][2] = { {1, 1}, {1, 0} };
    unsigned long long result[2][2];
    matrix_power(matrix, n - 1, result);

    return result[0][0];
}

// Estimate the largest n such that F(n) <= ULLONG_MAX
int estimate_max_n() {
    double phi = (1 + sqrt(5)) / 2; // Golden ratio
    double log_phi = log(phi);
    double log_sqrt5 = log(5) / 2;
    double log_limit = log((double)ULLONG_MAX);

    // Using Binet's formula: F(n) ≈ φ^n / √5
    // Solve for n: log(F(n)) ≈ n * log(φ) - log(√5)
    int n = (int)((log_limit + log_sqrt5) / log_phi);
    return n;
}

int main() {
    // Estimate the largest n such that F(n) <= ULLONG_MAX
    int max_n = estimate_max_n();
    printf("Estimated largest n: %d\n", max_n);

    // Compute Fibonacci numbers up to the estimated n
    for (int n = max_n - 1; n <= max_n + 1; n++) {
        unsigned long long fib = fibonacci(n);
        if (fib > ULLONG_MAX) {
            printf("F(%d) exceeds ULLONG_MAX.\n", n);
            break;
        }
        printf("F(%d) = %llu\n", n, fib);
    }

    return 0;
}