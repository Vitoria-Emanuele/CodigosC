typedef struct no No;
typedef struct fila Fila;

No* cria_no(int info);
Fila* cria_fila();

bool enfileira(Fila* f, int info);
bool desenfileira(Fila* f);
bool procura_fila(Fila* f, int info);

void imprime_fila(Fila* f);
int tamanho_fila(Fila *f);
void libera_fila(Fila** f);
