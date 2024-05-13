#include <iostream>

#include "ListaS.h"

using namespace std;

//lista simplismente encadeada:

//cada no tem armazenada sua informacao e um ponteiro que referencia o proximo no com suas informaçoes.
typedef struct no No;
struct no{
    int info;
    No* prox;
};

//a lista contem todos os nos. Dentro dessa estrutura tem um ponteiro que referencia o primeiro no(o inicio da lista).
typedef struct lista Lista;
struct lista{
    No* prim;
};

No* cria_no(int info){
    No* no = (No* )malloc(sizeof(No)); //alocado um espaco de memoria para o no.
    if(!no){ // verifica se a alocadocao foi feita.
        return NULL;
    }
    //as informacoes do no sao armazenadas.
    no->info = info;
    no->prox = NULL;
    return no;
    //essa funcao cira e aloca na memoria um no, esse no ainda nao faz parte de uma lista.
}

Lista* cria_lista(){
    Lista* l = (Lista* )malloc(sizeof(Lista)); //alocado um espaco de memoria para a lista.
    if(!l){ // verifica se a lista foi alocada.
        return NULL;
    }

    l->prim = NULL; //a lista eh criada vazia.
    return l;
    //essa funcao apenas cria e aloca um espaco de memoria para a lista, ela inicialmente eh vazia.
}

//Agora com uma lista e um no criado vamos ter funcoes que manipulem esses TADs:

bool insere_inicio(Lista* l, int info){
    if(!l){ // verifica se a lista foi alocada
        return false;
    }

    No* novo = cria_no(info); //uso da funcao de criar um novo no
    if(!novo){ // verifica se o novo no foi alocado.
        return false;
    }

    if(l->prim == NULL){ //quando a lista eh vazia
        l->prim = novo;
        return true;
    }
    //Quando a lista tem elementos:
    //Lembrando que a insercao eh pelo inicio da lista. O elemento que antes era o inicio agora eh o proximo do novo elemento. O novo elemento agora eh o primeiro da lista. A cada nova insercao o primeiro elemento da lista muda.
    novo->prox = l->prim;
    l->prim = novo;
    return true;
}

bool remove_inicio(Lista *l){//a remocao vai ser feita pelo inicio da lista.
    if(!l){//verifica se a alocadocao foi feita.
        return NULL;
    }

    if(l->prim == NULL){ //verifica se a lista eh vazia.
        return false;
    }
    //qaundo a lista tem elementos
    No* aux = l->prim->prox; //o auxiliar vai receber todas as informações do segundo elemento da lista, pois nao podemos perde essa referencia.
    free(l->prim); //desalocamos o no que era o primeiro da lista, ele foi excluido.
    l->prim = aux; //agora o auxiliar, que era o segundo elemento, eh referencia de primeiro elemento.
    return true;
}

bool insere_fim(Lista* l, int info){
    if(!l){ // verifica se a alocadocao da lista foi feita.
        return false;
    }

    No* novo = cria_no(info);
    if(!novo){ // verifica se a alocadocao do no foi feita.
        return false;
    }

    if(l->prim == NULL){ // verifica se a lista esta vazia, sendo assim o novo no eh o primeiro elemento da lista alem de ser o inicio eh o fim da lista tambem.
        return insere_inicio(l, info);
    }
    //quando a lista possui elementos:
    No* aux = l->prim; //o auxiliar recebe as informacoes do primeiro elemento.
    while(aux->prox != NULL){ // percorre a lista ate o ultimo elemento, quando proximo do aux for NULL o loop para.
        aux  = aux->prox; //o auxiliar vai recebendo o proximo dele, ate satisfazer a codincao de parada.
    }
    aux->prox = novo; //quando o auxiliar for o ultimo elemento da lista, o proximo elemento, que esta NULL, vai receber o novo elemento sendo ele entao o ultimo da lista.

    return true;
}

bool remove_fim(Lista* l){
    if(!l){ // verifica se a alocadocao da lista foi feita.
        return false;
    }
    if(!l->prim){ //verifica se a lista eh vazia, portanto nao pode haver remocao.
        return false;
    }
    if(l->prim->prox == NULL){ // verifica se a lista tem um elemento.
        return remove_inicio(l); //ser for o caso esse elemento alem de ser o fim tambem eh o incio, logo pode ser removido pela funcao que remove o primeiro elemento.
    }
    //quando a lista possui mais de um elemento:
    No* aux = l->prim; //o auxiliar recebe o primeiro elemento

    while(aux->prox->prox != NULL){ //percorre a lista ate o penultimo elemento. Foi feito assim para nao perde a referencia do penultimo e possa fazer que depois de liberar o ultimo o ponteiro de proximo do penultimo seja atrubuido a null.
        aux = aux->prox; //o auxiliar recebe seu proximo ate satisfazer a codicao
    }

    free(aux->prox); //como o auxiliar vai ser o penultimo elemento, libera-se o proximo do auxiliar, que seria o ultimo.
    aux->prox = NULL; //e o proximo do auxiliar vai ser NULL.
    return true;

}

