#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double power(double base, int exp) {
    double result = 1.0;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    double phi = (1 + sqrt(5)) / 2.0;
    return (int)round(power(phi, n) / sqrt(5));
}

int main() {
    int n;
    printf("Ingrese un numero: \n");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}