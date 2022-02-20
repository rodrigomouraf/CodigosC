#include <stdio.h>
#include <stdlib.h>
#include "IListaEstatica.h"
#include "ListaEstaticaMethod.cpp"

int solicitaValor(){
	int valor;
	printf("digite o valor desejado, segundo funcionalidade do menu desejada:");
	scanf("%d", &valor);
	return valor;
}

int main(){
	
	int opcao = 0;
	int valor;
	
	ListE l;
	l.inicio = 0;
	l.fim = 0;

    do {
		printf("\n\n");
        printf("Escolha uma opcao abaixo\n");
        printf("Para perguntar professora como criar a lista estatica digite 1\n");
        printf("Para perguntar professora como liberar lista estatatica digite 2\n");
        printf("Para inserir no inicio digite 3\n");
        printf("Para Inserir no fim digite 4\n");
        printf("Para Inserir ordenadamente digite 5\n");
        printf("Para Remover do início digite 6\n");
        printf("Para Remover do fim digite 7\n");
        printf("Para Remover por valor digite 8\n");
        printf("Para Consultar pelo conteudo digite 9\n");
        printf("Para Consultar pela posicao digite 10\n");
        printf("Para imprimir lista digite 11\n");
        printf("Para sair digite 12\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
				valor = solicitaValor();
                inserir_inicio(&l, valor);
                break;
            case 4:
				valor = solicitaValor();
				inserir_fim(&l, valor);
                break;
            case 5:
                valor = solicitaValor();
				inserir_meio(&l, valor);
                break;
            case 6:
                remover_inicio(&l);
                break;
            case 7:
                remover_fim(&l);
                break;
            case 8:
            	valor = solicitaValor();
            	remover_meio(&l, valor);
            	break;
            case 9:
            	valor = solicitaValor();
            	get_valor(&l, valor);
            	break;
            case 10:
            	valor = solicitaValor();
            	get_posicao(&l, valor);
            	break;
            case 11:
            	get_list(&l);
            	break;
            case 12:
            	printf("Obrigado pelo acesso!!! Ate a proxima.\n");
                break;
        }

    } while (opcao != 12);
	
//	inserir_meio(&l, 7);
//	get_list(&l);
//	inserir_meio(&l, 9);
//	get_list(&l);
//	inserir_meio(&l, 8);
//	get_list(&l);
//	inserir_inicio(&l, 2);
//	get_list(&l);
//	inserir_fim(&l, 0);
//	get_list(&l);
//	inserir_fim(&l, 0);
//	get_list(&l);
//	inserir_meio(&l, 0);
//	get_list(&l);
//	inserir_inicio(&l, 0);
//	get_list(&l);
//	remover_inicio(&l);
//	get_list(&l);
//	inserir_inicio(&l, 12);
//	get_list(&l);
//	remover_fim(&l);
//	get_list(&l);
//	remover_meio(&l, 8);
//	get_list(&l);
//	get_posicao(&l, 2);
//	get_valor(&l, 7);

	return 0;
}



