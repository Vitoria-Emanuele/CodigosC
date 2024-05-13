typedef struct nod Nod;
typedef struct listad Listad;

Nod* cria_nod(int info);
Listad* cria_listad();

bool insere_inicio(Listad* ld, int info);
bool remove_inicio(Listad* ld);

bool insere_fim(Listad* ld, int info);
bool remove_fim(Listad* ld);

//bool remove_info(Listad* ld, int info);

int tamanho_lista(Listad* ld);

bool insere_posicao(Listad* ld, int info, int posicao);
bool remove_posicao(Listad* ld, int posicao);

void ordena_cresc(Listad* ld);

void libera_lista(Listad** ld);
void imprime_lista(Listad* ld);
