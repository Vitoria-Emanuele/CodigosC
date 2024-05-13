#include <iostream>
#include "pilhas.h"

#define MAX 10

using namespace std;

//A estrutura da pilha eh composta por um vetor, com tamanho maximo de 10 elementos, e um numero que representa seu topo
//Observacao sobre o topo: a medida que sao inseridos elementos esse topo aumenta, lembrando que os indices de vetores inicia no 0, portanto inicialmente recebe -1 que significa que esta vazia
struct pilha{
    int info[MAX];
    int topo;

};
typedef struct pilha Pilha;

Pilha* cria_pilha(){
    Pilha* p = (Pilha* )malloc(sizeof(Pilha));

    if(!p){
        return NULL;
    }

    p->topo = -1; //como nao ha elementos na pilha seu topo eh -1
    return p;
}

//funcao que insere elementos na pilha
bool empilha(Pilha* p, int info){
    if(!p){ //se a pilha nao estiver alocada
        return false;
    }

    if(p->topo == MAX-1){ //se a pilha ja estiver cheia
        return false;
    }

    p->info[p->topo] = info; //a nova informacao vai ser inserida no vetor no indice que esta o topo
    (p->topo)++; //o topo muda
    return true;
}

//funcao que remove elementos da pilha
bool desempilha(Pilha* p, int *info){
    if(!p || !info || p->topo == -1){ //se nao houve alocacao da pilha ou das informcoes ou a pilha esta vazia
        return false;
    }

    *info = p->info[p->topo];
    (p->topo)--;
    return true;
}

//funcao que libera a memoria alocada para a pilha
void libera(Pilha** p){
    free(*p);
    *p = NULL;
}

//funcao que imprime os valores da pilha
void imprime(Pilha* p){
    if(!p){
        return;
    }

    cout << "PILHA: ";
    for(int i=-1; i < p->topo; i++){
        cout << p->info[i] << " ";
    }
    cout << endl;
}

//funcao que retorna o tamanho da pilha
int tamanho(Pilha* p){
    if(!p){
        return -1;
    }
    return(p->topo + 1);
}
