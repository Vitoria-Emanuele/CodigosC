#include <iostream>

#include "listad.h"

using namespace std;

//lista duplamente encadeada:

typedef struct nod Nod;
struct nod{
    int info;
    Nod* ant;
    Nod* prox;
};

typedef struct listad Listad;
struct listad{
    Nod* inicio;
    Nod* fim;
};

Nod* cria_nod(int info){
    Nod* nod = (Nod* )malloc(sizeof(Nod));
    if(!nod){ // verifica se o no existe(se foi alocado)
        return NULL;
    }
    nod->info = info;
    nod->ant = NULL;
    nod->prox = NULL;
    return nod;
}

Listad* cria_listad(){
    Listad* ld = (Listad* )malloc(sizeof(Listad));
    if(!ld){ // verifica se a lista existe(se foi alocada)
        return NULL;
    }
    ld->inicio = NULL;
    ld->fim = NULL;
    return ld;
}

bool insere_inicio(Listad* ld, int info){
    if(!ld){ // verifica se a lista existe(se foi alocada)
        return false;
    }

    Nod* novo = cria_nod(info);
    if(!novo){ // verifica se o novo no existe(se foi alocado)
        return false;
    }
    if(ld->inicio == NULL ){ //inserir elementos se a lista eh vazia
        ld->inicio = novo;
        ld->fim = novo;
        return true;
    }

    ld->inicio->ant = novo;
    novo->prox = ld->inicio;
    ld->inicio = novo;
    return true;
}

bool remove_inicio(Listad *ld){
    if(!ld || ld->inicio == NULL){ //verifica se a lista existe ou se esta vazia
        return false;
    }

    if(ld->inicio->prox == NULL){ //remocao quando a lista tem um elemento, ou seja, um elemento eh inicio e fim
        free(ld->inicio);
        ld->inicio = NULL;
        ld->fim = NULL;
        return true;
    }

    ld->inicio = ld->inicio->prox;
    free(ld->inicio->ant);
    ld->inicio->ant = NULL;
    return true;
}

bool insere_fim(Listad* ld, int info){
    if(!ld){ // verifica se a lista existe(se foi alocada)
        return false;
    }

    Nod* novo = cria_nod(info);
    if(!novo){ // verifica se o novo no existe(se foi alocado)
        return false;
    }

    if(ld->fim == NULL){ // verifica se a lista esta vazia, sendo assim o novo no eh o inicio e fim da lista
        ld->inicio = novo;
        ld->fim = novo;
        return true;
    }

    novo->ant = ld->fim;
    ld->fim->prox = novo;
    ld->fim = novo;
    return true;
}

bool remove_fim(Listad* ld){
    if(!ld || !ld->inicio){ //verifica se a lista existe ou se eh vazia
        return false;
    }
    if(ld->fim->ant == NULL){ //remocao quando a lista tem um elemento, ou seja, um elemento eh inicio e fim
        free(ld->fim);
        ld->fim = NULL;
        ld->inicio = NULL;
        return true;
    }

    ld->fim = ld->fim->ant;
    free(ld->fim->prox);
    ld->fim->prox = NULL;
    return true;

}

int tamanho_lista(Listad* ld){
    if(!ld){
        return -1;
    }
    if(ld->inicio == NULL){
        return 0;
    }

    int i;
    Nod* aux = ld->inicio;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}


bool insere_posicao(Listad* ld, int info, int posicao){
    if(!ld || ld->inicio == NULL){//verificando se a lista foi alocada ou se ela esta vazia, se for um dos casos a insercao nao pode ocorrer
        return false;
    }

    int tam = tamanho_lista(ld);
    if(posicao > tam || posicao < 0){//em casos que de a posicao ser invalida
        return false;
    }

    Nod* aux = ld->inicio;
    for(int i=0; i != posicao-1; i++){
        aux = aux->prox;
    }

    Nod* novo = cria_nod(info);
    if(!novo){
        return false;
    }

    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant->prox = novo;
    aux->ant = novo;
    return true;
}

bool remove_posicao(Listad* ld, int posicao){
    if(!ld || ld->inicio == NULL){//verifica se a lista foi alocada ou eh vazia, em algum dos casos a remocao nao pode ser efetuada.
        return false;
    }

    int tam = tamanho_lista(ld);
    Nod* aux = ld->inicio; //usamos o auxiliar para receber os nos ate o no desejado.
    for(int i; i != posicao-1; i++){
        aux = aux->prox;
    }

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    return true;
}

void ordena_cresc(Listad* ld){
    if(!ld || ld->inicio->prox == NULL){ //se a lista nao existe ou tem um elemento
        return;
    }

    Nod* aux = ld->inicio;
    while(aux->prox != NULL){
        Nod* menor = aux;
        Nod* aux2 = aux->prox;
        while(aux2 != NULL){
            if(aux2->info < menor->info){
                menor = aux2;
            }
            aux2 = aux2->prox;
        }
        int i = aux->info;
        aux->info = menor->info;
        menor->info = i;

        aux = aux->prox;
    }
}

void libera_lista(Listad** ld){
    if(!*ld){ //verifica se a lista existe
        return;
    }
    while((*ld)->inicio != NULL){ //remove os elementos por um loop que remove sempre o primeiro elemento, ate o ultimo
        remove_inicio(*ld);
    }
    free(*ld);//libera a lista
    *ld = NULL;
}

void imprime_lista(Listad* ld){
    if(!ld){ //verifica se a lista existe
        return;
    }
    Nod* aux = ld->inicio;
    cout << "LISTA: ";
    while(aux != NULL){ //percorre a lista
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}
