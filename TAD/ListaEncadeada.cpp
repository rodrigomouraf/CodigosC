typedef struct len{
	int dado;
	struct LEN * prox;
}Encadeada;

int insere_fim(Encadeada **lista, int d){
	Encadeada *aux;
	aux = (Encadeada*)malloc(sizeof(Encadeada));
	aux->dado=d;
	aux->prox=null;
	*lista=aux;
}

void main(){
	int ret;
	Encadeada *L;
	L = null;
	ret = insere_fim(&L, 7);
}
