#include <stdio.h>

// Matrix multiplication for Fibonacci
void matrix_multiply(long long a[2][2], long long b[2][2], long long result[2][2]) {
	result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

// Matrix exponentiation by squaring
void matrix_power(long long matrix[2][2], int n, long long result[2][2]) {
	long long temp[2][2];

	// Initialize result to the identity matrix
	result[0][0] = 1; result[0][1] = 0;
	result[1][0] = 0; result[0][1] = 1;

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
				result[i][j] = temp[i][j];
			}
		}
		n /= 2;
	}
}

// Compute Fibonacci number using matrix exponentiation
long long fibonacci(int n) {
	if (n == 0) return 0;

	long long matrix[2][2] = { {1, 1}, {1, 0} };
	long long result[2][2];
	matrix_power(matrix, n - 1, result);
}

int main() {
	int n = 2; // Compute F(50)
	printf("Fibonacci number F(%d) = %lld\n", n, fibonacci(n));
	return 0;
}