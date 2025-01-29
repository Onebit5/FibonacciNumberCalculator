#include <stdio.h>
#include <limits.h>

int main() {
	unsigned long long prev = 0; // F(0)
	unsigned long long curr = 1; // F(1)
	unsigned long long next;
	int n = 1; // Counter for the Fibonacci index

	// Loop until the next Fibonacci number exceeds the limit
	while (1) {
		// Check for overflow before computing the next Fibonacci number
		if (curr > ULLONG_MAX - prev) {
			printf("Fibonacci number %lu at index %d is the largest possible.\n", curr, n);
			break;
		}

		// Compute the next Fibonacci number
		next = prev + curr;
		prev = curr;
		curr = next;
		n++;
	}

	return 0;
}