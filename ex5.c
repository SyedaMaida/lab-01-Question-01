#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Please enter a non-negative integer for n.\n");
        return 1; 
    }
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    printFibonacciSeries(n);

    return 0;
}
