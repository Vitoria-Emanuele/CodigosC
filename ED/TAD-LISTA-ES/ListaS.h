//Lista simplesmente encadeada:

typedef struct no No;
typedef struct lista Lista;

No* cria_no(int info);
Lista* cria_lista();

bool insere_inicio(Lista* l,int info);
bool remove_inicio(Lista* l);

bool insere_fim(Lista* l, int info);
bool remove_fim(Lista* l);

bool remove_info(Lista* l, int info);

int tamanho_lista(Lista *l);

bool insere_posicao(Lista* l, int info, int posicao);
bool remove_posicao(Lista* l, int posicao);

void ordena_cresc(Lista* l);

void libera_lista(Lista** l);

void imprime_lista(Lista *l);
