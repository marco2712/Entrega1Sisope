#include <stdio.h>
#include <stdlib.h>

int main (){
    printf("Ingrese un ano: \n");
    int num;
    int ans;
    scanf("%d", &num);
    if((num % 4 == 0 && num % 100 != 0) || (num % 400 == 0 )){
        ans = 1;
    }else{
        ans = 0;
    }
    if (ans){
        printf("El ano %d es bisiesto", num);
    }else{
        printf("El ano %d no es bisiesto", num);
    }

    

    return 0;
}