#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

int main(){
	
	return 0;
    
}


//Arquivo ListaSequencial.h
#define MAX 100
struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};

typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li)

//Arquivo ListaSequencial.c
struct lista{
	int qtd;
	struct aluno dados[MAX];
};

Lista* cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(struct lista));
	if(li != Null)
		li->qtd = 0;
	return li;
}

void libera_lista(Lista* li){
	free(li);
}

int tamanho_lista(Lista* li){
	if(li == NULL)
		return -1;
	else
	return li->qtd;
}

//programa principal
Lista *li;
li = cria_lista();
libera_lista(li);
int x = tamanho_lista(li);
