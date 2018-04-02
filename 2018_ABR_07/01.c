#include <stdio.h>
#include <stdlib.h>
/*
Primeiro programa em C
*/
int main(int argc, char *argv[]){
    int numero_1;
    int numero_2;
    printf(" Digite um numero \n");
    scanf("%d", &numero_1);
    numero_2 = numero_1;
    printf("O numero digitado foi: %d \n\n", numero_2);
    return 0;
}
