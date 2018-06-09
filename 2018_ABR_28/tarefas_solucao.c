/*
 * Exercício 3 da lista.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 12/04/2018
 */

 #include <iostream>
 #include <string>
 #include <sstream>

using namespace std;

typedef struct node {
    string tarefa;
    int tempo_horas;
    int id_pessoa;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha * inicializar() {
    Pilha * s = (Pilha *)malloc(sizeof(Pilha));
    s->size = 0;
    s->top = NULL;
}


void push(Pilha *s) {
    string nova_tarefa;
    string horas_necessarias;
    string pessoa;
    int horas;
    int id_pessoa;
    Node *np;

    np = (Node *)malloc(sizeof(Node));
    if (np == NULL) {
        exit(1);
    }
    cout << "Digite o nome da tarefa: \n";
    cin >> nova_tarefa;
    cout << "Digite o numero de horas necessarias: \n";
    cin >> horas_necessarias;
    horas = atoi(horas_necessarias.c_str());
    do {
        cout << "Digite o ID do responsavel: \n";
        cin >> pessoa;
        id_pessoa = atoi(pessoa.c_str());

    }while (id_pessoa > 3 || id_pessoa < 1 );

    np->tempo_horas = horas;
    np->id_pessoa = id_pessoa;
    np->tarefa = nova_tarefa;

    np->next = s->top;
    s->top = np;

    s->size++;
}

void push(Pilha *s, string nova_tarefa,int horas, int id_pessoa) {

    Node *np;
    np = (Node *)malloc(sizeof(Node));

    np->tempo_horas = horas;
    np->id_pessoa = id_pessoa;
    np->tarefa = nova_tarefa;
    np->next = s->top;
    s->top = np;

    s->size++;
}

void imprime_nodo(Node *np) {
    cout << "Tarefa: \t" << np->tarefa << "\t previsto ";
    cout << np->tempo_horas << " horas";
    cout << " atribuido ao ID " << np->id_pessoa << " \n";

}
Node* pop(Pilha *s) {
    Node *np;

    if (s->top == NULL) {
        cout << "Não foi possível desempilhar" << endl;
        exit(-1);
    }

    np = s->top;
    s->top = s->top->next;
    s->size--;
    np->next = NULL;
    return np;
}

void destruir_pilha(Pilha *s) {
    Node *no;
    while (s->top != NULL) {
        no = pop(s);
        // imprime_nodo(no);
        delete no;
    }
    delete s;
}

void preencher_dados(Pilha *s) {

    stringstream ss;
    string tarefa;
    int hora;
    int id_pessoa;
    int x;

    for(x = 0 ; x < 7 ; x++) {
        ss << "Tarefa_" << x+1;
        tarefa = ss.str();
        ss.str("");
        hora = (rand() % 24) + 1;
        id_pessoa = rand() % 3;
        push(s, tarefa, hora, id_pessoa+1);
    }
}

void imprime_pilha(Pilha *s) {
	Node* temp;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
    cout << "HISTÓRICO DE TAREFAS\n";
    cout << "====================\n";
    cout << "Numero de tarefas acumuladas: " << s->size << "\n\n\n";
	while(temp!=NULL){
		cout << "Tarefa: \t" << temp->tarefa << "\t previsto ";
        cout << temp->tempo_horas << " horas";
        cout << " atribuido ao ID " << temp->id_pessoa << " \n";
		temp = temp->next;
	}
    cout << "========================\n\n\n";

	cout << "\n";
}

void maior_tarefa(Pilha *s)  {
	Node* temp;
    Node* maior;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
    maior = temp;

	while(temp!=NULL){

        if(temp->tempo_horas > maior->tempo_horas) {
            maior = temp;
        }

		temp = temp->next;
	}
    cout << "========================\n\n";
    cout << "Maior tarefa: \t" << maior->tarefa << "\t previsto ";
    cout << maior->tempo_horas << " horas";
    cout << " atribuido ao ID " << maior->id_pessoa << " \n";
	cout << "========================\n\n";
}

Pilha* pilha_reversa(Pilha *s) {
    Pilha *pilha_reversa = inicializar();
    Node *no;
    while (s->top != NULL) {
        no = pop(s);
        no->next = pilha_reversa->top;
        pilha_reversa->top = no;
        pilha_reversa->size++;
    }
    delete s;
    return pilha_reversa;
}

int atividade_por_pessoa (Pilha *s, int id) {
    Node *temp;
    int contador = 0;
    if (s->top == NULL) {
        return 0;
    }

    temp = s->top;
    while(temp!=NULL){
        if( temp->id_pessoa == id) {
            // cout << "Tarefa: \t" << temp->tarefa << endl;
            contador++;
        }
        temp = temp->next;
    }
    cout << "========================\n\n";
    return contador;
}

int main() {
    char escolha;
    Node *no;
    Pilha *minhaPilha = inicializar();
    do {
        cout << "\n********************************\n";
        cout << "Digite uma letra\n\n";
        cout << "a \t Preencher dados pre-carregados\n";
        cout << "c \t Cadastrar tarefa\n";
        cout << "d \t Desempilhar tarefa\n";
        cout << "h \t Ver historico de tarefas \n";
        cout << "m \t Descobrir a maior tarefa \n";
        cout << "r \t Pilha reversa \n";
        cout << "p \t Numero de atividade por pessoas \n";
        cout << "q \t Sair da agenda.\n\n";
        cin >> escolha;
        if(escolha == 'a' || escolha == 'A'){
            preencher_dados(minhaPilha);
        }
        if(escolha == 'c' || escolha == 'C'){
            push(minhaPilha);
        }
        if(escolha == 'h' || escolha == 'H'){
            imprime_pilha(minhaPilha);
        }
        if(escolha == 'd' || escolha == 'D'){
            no = pop(minhaPilha);
            imprime_nodo(no);
            delete no;
        }
        if(escolha == 'm' || escolha == 'M'){
            maior_tarefa(minhaPilha);
        }
        if(escolha == 'r' || escolha == 'R'){
            minhaPilha = pilha_reversa(minhaPilha);
        }
        if(escolha == 'p' || escolha == 'P'){
            cout << "Jose tem " << atividade_por_pessoa(minhaPilha,1);
            cout << " atividade(s) previstas." << endl;

            cout << "Maria tem " << atividade_por_pessoa(minhaPilha,2);
            cout << " atividade(s) previstas." << endl;

            cout << "Joao tem " << atividade_por_pessoa(minhaPilha,3);
            cout << " atividade(s) previstas." << endl;
        }
    } while( escolha != 'q');

    destruir_pilha(minhaPilha);
    return 0;
}
