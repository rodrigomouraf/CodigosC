#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exemplo de ordena??o e aloca??o din?mica, usando ?rvores bin?rias simples.
*/
typedef struct _REG_CONTATO {
    char nome[81];
    char telefone[21];
} CONTATO;

typedef struct _CEL {            //           +------------------+
    CONTATO dado;                //           |     dados        |       B
    struct _CEL *esq;            //           +--------+---------+
    struct _CEL *dir;            //           | esq    |  dir    |   A       C
} CEL;                           //           +--------+---------+

void printEmOrdem(CEL *no) {  // no == B ; 2)  no = A
    if( no->esq != NULL ) {
        printEmOrdem( no->esq );
    }
    printf("%80s | %20s\n",no->dado.nome, no->dado.telefone);
    if( no->dir != NULL ) {
        printEmOrdem( no->dir );
    }
}

int myGets(const char *buffer, int maxsize) {
   int ch=0;
   char *p;
   
   do {
        ch = getchar();        
        
   } while( ch < 32 && ch != 10 && ch != 13);
      if( ch>31 ) {
          putchar(ch);
      }
   p = (char *)buffer;
   while( ch != EOF && ch != '\n' && ch>31 ) {
       *p = (char)ch;
       p++;
       maxsize--;
       if(maxsize<=1) {
          *p = '\0';
          break;
       }
       ch = getchar();
   }
   *p = '\0';
   return p-buffer;
}


int execArvore()
{
    char nome[81],fone[21]; // 80 + \n
    CEL *raiz = NULL,*novo,*no,*aux;

    printf("Informe uma lista de contatos\n\n");

    do {
        printf("Nome: ");
        myGets(nome,80);
        if( nome[0] != '\0' ) {
            novo = (CEL *)malloc( sizeof(CEL) );
            if( novo != NULL ) {
                novo->dir = NULL;
                novo->esq = NULL;
                printf("Telefone: ");
                myGets(fone,20);
                strcpy(novo->dado.nome, nome);
                strcpy(novo->dado.telefone, fone);
                printf("lido: %s %s\n",novo->dado.nome,novo->dado.telefone);
                //
                // ?rvore
                if( raiz == NULL ) {
                    raiz = novo;
                } else {
                    // percorre a arvore e realiza a insercao
                    no = raiz;
                    aux = no;

                    while( no != NULL ) {
                        printf("No %s\n",no->dado.nome);
                        if( strcmp(no->dado.nome, novo->dado.nome) < 0 ) {
                            // direita
                            if( no->dir == NULL ) {
                                printf("inserido a direita de %s\n",no->dado.nome);
                                no->dir = novo;
                                break;
                            } else {
                                no = no->dir;
                                printf("deslocando-se para direita %s\n",no->dado.nome);
                            }
                        } else {
                            // esquerda
                            if( no->esq == NULL ) {
                                printf("inserido a esquerda de %s\n",no->dado.nome);
                                no->esq = novo;
                                break;
                            } else {
                                printf("deslocando-se para esquerda %s\n",no->dado.nome);
                                no = no->esq;
                            }
                        }
                        // insano
                        if( no == aux ) {
                            // detectado falha de l?gica na rela??o dos dados
                            printf("\nFalha no loop de insercao\n\n");
                            break;
                        }
                        aux = no;
                    }
                }
            }
        }
    } while( nome[0] != '\0' );

    //
    // aprese a lista de contados em ordem.
    printf("\n\n");
    printEmOrdem(raiz);
    // liberacao dos nos
    // free

    return 0;
}


int main() {
    execArvore();
    
    return 0;
}
