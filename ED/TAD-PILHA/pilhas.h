//usando vetor estatico
typedef struct pilha Pilha;
Pilha* cria_pilha();

bool empilha(Pilha* p, int info);
bool desempilha(Pilha* p, int *info);

void libera(Pilha** p);
void imprime(Pilha* p);
int tamanho(Pilha* p);
