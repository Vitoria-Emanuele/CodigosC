#include <iostream>
#include "fila.h"

using namespace std;

int main()
{
    cout << "Hello world! Fila TAD test\n" << endl;

    Fila* f = cria_fila();

    enfileira(f, 3);
    enfileira(f, 7);
    enfileira(f, 5);
    enfileira(f, 10);
    enfileira(f, 22);

    cout << "Tamanho da fila: " << tamanho_fila(f) << endl;

    imprime_fila(f);

    desenfileira(f);
    desenfileira(f);

    cout << "Tamanho da fila: " << tamanho_fila(f) << endl;
    imprime_fila(f);

    procura_fila(f, 10);

    libera_fila(&f);
    return 0;
}
