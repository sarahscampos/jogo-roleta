struct no {
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo;

void logo();
void menu();
int verificaNumValido(int, int v[]);
void criarListaCircular();
void percorrerLista(struct no*, int, float*, float);
int sorteia();
