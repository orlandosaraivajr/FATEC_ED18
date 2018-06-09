/*
 * Exercício 3
 *
 * Faça um programa que simule a entrada e saída de clientes em uma fila de banco.
 * Não há limite para o número de clientes que possa ser enfileirados.
 * Armazene nome do cliente e idade do cliente.
 *
 * Crie uma função que busque clientes pelo nome.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 08/05/2018
 */
 #include <iostream>
 #include <stdlib.h>

using namespace std;

typedef struct {
    string nome;
    int idade;
}ELEMENTO;

 typedef struct NO{
 	ELEMENTO cliente;
 	struct NO* prox;
 }*FILA;

static FILA fila;

 void inicializar(){
 	fila = (FILA) malloc( sizeof(NO) );
 	fila->prox = NULL;
 	return;
 }

 void enqueue(){
     ELEMENTO novo_cliente;
     cout << "Digite o nome do cliente " << endl;
     cin >> novo_cliente.nome;
     cout << "Digite a idade do cliente " << endl;
     cin >> novo_cliente.idade;
     FILA aux = (FILA) malloc( sizeof(NO) );
  	 aux->cliente = (ELEMENTO) novo_cliente;
  	 aux->prox  = (FILA)fila;
     fila = aux;

 }

 void mostraFila(){
    FILA no = fila;
 	while(no != NULL){
        if (no->prox != NULL) {
            cout <<"[" << no->cliente.nome << "] -> ";
        }

 		no = no->prox;
 	}
 	cout << endl;
 }

 ELEMENTO dequeue(){
    ELEMENTO temp;
    temp.nome = "";
    temp.idade = -1;
    if(fila->prox == NULL ) {
        cout << "Nenhum cliente na fila";
    } else {
        FILA noAnterior = fila;
        FILA noAtual = fila;
     	while(noAtual->prox != NULL){
     		noAnterior = noAtual;
     		noAtual = noAtual->prox;
     	}
     	noAnterior->prox = NULL;
        temp = noAnterior->cliente;
     	free(noAnterior);
    }
    return temp;
 }

 int tamanhoFila(){
     FILA fila_local = fila;
 	int cont = 0;
 	while(fila_local != NULL){
 		fila_local = fila_local->prox;
        cont++;
 	}
 	return (cont - 1);
 }

 void destruir(){
    if(fila->prox != NULL ) {
        FILA noProximo = fila;
        while(noProximo->prox != NULL){
            cout << "| " << noProximo->cliente.nome;
            cout << " - " << noProximo->cliente.idade << endl;
            fila = noProximo->prox;
            noProximo->prox = NULL;
            free(noProximo);
            noProximo = fila;
     	}
    }
 }

 int buscaFila(string ch){
     FILA noProximo = fila;
     int cont = tamanhoFila();
     while(noProximo != NULL){
         if (ch == noProximo->cliente.nome) {
             return cont;
         }
         cont--;
         noProximo = noProximo->prox;
     }
     return cont;
 }

 int main(){
     char escolha = 'x';
     ELEMENTO cliente_no_caixa;
     fila = NULL;
     inicializar();
     do {
           cout << "\n********************************\n";
           cout << "Digite uma letra\n\n";
           cout << "i \t Inserir na fila\n";
           cout << "a \t Atender cliente\n";
           cout << "e \t Encontrar cliente na fila \n";
           cout << "p \t Imprimir a fila \n";
           cout << "q \t Encerrar banco.\n\n\n";
           cin >> escolha;
           if(escolha == 'i' || escolha == 'I'){
               enqueue();
           }
           if(escolha == 'a' || escolha == 'A'){
               cliente_no_caixa = dequeue();
               if(cliente_no_caixa.nome != ""){
                   cout << " Atendimento para : " << endl;
                   cout << cliente_no_caixa.nome <<" - ";
                   cout << cliente_no_caixa.idade <<" anos ";
                   cout << endl;
               }
           }
           if(escolha == 'e' || escolha == 'E'){
               string cliente_procurado;
               cout << " Digite o nome do cliente procurado : " << endl;
               cin >> cliente_procurado;
               cout << "O cliente "<< cliente_procurado ;
               cout << " encontra-se na posicao "<< buscaFila(cliente_procurado);
               cout << " da fila" << endl;
           }
           if(escolha == 'p' || escolha == 'P'){
               cout << "Tamanho da fila: " << tamanhoFila() << endl;
               mostraFila();
           }
       } while( escolha != 'q');

     destruir();
     free(fila);
     return 0;
 }
