#include <stdio.h>
#include <stdlib.h>

int main (){
    printf("Ingrese un numero: \n");
    int num;
    int ans;
    scanf("%d", &num);
    if(num % 2 == 0){
        ans = 1;
    }else{
        ans = 0;
    }
    if (ans){
        printf("El numero:  %d es par", num);
    }else{
        printf("El numero:  %d es impar", num);
    }


    return 0;
}