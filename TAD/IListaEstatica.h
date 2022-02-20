#define MAX 4

typedef struct EDE{
	int dados[MAX];
	int inicio, fim;
} ListE;

//Funções de retorno da lista
void get_list(ListE* l);
void get_posicao(ListE* l, int posicao);
void get_valor(ListE* l, int dado);

//Funções de exclusão
void remover_inicio(ListE* l);
void remover_fim(ListE* l);
void remover_meio(ListE* l, int dado);

//Funções de Inserção
void inserir_fim(ListE* l, int dado);
void inserir_meio(ListE* l, int dado);
void inserir_inicio(ListE* l, int dado);
void retorna_status_insercao(int ret);
