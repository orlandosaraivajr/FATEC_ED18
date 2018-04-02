#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 50
#define TAMANHO_DISCIPLINA 20

int main(int argc, char *argv[]){
    struct ficha_de_aluno {
        char nome[TAMANHO_NOME];
        char disciplina[TAMANHO_DISCIPLINA];
        float nota_1;
        float nota_2;
    };

    struct ficha_de_aluno aluno;

    /*    Entrada de dados    */
    printf(" Digite o nome do aluno: \n");
    fgets( aluno.nome , TAMANHO_NOME, stdin );
    printf(" Digite a disciplina: \n");
    fgets( aluno.disciplina , TAMANHO_DISCIPLINA, stdin );
    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota_1);
    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota_2);

    /* Imprimir resultados  */
    printf("O nome do aluno: %s \n", aluno.nome);
    printf("Disciplina: %s \n", aluno.disciplina);
    printf("Média: %4.2f \n", ( aluno.nota_1 + aluno.nota_2 ) / 2);

    return 0;
}
