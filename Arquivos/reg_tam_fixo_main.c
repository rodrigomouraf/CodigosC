#include <stdio.h>
#include <stdlib.h>

/*
Exemplo do arquivo texto
         1         2         3         4         5         6         7         8         9         0         1         2         3
1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
CursoCod CursoNome Ciclo CodDisc NomeDisc                                                   Professor                        Vagas
47       TADS      1     DS122   Desenvolvimento Web I (turma V2)                           Alexander Kutzke                 20
*/

typedef struct _REG_FIXO_AUX {
    char cursoCod[8];
    char delim1;
    char cursoNome[9];
    char delim2;
    char ciclo[5];
    char delim3;
    char codDisc[7];
    char delim4;
    char nomeDisc[58];
    char delim5;
    char professor[32];
    char delim6;
    char vagas[10];
    char delim7;
} REG_FIXO_AUX;

typedef struct _REGISTRO {
    int cursoCod;
    char cursoNome[10];
    short ciclo;
    char codDisc[7];
    char nomeDisc[59];
    char professor[33];
    int vagas;
} REGISTRO;


int main()
{
    FILE *fp;
    char buffer[4096], *p;
    REG_FIXO_AUX aux;
    int tam,numreg=0;
    REGISTRO reg;

    if( (fp=fopen("tabela_exemplo_coluna_fixa.txt","rt")) == NULL ) {
        printf("Arquivo nao encontrado.\n");
        exit(-1);
    }
    // pular o cabeçalho
    fgets(buffer,4096,fp);
    //
    while( !feof(fp) ) {
        // limpa o buffer
        memset(buffer,0, 4096);
        fgets(buffer,4096,fp);
        if( strlen(buffer) < 20 ) {
            break;
        }
        p = buffer;
        // remove a quebra de linha
        while( *p != '\0' ) {
            if( *p == '\n' || *p == '\r' ) {
                *p='\0';
                break;
            }
            p++;
        }
        //
        // comeca a conversao da linha buffer para o registro auxiliar
        numreg++;
        // a magica parte 1
        memcpy((void *)&aux, buffer, sizeof(REG_FIXO_AUX));
        //
        // O problema da ausencia do final de string
        printf("%s\n", aux.cursoCod );
        // colocando o \0 nos delimitadores
        aux.delim1 = '\0';
        aux.delim2 = '\0';
        aux.delim3 = '\0';
        aux.delim4 = '\0';
        aux.delim5 = '\0';
        aux.delim6 = '\0';
        aux.delim7 = '\0';
        printf("Nro do registro %d\n",numreg);
        printf("CursoCod.: %s\n", aux.cursoCod );
        printf("CursoNome: %s\n", aux.cursoNome );
        printf("Ciclo....: %s\n", aux.ciclo );
        printf("codDisc..: %s\n", aux.codDisc );
        printf("nomeDisc.: %s\n", aux.nomeDisc );
        printf("professor: %s\n", aux.professor );
        printf("vagas....: %s\n", aux.vagas );
        //
        // faz a conversao dos tipos
        memset((void *)&reg , 0, sizeof(REGISTRO) );
        // por causa da funcao strcpy, forcar o \0 no final da string
        aux.cursoCod[7] = '\0';
        aux.cursoNome[8] = '\0';
        aux.ciclo[4] = '\0';
        aux.codDisc[6] = '\0';
        aux.nomeDisc[57] = '\0';
        aux.professor[32] = '\0';
        aux.vagas[9] = '\0';
        //
        // realiza as conversoes
        //
        reg.cursoCod = atoi(aux.cursoCod);
        strcpy(reg.cursoNome , aux.cursoNome );
        reg.ciclo = atoi(aux.ciclo);
        strcpy(reg.codDisc , aux.codDisc );
        strcpy(reg.nomeDisc , aux.nomeDisc );
        strcpy(reg.professor , aux.professor );
        reg.vagas = atoi(aux.vagas);
        printf("Nro do registro %d\n",numreg);
        printf("CursoCod.: %s\t%d\n", aux.cursoCod  , reg.cursoCod );
        printf("CursoNome: %s\t%s\n", aux.cursoNome , reg.cursoNome );
        printf("Ciclo....: %s\t%d\n", aux.ciclo     , reg.ciclo );
        printf("codDisc..: %s\t%s\n", aux.codDisc   , reg.codDisc);
        printf("nomeDisc.: %s\t%s\n", aux.nomeDisc  , reg.nomeDisc);
        printf("professor: %s\t%s\n", aux.professor , reg.professor);
        printf("vagas....: %s\t%d\n", aux.vagas     , reg.vagas);
    }
    fclose(fp);

    return 0;
}
