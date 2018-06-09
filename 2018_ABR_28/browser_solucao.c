/*
 * Exercício 2 da lista
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 10/04/2018
 */

 #include <stdio.h>
 #include <iostream>
 #include <stdlib.h>

 using namespace std;

typedef struct node {
    string url;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha * inicializar() {
    Pilha * s = (Pilha *)malloc(sizeof(Pilha));
    s->size = 0;  // Setar o tamanho da pilha como zero.
    s->top = NULL; // o topo da pilha é NULL
}

void push(Pilha *s) {
    string url_visitada;
    Node *np;  // Criar um ponteiro de Node (nó)

    np = (Node *)malloc(sizeof(Node));  // Alocar Node na memória
    if (np == NULL) {
        exit(1);
    }
    cout << "Digite o site visitado: \n";
    cin >> url_visitada;
    np->url = url_visitada; // Setar o valor no Node.
    np->next = s->top; // Copiar o último endereço que estará no topo da pilha
    s->top = np; // O topo está apontando para o novo Node criado .

    s->size++; // Incrementar o tamanho do contador de pilha
}

string pop(Pilha *s) {
    string temp;
    Node *np;

    if (s->top == NULL) {
        return "";
    }

    np = s->top; // Um ponteiro de nó está apontando para o topo da pilha.
    temp = s->top->url; // armazenar em temp o valor corrente do topo da pilha.
    s->top = np->next; // fazer o topo da pilha apontar para o nó abaixo
    s->size--; // decrementar o tamanho da pilha
    free(np); // desalocar o nó topo

    return temp; // retornar o valor desempilhado
}

void destruir_pilha(Pilha *s) {
    while (s->top != NULL) {
        pop(s);
    }
    pop(s);
    free(s);
}

void imprime_pilha(Pilha *s) {
	Node* temp;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
    cout << "HISTÓRICO DE NAVEGAÇÃO\n";
    cout << "========================\n";
    cout << "Numero de sites acessados \n# " << s->size << "\n";
	while(temp!=NULL){
		cout << temp->url << "\n";
		temp = temp->next;
	}
    cout << "========================\n\n\n";

	printf("\n");
}

int main() {
    string valor;
    char escolha;
    Pilha *minhaPilha = inicializar();

    do {
        cout << "\n********************************\n";
        cout << "Digite uma letra\n\n";
        cout << "n \t Navegar em um site\n";
        cout << "v \t Pressione botão voltar\n";
        cout << "h \t Ver historico de acesso \n";
        cout << "q \t Sair do navegador.\n\n\n";
        cin >> escolha;
        if(escolha == 'n' || escolha == 'N'){
            push(minhaPilha);
        }
        if(escolha == 'h' || escolha == 'H'){
            imprime_pilha(minhaPilha);
        }
        if(escolha == 'v' || escolha == 'V'){
            valor = pop(minhaPilha);
            if(valor.size() > 0 ){
                cout << "\n\nSite que voltou:\t " << valor << "\n\n";
            } else {
                cout << "\n\nNenhum site acessado anteriormente. \n\n";
            }

        }
    } while( escolha != 'q');

    destruir_pilha(minhaPilha);
    return 0;
}
