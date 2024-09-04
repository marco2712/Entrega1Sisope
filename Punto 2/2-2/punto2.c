#include <stdlib.h>
#include <stdio.h>

typedef struct estudiante{
    float lab1;
    float parcial1;
    float lab2;
    float parcial2;
    float lab3;
    float parcial3;
}estudiante;

int main(){

    int flag = 1;
    int tmp;
    while (flag){
        printf("Si desea agregar notas de estudiantes ingrese 1, de lo contrario coloque cualquier numero\n");
        scanf("%d", &tmp);
        if(tmp == 1){
            struct estudiante estudiante1; 
            printf("Digite la nota del lab1 5 porciento \n");
            scanf("%f", &estudiante1.lab1);
            printf("Digite la nota del parcial 25 porciento \n");
            scanf("%f", &estudiante1.parcial1);
            printf("Digite la nota del lab2 15 porciento \n");
            scanf("%f", &estudiante1.lab2);
            printf("Digite la nota del parcial2 20 porciento \n");
            scanf("%f", &estudiante1.parcial2);
            printf("Digite la nota del lab3 15 porciento \n");
            scanf("%f", &estudiante1.lab3);
            printf("Digite la nota del parcial3 20 porciento \n");
            scanf("%f", &estudiante1.parcial3);
            float acum = estudiante1.lab1 * 0.05 + estudiante1.parcial1 * 0.25 + estudiante1.lab2 * 0.15 + estudiante1.parcial2 * 0.20 + estudiante1.lab3 * 0.15 + estudiante1.parcial3 * 0.20;
            printf("Tu promedio es %f \n", acum);
        }else{
            flag = 0;
        }   



    }


    return 0;
}
