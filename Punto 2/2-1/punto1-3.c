#include <stdlib.h>
#include <stdio.h>


int potencia(int num, int aux){
    int ans;
    ans = aux * num;
    return ans;
}

int main () {
    printf("Ingrese un numero: ");
    int num;
    int aux;
    int ans = 0;
    scanf("%d", &num);
    printf("Ingrese la potencia: ");
    int pot;
    scanf("%d", &pot);
    for (int i = 1; i < pot; i++){
        if(i == 1){
            aux = num;
        }
        else{
            aux = ans;
        }
        ans = potencia(num, aux);
    }
    
    printf("El resultado es: %d \n", ans);

    return 0;
}