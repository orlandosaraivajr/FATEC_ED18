/*
 * Exercício 4
 *
 * Faça um programa que simule a entrada e saída de clientes em uma
 * fila de banco. Não há limite para o número de clientes que possam
 * ser enfileirados. Armazene nome do cliente e idade do cliente.
 * Entretanto, os clientes podem serão atendidos na seguinte forma:
 * primeiro os clientes da fila preferencial, depois os clientes
 *  da fila convencional.
 *
 * Crie uma função que crie vinte clientes de forma automática.

 * Crie uma função que imprima a fila convencional e a fila preferencial
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 08/05/2018
 */
 #include <iostream>
 #include <stdlib.h>
 #include <sstream>

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
static FILA fila_preferencial;

 void inicializar(){
 	//fila = (FILA) malloc( sizeof(NO) );
    fila = new NO;
    // fila_preferencial = (FILA) malloc( sizeof(NO) );
    fila_preferencial = new NO;
 	fila->prox = NULL;
    fila_preferencial->prox = NULL;
 	return;
 }

 void enqueue(){
     ELEMENTO novo_cliente;
     cout << "Digite o nome do cliente " << endl;
     cin >> novo_cliente.nome;
     cout << "Digite a idade do cliente " << endl;
     cin >> novo_cliente.idade;
     if(novo_cliente.idade >= 65) {
         //FILA aux = (FILA) malloc( sizeof(NO) );
         FILA aux =  new NO;
         aux->cliente = (ELEMENTO) novo_cliente;
         aux->prox  = (FILA)fila_preferencial;
         fila_preferencial = aux;
     } else {
         // FILA aux = (FILA) malloc( sizeof(NO) );
         FILA aux =  new NO;
         aux->cliente = (ELEMENTO) novo_cliente;
         aux->prox  = (FILA)fila;
         fila = aux;
     }
 }

 void enqueue(ELEMENTO novo_cliente){
     novo_cliente.nome;
     novo_cliente.idade;
     if(novo_cliente.idade >= 65) {
         // FILA aux = (FILA) malloc( sizeof(NO) );
         FILA aux =  new NO;
         aux->cliente = (ELEMENTO) novo_cliente;
         aux->prox  = (FILA)fila_preferencial;
         fila_preferencial = aux;
     } else {
         // FILA aux = (FILA) malloc( sizeof(NO) );
         FILA aux =  new NO;
         aux->cliente = (ELEMENTO) novo_cliente;
         aux->prox  = (FILA)fila;
         fila = aux;
     }
 }

 void enfileiramento_automatico(int num_clientes){
     ELEMENTO novo_cliente;
     novo_cliente.nome;
     novo_cliente.idade;
     stringstream ss;
     int x;

     for(x = 0 ; x < num_clientes ; x++) {
        ss << "Cliente_aletarório_" << x+1;
        novo_cliente.nome = ss.str();
        ss.str("");
        novo_cliente.idade = (rand() % 99) + 1;
        enqueue(novo_cliente);
    }


 }

 void mostraFila(){
    FILA no = fila;
    cout << "Fila Convencional " << endl;
 	while(no != NULL){
        if (no->prox != NULL) {
            cout <<"[" << no->cliente.nome << "] -> ";
        }
 		no = no->prox;
 	}

    no = fila_preferencial;
    cout << endl << endl << "Fila preferencial " << endl;
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
    FILA noAnterior;
    FILA noAtual;
    temp.nome = "";
    temp.idade = -1;
    if(fila_preferencial->prox == NULL ) {
        if(fila->prox == NULL ) {
            cout << "Nenhum cliente na fila";
        } else {
            noAnterior = fila;
            noAtual = fila;
         	while(noAtual->prox != NULL){
         		noAnterior = noAtual;
         		noAtual = noAtual->prox;
         	}
         	noAnterior->prox = NULL;
            temp = noAnterior->cliente;
            delete noAnterior;
        }
    } else {
        noAnterior = fila_preferencial;
        noAtual =  fila_preferencial;
     	while(noAtual->prox != NULL){
     		noAnterior = noAtual;
     		noAtual = noAtual->prox;
     	}
     	noAnterior->prox = NULL;
        temp = noAnterior->cliente;
        delete noAnterior;
    }
    return temp;
 }

 int tamanhoFilaPreferencial(){
     FILA fila_local = fila_preferencial;
    int cont = 0;
    while(fila_local != NULL){
        fila_local = fila_local->prox;
        cont++;
    }
    return (cont - 1);
 }

 int tamanhoFilaConvencional(){
     FILA fila_local = fila;
    int cont = 0;
    while(fila_local != NULL){
        fila_local = fila_local->prox;
        cont++;
    }
    return (cont - 1);
 }

 int tamanhoFila(){
    int cont = 0;
    cont = cont + tamanhoFilaPreferencial();
    cont = cont + tamanhoFilaConvencional();
    return (cont);
 }

 void destruir(){
    if(fila->prox != NULL ) {
        FILA noProximo = fila;
        while(noProximo->prox != NULL){
            cout << "| " << noProximo->cliente.nome;
            cout << " - " << noProximo->cliente.idade << endl;
            fila = noProximo->prox;
            noProximo->prox = NULL;
            delete noProximo;
            noProximo = fila;
     	}
    }
    if(fila_preferencial->prox != NULL ) {
        FILA noProximo = fila_preferencial;
        while(noProximo->prox != NULL){
            cout << "| " << noProximo->cliente.nome;
            cout << " - " << noProximo->cliente.idade << endl;
            fila_preferencial = noProximo->prox;
            noProximo->prox = NULL;
            delete noProximo;
            noProximo = fila_preferencial;
        }
    }
    delete fila;
    delete fila_preferencial;
 }

int main(){
     char escolha = 'x';
     ELEMENTO cliente_no_caixa;
     fila = NULL;
     inicializar();
     do {
           cout << "\n********************************\n";
           cout << "Digite uma letra\n\n";
           cout << "w \t Preenchimento automático\n";
           cout << "i \t Inserir na fila\n";
           cout << "a \t Atender cliente\n";
           cout << "p \t Imprimir a fila \n";
           cout << "q \t Encerrar banco.\n\n\n";
           cin >> escolha;
           if(escolha == 'w' || escolha == 'W'){
               int num_clientes;
               cout << "Digite o número de clientes a ser gerado" << endl;
               cin >> num_clientes;
               enfileiramento_automatico(num_clientes);
           }
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
           if(escolha == 'p' || escolha == 'P'){
               cout << "Tamanho da fila: " << tamanhoFila() << endl;
               cout << "Tamanho da fila Preferencial: " << tamanhoFilaPreferencial() << endl;
               cout << "Tamanho da fila Convencional: " << tamanhoFilaConvencional() << endl;
               mostraFila();
           }
       } while( escolha != 'q');

     destruir();
     return 0;
 }
