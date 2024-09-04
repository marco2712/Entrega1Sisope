#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Ingrese un numero: \n");
    int num;
    int ans = 1;
    scanf("%d", &num);

    for(int i = 2; i <= num; i++ ){
        ans = ans * i;
    }
    printf("EL factorial de %d es: %d \n", num, ans);



    return 0;
}