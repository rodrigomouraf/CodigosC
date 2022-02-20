#include <stdio.h>
#include <stdlib.h>
#include "IListaEstatica.h"
#include "ListaEstaticaMethod.cpp"

int main(){
	int ret;
	
	ListE l, la, lb, lc;
	
	l.inicio = 0;
	l.fim = 0;
	
	inserir_meio(&l, 7);
	get_list(&l);
	inserir_meio(&l, 9);
	get_list(&l);
	inserir_meio(&l, 8);
	get_list(&l);
	inserir_inicio(&l, 2);
	get_list(&l);
	inserir_fim(&l, 0);
	get_list(&l);
	inserir_fim(&l, 0);
	get_list(&l);
	inserir_meio(&l, 0);
	get_list(&l);
	inserir_inicio(&l, 0);
	get_list(&l);
	remover_inicio(&l);
	get_list(&l);
	inserir_inicio(&l, 12);
	get_list(&l);
	remover_fim(&l);
	get_list(&l);
	remover_meio(&l, 8);
	get_list(&l);
	get_posicao(&l, 2);
	get_valor(&l, 7);

	return 0;
}



