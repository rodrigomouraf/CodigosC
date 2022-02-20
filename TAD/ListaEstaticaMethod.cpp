int valida_list(ListE* l){

	if(l == NULL){
		retorna_status_insercao(3);
		return 0;
	}
	
	if(l->fim > MAX){
		retorna_status_insercao(2);
		return 0;
	}		
		
	return 1;		
}

//Funções de retorno da lista
void get_list(ListE* l){
	
	if(l == NULL)
		return retorna_status_insercao(3);
	
	printf("\n Os valore da lista sao: ");
	for(int i = 0; i < l->fim; i++){
		printf("%d ",l->dados[i]);
	}
	printf("\n");
	
}

void get_posicao(ListE* l, int posicao){
	printf("\nEntrado no metodo de busca por posicao\n");
	
	if(l == NULL || posicao <= 0 || posicao > l->fim){
		printf("Nao foi possivel encontrar o valor da sua lista nesta posicao,\nverifique se sua consulta esta respeitando o limite de sua lista, que no momento eh de 1 ah %d", l->fim);
	}else{
		printf("O valor da lista para a posicao %d eh: %d\n", posicao, l->dados[posicao-1]);
	}
}

void get_valor(ListE* l, int dado){
	printf("\nEntrado no metodo de busca por valor\n");
	
	if(l == NULL){
		printf("Lista vazia");
	}else{
		
		int i = 0;
		while(i<l->fim && l->dados[i] != dado){
			i++;
		}
		
		if(i == l->fim){
			printf("O valor %d nao foi encontrado na lista");
		}else{
			printf("O valor %d, existe na lista e esta na posicao: %d\n", l->dados[i], i+1);	
		}
		
	}
}

//Funções de exclusão

void remover_inicio(ListE* l){
	printf("\nsolicitado a remocao do primeiro item da Lista %d\n", l->dados[0]);
	
	if(l != NULL){
		int fim=l->fim-1;
		for(int i = 0; i <= fim; i++){
			l->dados[i] = l->dados[i+1];
		}
				
		l->fim--;		
	}else{
		retorna_status_insercao(3);
	}
}

void remover_fim(ListE* l){
	printf("\nsolicitado a remocao do ultimo item da Lista %d\n", l->dados[l->fim-1]);
	
	l->fim--;
}

void remover_meio(ListE* l, int dado){
	printf("\nsolicitado a remocao do valor: %d \n", dado);
	
	int fim = l->fim-1;
	int remover = -1;
	for(int i=0; i <= fim; i++){
		if(l->dados[i] == dado)
			remover = i;
	}
	
	if(remover == -1){
		printf("Valor %d nao encontrado na lista!!!\n", dado);
	}else{
		for(remover; remover <= fim; fim--){		
			l->dados[remover] = l->dados[remover+1];		
		}
		
		l->fim--;
	}
	
}

//Funções de Inserção

void inserir_inicio(ListE* l, int dado){
	
	printf("\nsolicitado a insercao do valor: %d no inicio da lista\n", dado);
	
	if(valida_list(l)){
		
		int fim=l->fim;
		for(fim; fim >= 1; fim--){
			l->dados[fim] = l->dados[fim-1];
		}
		
		l->dados[0] = dado;
		l->fim++;
	}
	
}

void inserir_fim(ListE* l, int dado){
	
	printf("\nsolicitado a insercao do valor: %d no fim da lista\n", dado);
	
	if(valida_list(l)){
		l->dados[l->fim] = dado;
		l->fim++;
		
		retorna_status_insercao(1);		
	}
}

void inserir_meio(ListE* l, int dado){
	
	printf("\nsolicitado a insercao do valor: %d ordenadamente na lista\n", dado);
	
	if(valida_list(l)){
		
		int posicao_insere = 0;
		while(posicao_insere < l->fim && l->dados[posicao_insere] < dado)
			posicao_insere++;
		
		
		for(int fim_list = l->fim; fim_list >= posicao_insere; fim_list--){		
			l->dados[fim_list] = l->dados[fim_list-1];		
		} 	
		
		l->dados[posicao_insere] = dado;	
		l->fim++;
		
		return retorna_status_insercao(1);
	}
	
	
}

void retorna_status_insercao(int ret){
	
	switch(ret){
		case 0:
			printf("Nao foi possivel a insercao\n");
			break;
		case 1:
			printf("Numero Inserido Com Sucesso!!!\n");
			break;
		case 2:
			printf("Nao foi possivel a insercao - Lista Cheia!!!\n");
			break;
		case 3:
			printf("Lista NULL!!!\n");
			break;
	}
			
}