bool remove_info(Lista* l, int info){
    if(!l || l->prim == NULL){ //verifica se a lista foi alocada ou se ela eh vazia. No caso de uma das condicoes nao tem como ser feita a remocao.
        return false;
    }
    //um no auxiliar inicia pelo primeiro elemento da lista e vai percorre-la ate o no com a informacao desejada
    No* no = l->prim;
    while(no->info != info){
        no = no->prox;
    }
    if(no == l->prim){//se o elemento a ser removido eh o primeiro
        l->prim = no->prox;
        free(no);
        return true;
    }
    //Nao podemos simplismente excluir o no desejado, pois perderemos a referencia e a lista se perde. Criamos um no auxiliar que vai percorrer a lista ate o no anterior do no desejado.
    No* aux = l->prim;
    while(aux->prox != no){
        aux = aux->prox;
    }
    aux->prox = no->prox; //para a lista continuar ligada o no atras do no desejado deve apontar para o proximo desse no.
    free(no); //e entao podemos exclui-lo da lista.
    return true;
}

int tamanho_lista(Lista* l){ //funcao para obtermos o tamanho da lista
    if(!l){
        return -1;
    }
    if(l->prim == NULL){
        return 0;
    }

    int i;
    No* aux= l->prim;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

bool insere_posicao(Lista* l,int info, int posicao){ //funcao para inserir elemento por posicao na lista:
    if(!l || l->prim == NULL){//verifica se a lista foi alocada ou eh vazia, em algum dos casos a remocao nao pode ser efetuada.
        return false;
    }

    int tam = tamanho_lista(l); //usamos a funcao que calcula o tamanho da lista para podermos percorrer essa lista ate a posicao desejada.
    if(posicao > tam){ //em caso de inserir um posicao invalida
        return false;
    }
    No* aux = l->prim; //usamos o auxiliar para receber os nos ate o no desejado.
    for(int i=0; i != posicao-1; i++){
        aux = aux->prox;
    }

    No* aux2 = l->prim;//usamos um outro auxiliar para encontrar o anterior do no desejado para nao perde a referencia e a lista se perder.
    while(aux2->prox != aux){
        aux2= aux2->prox;
    }

    No* novo = cria_no(info);
    if(!novo){
        return false;
    }

    aux2->prox= novo;//com a informacao do no e do seu anterior podemos fazer com que o anterior aponte para o novo no
    novo->prox= aux;//assim o novo no aponta para o no que antes estava na posicao desejada
    return true;
}

bool remove_posicao(Lista* l,int posicao){ //funcao para remover por posicao na lista:
    if(!l || l->prim == NULL){//verifica se a lista foi alocada ou eh vazia, em algum dos casos a remocao nao pode ser efetuada.
        return false;
    }

    int tam = tamanho_lista(l); //usamos a funcao que calcula o tamanho da lista para podermos percorrer essa lista ate a posicao desejada.

    No* aux = l->prim; //usamos o auxiliar para receber os nos ate o no desejado.
    for(int i; i != posicao-1; i++){
        aux = aux->prox;
    }

    No* aux2 = l->prim;//usamos um outro auxiliar para encontrar o anterior do no desejado para nao perde a referencia e a lista se perder.
    while(aux2->prox != aux){
        aux2= aux2->prox;
    }

    aux2->prox= aux->prox;//com a informacao do no e do seu anterior podemos fazer com que o anterior aponte para o proximo do no desejada
    free(aux); //e entao a exclusao ser efetuada
    return true;
    //essa funcao eh bem parecida com a de remover pela informacao.
}

void ordena_cresc(Lista* l){ //funcao para ordenar a lista em ordem crescente
    if(!l || l->prim->prox == NULL){
        return;
    }

    No* aux = l->prim;
    while(aux->prox != NULL){
        No* menor = aux;
        No* aux2 = aux->prox;
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

void libera_lista(Lista** l){ //essa funcao desaloca a memoria. Eh importante fazer isso para que a memoria que nao esta sendo usada seja liberada para uso.
    if(!*l){ //verifica se a lista existe
        return;
    }
    while((*l)->prim != NULL){ //remove os elementos por um loop que remove sempre o primeiro elemento, ate o ultimo
        remove_inicio(*l);
    }
    free(*l);//libera a lista
    *l = NULL;
}

void imprime_lista(Lista* l){//funcao que imprime a lista
    if(!l){ //verifica se a lista existe
        return;
    }
    No* aux = l->prim;
    while(aux != NULL){ //percorre a lista
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}
