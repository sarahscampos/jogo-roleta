#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


struct no {
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo;


int main() {
    int v[5] = {4, 21, 2, 25, 17};
    int numEscolhido, res;
    float aposta, saldo;
    char continuar;

    criarListaCircular();

    logo();
    menu();


    printf("Insira a sua aposta: ");
    scanf("%f", &aposta);
    float* sal = &saldo;
    saldo = aposta;

    do {
        do {
            printf("Insira o numero escolhido (4, 21, 2, 25, 17): ");
            scanf("%d", &numEscolhido); 
            res = verificaNumValido(numEscolhido, v);  
        } while(res == -1);
        percorrerLista(topo, numEscolhido, sal, aposta);
        printf("Deseja continuar jogando? (S/N) ");
        scanf(" %c", &continuar);

    } while(continuar == 'S');

    printf("Seu saldo final e: %.2f\n", saldo);
    printf("Obrigada por jogar, ate mais!\n");
    


    return 0;
}


void logo() {

printf("\n");  
printf("    //   ) )                                                      //   ) ) \n");
printf("   //___/ /      ___       //      ___     __  ___     ___       //        \n");  
printf("  / ___ (      //   ) )   //     //___) )   / /      //   ) )   //         \n"); 
printf(" //   | |     //   / /   //     //         / /      //   / /   //          \n");
printf("//    | |    ((___/ /   //     ((____     / /      ((___( (   ((____/ /    \n");
printf("\n");

}


void menu() {
    printf("Ola, seja bem-vindo ao RoletaC.\nAs regras sao bem simples, escolha um numero entre os listados a seguir e faca a sua aposta!\nSe voce estiver com sorte e acertar o numero ira ganhar o valor que voce apostou inicialmente, caso contrario esse valor ira ser descontado do seu saldo.\n");
    printf("Saldos negativos sao permitidos, mas nao se esqueca de pagar :v\n");
}

int verificaNumValido(int n, int v[]) {
    for(int i = 0; i < 5; i++) {
        if(n == v[i]) {
            return 1;
        }
    }
    printf("Entre com um numero valido! (4, 21, 2, 25, 17)\n");
    return -1;
}

void criarListaCircular() {
    noPtr p =  (noPtr) malloc (sizeof(struct no));
    noPtr q =  (noPtr) malloc (sizeof(struct no));
    noPtr r =  (noPtr) malloc (sizeof(struct no)); 
    noPtr s =  (noPtr) malloc (sizeof(struct no));
    noPtr t =  (noPtr) malloc (sizeof(struct no));
    

    t->info = 17;
    t->prox = p;
    s->info = 25;
    s->prox = t;
    r->info = 2;
    r->prox = s;
    q->info = 21;
    q->prox = r;
    p->info = 4;
    p->prox = q;

    topo = p;
}

int sorteia() {
    int impulso;
    srand((unsigned)time(NULL));
    impulso = rand() % 10;   //impulso variando de 0 a 9

    return impulso;

}

void percorrerLista(noPtr i, int num, float* sal, float aposta) {
    i = topo;
    int valorImp;

    valorImp = sorteia();


    for(int j = 0; j < valorImp; j++) {
        i = (*i).prox;   

    }
    if(num == (*i).info) {
        printf("Parabens, voce ganhou!\n");
        (*sal) += aposta;
       
    }
    else {
        printf("Voce perdeu, a bolinha parou no %d. Quem sabe na proxima...\n", (*i).info);
        (*sal) -= aposta;
       
    }

  

}


