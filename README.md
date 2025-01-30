# Fibonacci Number Computation

This repository contains three C programs (`fibFirstTry.c`, `fibSecondTry.c`, and `fibThirdTry.c`) that compute Fibonacci numbers using different techniques. Each program demonstrates a unique approach to solving the problem, with increasing complexity and efficiency. Below is an explanation of the techniques used, how they work, and why the third program (`fibThirdTry.c`) cannot compute Fibonacci numbers beyond a certain limit.

---

## **1. `fibFirstTry.c`: Iterative Approach**

### **Technique Used**
- **Iterative Computation**:
  This program uses a simple iterative approach to compute Fibonacci numbers. It starts with the initial values \(F(0) = 0\) and \(F(1) = 1\) and iteratively computes the next Fibonacci number until it reaches the limit of the `unsigned long long` data type.

### **How It Works**
1. Initialize `prev = 0` (for \(F(0)\)) and `curr = 1` (for \(F(1)\)).
2. In each iteration, compute the next Fibonacci number as `next = prev + curr`.
3. Check if `curr` exceeds the maximum value of `unsigned long long` (`ULLONG_MAX`). If so, stop and print the largest Fibonacci number found.
4. Update `prev` and `curr` for the next iteration.

### **Limitations**
- The program stops when the next Fibonacci number exceeds `ULLONG_MAX`.
- It is simple but inefficient for very large Fibonacci numbers due to its \(O(n)\) time complexity.

---

## **2. `fibSecondTry.c`: Matrix Exponentiation**

### **Technique Used**
- **Matrix Exponentiation**:
  This program uses matrix exponentiation to compute Fibonacci numbers in \(O(\log n)\) time. The Fibonacci sequence can be represented using the following matrix:
  ```math
  \begin{pmatrix}
  F(n) \\
  F(n-1)
  \end{pmatrix}
  =
  \begin{pmatrix}
  1 & 1 \\
  1 & 0
  \end{pmatrix}^{n-1}
  \begin{pmatrix}
  F(1) \\
  F(0)
  \end{pmatrix}
  ```
  

### **How It Works**
1. Define a function `matrix_multiply` to multiply two 2x2 matrices.
2. Define a function `matrix_power` to compute the power of a matrix using exponentiation by squaring.
3. Use the `matrix_power` function to compute the Fibonacci matrix raised to the power of \(n-1\).
4. Extract \(F(n)\) from the resulting matrix.

### **Limitations**
- The program is incomplete and does not handle the computation of large Fibonacci numbers correctly.
- It does not check for overflow or estimate the largest Fibonacci number that fits in `unsigned long long`.

---

## **3. `fibThirdTry.c`: Matrix Exponentiation with Binet's Formula**

### **Technique Used**
- **Matrix Exponentiation**:
  Similar to `fibSecondTry.c`, this program uses matrix exponentiation to compute Fibonacci numbers efficiently.
- **Binet's Formula**:
  The program uses Binet's formula to estimate the largest Fibonacci number that fits in `unsigned long long`. Binet's formula is given by:
  ```math
  F(n) \approx \frac{\phi^n}{\sqrt{5}}, where \phi = \frac{1 + \sqrt{5}}{2} 
  ```

### **How It Works**
1. Define a function `matrix_multiply` to multiply two 2x2 matrices.
2. Define a function `matrix_power` to compute the power of a matrix using exponentiation by squaring.
3. Use the `matrix_power` function to compute the Fibonacci matrix raised to the power of \(n-1\).
4. Define a function `estimate_max_n` to estimate the largest using Binet's formula.
5. Compute Fibonacci numbers around the estimated \(n\) to find the largest one that fits in `unsigned long long`.

### **Why It Can't Compute Larger Fibonacci Numbers**
- The program is limited by the size of the `unsigned long long` data type, which can only hold values up to \(2^{64} - 1\).
- Once \(F(n)\) exceeds this limit, the program stops and reports the largest Fibonacci number that fits.

---

## **Comparison of the Programs**

| Program          | Technique Used               | Time Complexity | Limitations                                                                 |
|------------------|------------------------------|-----------------|-----------------------------------------------------------------------------|
| `fibFirstTry.c`  | Iterative Approach           | \(O(n)\)        | Inefficient for large \(n\); stops at the limit of `unsigned long long`.    |
| `fibSecondTry.c` | Matrix Exponentiation        | \(O(\log n)\)   | Incomplete implementation; does not handle overflow or large \(n\).         |
| `fibThirdTry.c`  | Matrix Exponentiation + Binet's Formula | \(O(\log n)\) | Limited by the size of `unsigned long long`; cannot compute beyond \(F(93)\). |

---

## **Why `fibThirdTry.c` Can't Compute Larger Fibonacci Numbers**

The `fibThirdTry.c` program is designed to compute the largest Fibonacci number that fits in the `unsigned long long` data type. The limit is imposed by the maximum value that `unsigned long long` can hold, which is 2^64 - 1. Specifically:
- The largest Fibonacci number that fits in `unsigned long long` is \(F(93) = 1293530146158671551\).
- The next Fibonacci number, \(F(94) = 18446744073709551615\), exceeds 2^64 - 1, causing an overflow.

Thus, the program stops at \(F(93)\) and cannot compute larger Fibonacci numbers without using a different data type or arbitrary-precision arithmetic.

---

## **How to Run the Programs**

1. Compile each program using a C compiler (e.g., `gcc`):
   ```bash
   gcc fibFirstTry.c -o fibFirstTry
   gcc fibSecondTry.c -o fibSecondTry
   gcc fibThirdTry.c -o fibThirdTry
   ```
2. Run the compiled programs:
   ```bash
   ./fibFirstTry
   ./fibSecondTry
   ./fibThirdTry
   ```

## **Conclusion**

- `fibFirstTry.c` is a simple iterative approach but inefficient for large Fibonacci numbers.
- `fibSecondTry.c` introduces matrix exponentiation for efficient computation but is incomplete.
- `fibThirdTry.c` combines matrix exponentiation with Binet's formula to compute the largest Fibonacci number that fits in `unsigned long long`.
