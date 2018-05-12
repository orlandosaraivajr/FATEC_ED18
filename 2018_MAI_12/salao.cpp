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

struct Item {
    string  nome;
    int     idade;
};

static Item *fila;
static int N = 5;
static int inicio, fim;

void inicializar(int maxN) {
	fila = (Item *)malloc(maxN * sizeof(Item));
	N = maxN;
	inicio = N - 1;
	fim = 0;
}

void inserir() {
    Item cliente;
    cout << "Digite o nome do cliente: " << endl;
    cin >> cliente.nome;
    cout << "Digite a idade do cliente: " << endl;
    cin >> cliente.idade;
	fila[fim++] = cliente;
	fim = fim % N;
    cout << "DEBUG: início  " << inicio << "\n\n";
    cout << "DEBUG: fim  " << fim << "\n\n";
}

void atender(void) {
	inicio = (inicio + 1) % N;
    cout << " Atendimento para : " << endl;
    cout << fila[inicio].nome <<" - ";
    cout << fila[inicio].idade <<" anos ";
    cout << endl;
    fila[inicio].nome = "";
    fila[inicio].idade = 0;
    cout << "DEBUG: início  " << inicio << "\n\n";
    cout << "DEBUG: fim  " << fim << "\n\n";
}

void imprime_fila() {
    int x;
    cout << "============= FILA ============= " << endl;
	for (x = 0; x < N ; x++) {
        cout << fila[x].nome <<" - ";
        cout << fila[x].idade <<" anos ";
        cout << endl;
    }
    cout << endl;
}

int main(void) {
    char escolha;
    int x;

	inicializar(N);
    do {
          cout << "\n********************************\n";
          cout << "Digite uma letra\n\n";
          cout << "i \t Inserir na fila\n";
          cout << "a \t Atender cliente\n";
          cout << "p \t Imprimir a fila \n";
          cout << "q \t Sair do salão.\n\n\n";
          cin >> escolha;
          if(escolha == 'i' || escolha == 'I'){
              inserir();
          }
          if(escolha == 'a' || escolha == 'A'){
              atender();
          }
          if(escolha == 'p' || escolha == 'P'){
            imprime_fila();
          }
      } while( escolha != 'q');
    free(fila);
	return 0;
}
