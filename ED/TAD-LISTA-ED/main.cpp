#include <iostream>
#include "listad.h"

using namespace std;

int main()
{
    cout << "Hello world! Doubly linked list TAD test\n" << endl;

    //Agora vamos usar esses tipos de dados e suas funcoes de manipulacao:

    //primeiro criando uma lista duplamente encadeada. Vamos chamar nosso tipo lista duplamente encadeada de l
    Listad* l = cria_listad();

    //Vamos adicionar elementos nessa lista usando a funcao de inserir pelo inicio
    insere_inicio(l, 10);
    insere_inicio(l, 15);
    insere_inicio(l, 11);
    insere_inicio(l, 25);

    //Vamos imprimir a cada funcao usada pra visualizar as mudancas feitas
    cout << "Lista criada: ";
    imprime_lista(l);

    //Inserir no fim
    insere_fim(l, 3);
    insere_fim(l, 7);

    cout << "Lista atualizada: ";
    imprime_lista(l);

    //Agora vamos inserir em uma posicao. Antes vou imprimir o tamanho da lista
    int t = tamanho_lista(l);
    cout << "\nTamanho da Lista: " << t << " " << endl;

    insere_posicao(l, 0, 2);

    cout << "Elemento inserido na posicao 2. Lista atualizada: ";
    imprime_lista(l);

    //Agora vamos ordenar essa lista
    ordena_cresc(l);
    cout << "Lista ordenada: ";
    imprime_lista(l);

    //Vamos usar as funcoes de remocao
    remove_fim(l);
    cout << "Elemento removido do fim..." << endl;
    imprime_lista(l);

    remove_inicio(l);
    cout << "Elemento removido do inicio: " << endl;
    imprime_lista(l);

    remove_posicao(l, 3);
    cout << "Elemento removido da posicao 3: " << endl;
    imprime_lista(l);


    //Vamos ordena-la novamente
    ordena_cresc(l);
    cout << "Lista Ordenada..." << endl;
    imprime_lista(l);

    //Por fim vamos liberar a memoria que aloca essa lista ja que nao vamos mais usar.
    libera_lista(&l);

    return 0;
}
