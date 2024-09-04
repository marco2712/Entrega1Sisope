#include <stdio.h>

int main() {
    // Implicit Type Casting
    int intVal = 10;
    float floatVal = 5.5;
    float result;

    result = intVal + floatVal;  // Implicit casting
    printf("Result of implicit casting: %.2f\n", result);

    // Explicit Type Casting
    floatVal = 5.9;
    intVal = (int) floatVal;  // Explicit casting
    printf("Result of explicit casting: %d\n", intVal);

    return 0;
}
