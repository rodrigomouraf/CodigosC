#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _REG_ESTADO {
    char estado[16];
} ESTADO;

typedef struct _CEL {            //           +------------------+
    ESTADO dado;               //           |     dados        |       B
    struct _CEL *esq;            //           +--------+---------+
    struct _CEL *dir;            //           | esq    |  dir    |   A       C
} CEL; 


typedef struct _REG_FIXO_AUX {
    char Uf[2];
    char delim1;
    char nomeUF[16];
    char delim2;
    char mesoregiaoGeografi[20];
    char delim3;
    char nomeMesorregiao[30];
    char delim4;
    char microregiaoGeograf[20];
    char delim5;
    char nomeMicrorregiao[32];
    char delim6;
    char municipi[8];
    char delim7;
    char codigoMunicipioCompleto[32];
    char delim8;
    char nomeMunicipio[55];
    char delim9;
} REG_FIXO_AUX;

typedef struct _REGISTRO {
    int Uf;
    char nomeUF[17];
    char mesoregiaoGeografi[21];
    char nomeMesorregiao[31];
    char microregiaoGeograf[21];
    char nomeMicrorregiao[33];
    char municipi[9];
    int codigoMunicipioCompleto;
    char nomeMunicipio[56];
} REGISTRO;

typedef struct _CONTABIL {
    char estado[16];
    int quant;
    struct _CONTABIL *proximo; 
} CONTABIL;

/*void insereValor(char teste[16]){
	CONTABIL *first=NULL, *aux, *novo;
	
	novo = (CONTABIL *)malloc( sizeof(CONTABIL) );
    strcpy(novo->estado , teste );
    novo->quant = 1;
    novo->proximo = NULL;
	
	if( first == NULL ) {
		first = novo;
	} else {
		aux = first;
		while( aux->proximo != NULL ){
		
			aux = aux->proximo;
			// nesse ponto, o novo elemento é
			// adicionado ao final da lista
			aux->proximo = novo; 
		}
	} 
}*/

void printEmOrdem(CEL *no ) {  // no == B ; 2)  no = A

	if( no->esq != NULL ) {
        printEmOrdem( no->esq);
    }
    
    printf("Estado: %17s\n",no->dado.estado);    
		
    
	if( no->dir != NULL ) {
        printEmOrdem( no->esq);
    }
    
}

void libera(CEL *no) {  // no == B ; 2)  no = A
    if( no->esq != NULL ) {
        free( no->esq );
    }
    
    free(no->dado.estado);
    
	if( no->dir != NULL ) {
        free( no->dir );
    }
}

int main()
{
	FILE* fp;
	//CONTABIL *first=NULL, *aux3, *novo2; 
    char buffer[4096], * p;
    REG_FIXO_AUX aux;
    int tam, numreg = 0;
    REGISTRO reg;
    CEL *raiz = NULL, *novo,*no,*aux2;

    if ((fp = fopen("ibge_municipios_coluna_fixa.txt", "rt")) == NULL) {
        printf("Arquivo nao encontrado.\n");
        exit(-1);
    }
    // pular o cabe?alho
    fgets(buffer, 4096, fp);
    fgets(buffer, 4096, fp);
    fgets(buffer, 4096, fp);
    fgets(buffer, 4096, fp);
    //
    while (!feof(fp)) {
        // limpa o buffer
        memset(buffer, 0, 4096);
        fgets(buffer, 4096, fp);
        if (strlen(buffer) < 20) {
            break;
        }
        p = buffer;
        // remove a quebra de linha
        while (*p != '\0') {
            if (*p == '\n' || *p == '\r') {
                *p = '\0';
                break;
            }
            p++;
        }
        //
        // comeca a conversao da linha buffer para o registro auxiliar
        numreg++;
        // a magica parte 1
        memcpy((void*)&aux, buffer, sizeof(REG_FIXO_AUX));
        //
        // O problema da ausencia do final de string
        //printf("%s\n", aux.Uf);
        // colocando o \0 nos delimitadores
        aux.delim1 = '\0';
        aux.delim2 = '\0';
        aux.delim3 = '\0';
        aux.delim4 = '\0';
        aux.delim5 = '\0';
        aux.delim6 = '\0';
        aux.delim7 = '\0';
        
        // faz a conversao dos tipos
        memset((void*)&reg, 0, sizeof(REGISTRO));
        // por causa da funcao strcpy, forcar o \0 no final da string
        aux.nomeUF[16] = '\0';
        aux.mesoregiaoGeografi[20] = '\0';
        aux.nomeMesorregiao[30] = '\0';
        aux.microregiaoGeograf[20] = '\0';
        aux.nomeMicrorregiao[32] = '\0';
        aux.municipi[8] = '\0';
        aux.nomeMunicipio[55] = '\0';
        //
        // realiza as conversoes
        //
        reg.Uf = atoi(aux.Uf);
        strcpy(reg.nomeUF, aux.nomeUF);        
        strcpy(reg.mesoregiaoGeografi, aux.mesoregiaoGeografi);
        strcpy(reg.nomeMesorregiao, aux.nomeMesorregiao);
        strcpy(reg.microregiaoGeograf, aux.microregiaoGeograf);
        strcpy(reg.nomeMicrorregiao, aux.nomeMicrorregiao);
        strcpy(reg.municipi, aux.municipi);
        reg.codigoMunicipioCompleto = atoi(aux.codigoMunicipioCompleto);
        strcpy(reg.nomeMunicipio, aux.nomeMunicipio);
        
		//printf("Nro do registro %d\n", numreg);
        //printf("CursoNome: %s\t%s\n", aux.nomeUF, reg.nomeUF);
        
        //printf("Estado: %s\n", reg.nomeUF);
        
        if( reg.nomeUF[0] != '\0' ) {
	        novo = (CEL *)malloc( sizeof(CEL) );
	        if( novo != NULL ) {
	            novo->dir = NULL;
	            novo->esq = NULL;	
	            strcpy(novo->dado.estado, reg.nomeUF);
	            //
	            // ?rvore
	            if( raiz == NULL ) {
	                raiz = novo;
	            } else {
	                // percorre a arvore e realiza a insercao
	                no = raiz;
	                aux2 = no;
	
	                while( no != NULL ) {
	                    if( strcmp(no->dado.estado, novo->dado.estado) < 0 ) {
	                        // direita
	                        if( no->dir == NULL ) {
	                            no->dir = novo;
	                            break;
	                        } else {
	                            no = no->dir;
	                        }
	                    } else {
	                        // esquerda
	                        if( no->esq == NULL ) {
	                            no->esq = novo;
	                            break;
	                        } else {
	                            no = no->esq;
	                        }
	                    }
	                    // insano
	                    if( no == aux2 ) {
	                        // detectado falha de l?gica na rela??o dos dados
	                        printf("\nFalha no loop de insercao\n\n");
	                        break;
						}
	                    aux2 = no;
	                }
	            }
	       	}
	    }
    
    	//
    	// aprese a lista de contados em ordem.
    	printf("\n\n");	
        
    }
    fclose(fp);
	
	printEmOrdem(raiz);
	// liberacao dos nos
	libera(raiz);
	
	/*while( first ) {
		printf("teste 2 %d\n",first->estado);
		aux3 = first;
		first = first->proximo;
		free(aux2);
	}*/

    return 0;
}
