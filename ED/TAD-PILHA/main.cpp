#include <iostream>
#include "pilhas.h"

using namespace std;

int main()
{

    cout << "Hello world! Testing stack TAD\n" << endl;

    Pilha* p = cria_pilha();

    empilha(p, 2);
    empilha(p, 5);
    empilha(p, 6);
    empilha(p, 0);

    cout << "Tamanho da pilha: " << tamanho(p) << endl;
    imprime(p);


    int info;
    desempilha(p, &info);

    cout << "Valor removido: " << info << endl;
    cout << "Tamanho da pilha: " << tamanho(p) << endl;
    imprime(p);


    libera(&p);
    cout << "Pilha liberada." << endl;
    return 0;
}
