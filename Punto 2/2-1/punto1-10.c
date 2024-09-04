#include <stdio.h>

int main() {
    int i;

    printf("Number\tDecimal\tOctal\tHexadecimal\n");
    for (i = 1; i <= 10; i++) {
        printf("%d\t%d\t%o\t%x\n", i, i, i, i);
    }

    return 0;
}
