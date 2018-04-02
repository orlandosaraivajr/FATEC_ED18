#include <stdio.h>
#include <stdlib.h>
/*
Exemplo de funções e passagem de parâmetros
*/

void nao_troca_valores(int valor_1, int valor_2);
void troca_valores(int *ponteiro_1, int *ponteiro_2);

void funcao_1_1(){
    float b;
    b = 7;
    printf("printf dentro da funcao_1_1: %4.2f \n", b);
}

void funcao_1(){
    float a;
    a = 4.5;
    funcao_1_1();
    printf("printf dentro da funcao_1: %4.2f \n", a);
    funcao_1_1();
}


int main(int argc, char *argv[]){
    int numero_1;
    int numero_2;

    funcao_1();

    printf(" Digite primero numero \n");
    scanf("%d", &numero_1);
    printf(" Digite segundo numero \n");
    scanf("%d", &numero_2);

    printf("Numeros digitados: %d %d \n", numero_1, numero_2);

    nao_troca_valores(numero_1, numero_2);
    printf("Numeros digitados: %d %d \n", numero_1, numero_2);

    troca_valores(&numero_1, &numero_2);
    printf("Numeros digitados: %d %d \n", numero_1, numero_2);

    return 0;
}

/* Passagem por valor */
void nao_troca_valores(int valor_1, int valor_2) {
    int auxiliar;
    auxiliar = valor_1;
    valor_1 = valor_2;
    valor_2 = auxiliar;
    printf("Dentro da funcao nao_troca_valores: %d %d \n", valor_1, valor_2);
    return;
}
/* Passagem por referência */
void troca_valores(int *ponteiro_1, int *ponteiro_2) {
    int auxiliar;
    auxiliar = *ponteiro_1;
    *ponteiro_1 = *ponteiro_2;
    *ponteiro_2 = auxiliar;
    printf("Dentro da funcao nao_troca_valores: %d %d \n", *ponteiro_1, *ponteiro_2);
    return;
}
