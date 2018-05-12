/*
 * Exercício 2
 *
 * Um determinado salão atende os clientes por ordem de chegada.
 * Entretanto, pode-se atender um único cliente de cada vez e no salão só
 * existe N cadeiras de espera. Determine o valor de N.
 * Crie uma aplicação que simule a fila de atendimento de clientes.
 * Armazene nome do cliente e idade.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 07/05/2018
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

#define N 4

struct Item {
    string  nome;
    int     idade;
};

struct Fila {
    Item   data[N];
    int     size;
};

static int inicio, fim;

void debug();

void inicializar(Fila *F) {
    int x;
    F->size = 0;
    inicio = N - 1;
	fim = 0;

    for(x=0; x<N; x++) {
        F->data[x].nome = "";
        F->data[x].idade = 0;
    }

}

void inserir(Fila *minhaFila){
    Item cliente_tmp;
    int indice = fim++;
    if ( minhaFila->data[indice].idade == 0) {
        cout << "Digite o nome do cliente \n";
    	cin >> cliente_tmp.nome;
        cout << "Digite a idade \n";
    	cin >> cliente_tmp.idade;
        minhaFila->data[indice] = cliente_tmp;
    	fim = fim % N;
    }
    debug();
}

Item atender(Fila *minhaFila) {
    Item retorno;
    int indice = (inicio + 1) % N;
    if( minhaFila->data[indice].idade == 0) {
        cout << " Nenhum cliente para ser atendido" <<endl;
    } else {
        inicio = indice;
        retorno = minhaFila->data[inicio];
        minhaFila->data[inicio].nome = "";
        minhaFila->data[inicio].idade = 0;
        debug();

    }
    return retorno;
}

void debug() {
    cout << "DEBUG: início  " << inicio << "\n\n";
    cout << "DEBUG: fim  " << fim << "\n\n";
}
void imprime_fila(Fila *minhaFila) {
    int x;
    Item cliente_tmp;
	for (x = 0; x < N ; x++) {
        cliente_tmp = minhaFila->data[x];
        cout << "Nome: \t"<< cliente_tmp.nome;
        cout << "\tidade \t" << cliente_tmp.idade << "\n";
    }
    cout << "\n\n";
}

int main() {
    debug();
    Fila minhaFila;
    Item valor;
    char escolha = 'x';
    inicializar(&minhaFila);

    do {
          cout << "\n********************************\n";
          cout << "Digite uma letra\n\n";
          cout << "i \t Inserir na fila\n";
          cout << "a \t Atender cliente\n";
          cout << "p \t Imprimir a fila \n";
          cout << "q \t Sair do salão.\n\n\n";
          cin >> escolha;
          if(escolha == 'i' || escolha == 'I'){
              inserir(&minhaFila);
          }
          if(escolha == 'a' || escolha == 'A'){
              valor = atender(&minhaFila);
              if(valor.nome != ""){
                  cout << " Atendimento para : " << endl;
                  cout << valor.nome <<" - ";
                  cout << valor.idade <<" anos ";
                  cout << endl;
              }
          }
          if(escolha == 'p' || escolha == 'P'){
            imprime_fila(&minhaFila);
          }
      } while( escolha != 'q');
	return 0;
}
