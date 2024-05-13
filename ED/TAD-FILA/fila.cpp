#include <iostream>
#include "fila.h"

using namespace std;

//estrutura da fila
struct no{
    int info;
    struct no* ant;
};
typedef struct no No;

struct fila{
    struct no* inicio;
    struct no* fim;
};
typedef struct fila Fila;

//funcoes de manipulacao da fila
No* cria_no(int info){
    No* no = (No* )malloc(sizeof(No));

    if(!no){
        return NULL;
    }

    no->info = info;
    no->ant = NULL;
    return no;

}

Fila* cria_fila(){
    Fila* f = (Fila* )malloc(sizeof(Fila));

    if(!f){
        return NULL;
    }

    f->inicio= NULL;
    f->fim= NULL;
    return f;
}

//Lembrando que a fila eh uma estrutura FIFO. A entrada ocorre por um lado e saida por outro, as filas respeitam uma ordem, por isso a inserecao e remocao sao padrao

//A insercao ocorre pelo fim da fila
bool enfileira(Fila* f, int info){
    if(!f){
        return false;
    }

    No* novo = cria_no(info);
    if(!novo){
        return false;
    }

    if(f->inicio == NULL){//fila vazia
        f->inicio = novo;
        f->fim = novo;
        return true;
    }

    f->fim->ant = novo;
    f->fim = novo;
    return true;
}

//A remocao eh feita pelo inicio. O primeiro elemento a entrar eh o primeiro a sair.
bool desenfileira(Fila* f){
    if(!f){
        return false;
    }

    if(f->inicio == NULL){//fila  vazia
        return false;
    }

    No* aux = f->inicio;

    if(aux->ant == NULL){//fila com um elemento
        free(aux);
        f->inicio = NULL;
        f->fim = NULL;
        return true;
    }

    f->inicio = aux->ant;
    free(aux);
    return true;
}

bool procura_fila(Fila* f, int info){
    if(!f){
        return false;
    }

    No* aux = f->inicio;
    while(aux->ant != NULL){
        if(aux->info == info){
            cout << "O elemento pertence a fila." << endl;
            return true;
        }
        aux = aux->ant;
    }
    cout << "O elemento nao pertence a fila." << endl;
    return false;
}

void imprime_fila(Fila* f){
    if(!f){
        return;
    }

    No* aux = f->inicio;
    while(aux != NULL){
        cout << aux->info << " ";
        aux = aux->ant;
    }

    cout << endl;
}

int tamanho_fila(Fila *f){
    if(!f){
        return -1;
    }

    if(f->inicio == NULL){//fila sem elementos
        return 0;
    }

    No* aux = f->inicio;
    int i=0;
    while(aux != NULL){
        i++;
        aux = aux->ant;
    }
    return i;
}

void libera_fila(Fila** f){
    if(!*f){
        return;
    }

    while((*f)->inicio != NULL){
        desenfileira(*f);
    }

    free(*f);
    *f = NULL;
    cout << "Fila Liberada." << endl;
}
