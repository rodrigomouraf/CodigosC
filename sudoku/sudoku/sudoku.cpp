#include <stdio.h>

void PrintaSudoku();
void SelecionaLinha(int existe, int num[9]);
void SelecionaColuna(int existe, int num[9]);
void SelecionaGrupo(int existe, int num[9]);
void VerificaValores(int parametro);
void NaoAceita(int linha, int coluna, int grupo);
void GeraInfoContemVizinho(int verificaLinha[2], int verificaColuna[2], int linha, int coluna, int respostaAvancada[9][2]);
void GerenciaRespAvancada(int lin, int col, int respostaAvancada[9][2], int existe);
void VerificaCelula(int linha, int coluna, int grupo);
void VerificacaoAvancada(int linha, int coluna, int grupo, int resposta[9], int respostaAvancada[9][2]);
int VerificaExistencia(int linha, int coluna);
void ProcuraValores(int seleciona);
void GeraNum(int* num);
void VerifLinColGrpTest(int verificaLinha[2], int verificaColuna[2], int linha, int coluna);
void CriaGrupo(int* grupoLin, int* grupoCol, int grupo);
void CriarSudoku();

int sudoku[9][9];

int main()
{  
    int opcao = 0;

    CriarSudoku();

    do {

        printf("Escolha uma opcao abaixo\n");
        printf("Para verificar a Matriz Sudoku digite 1\n");
        printf("Para verificar quais valores faltam em uma linha digite 2\n");
        printf("Para verificar quais valores faltam em uma coluna digite 3\n");
        printf("Para verificar quais valores faltam em um grupo digite 4\n");
        printf("Para verificar quais valores podem conter uma celula digite 5\n");
        printf("Para verificar quais valores uma celula nao pode conter digite 6\n");
        printf("Caso deseje sair da aplicacao digite 0\n");

        scanf_s("%d", &opcao);
        printf("\n\n");

        switch (opcao)
        {
            case 1:
                PrintaSudoku(); 
                break;
            case 2:
                ProcuraValores(1);
                break;
            case 3:
                ProcuraValores(2);
                break;
            case 4:
                ProcuraValores(3);
                break;
            case 5:
                VerificaValores(1);
                break;
            case 6:
                VerificaValores(2);
                break;
            case 0:
                printf("Obrigado pelo acesso!!! Ate a proxima.\n");
                break;
        }

    } while (opcao);
}

void PrintaSudoku() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 2 || j == 5 || j == 8) {
                printf("%d   ", sudoku[i][j]);
            }
            else {
                printf("%d ", sudoku[i][j]);
            }
        }
        if (i == 2 || i == 5 || i == 8) {
            printf("\n\n");
        }
        else {
            printf("\n");
        }
    }

}

void SelecionaLinha(int existe, int num[9]) {

    int linha = 0;
    printf("Digite a linha que voce deseja analisar:\n");
    scanf_s("%d", &linha);

    GeraNum(num);

    linha--;

    printf("A linha que voce selecionou tem os seguintes valores:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", sudoku[linha][i]);
    }
    printf("\n");

    printf("Os valores que faltam sao:\n");
    for (int i = 0; i < 9; i++) {
        existe = 0;
        for (int j = 0; j < 9; j++) {

            if (num[i] == sudoku[linha][j]) {
                existe++;
            }

        }

        if (existe == 0) {
            printf("%d ", num[i]);
        }
    }

    printf("\n\n");
}

void SelecionaColuna(int existe, int num[9]) {

    int coluna = 0, i = 0, j = 0;
    printf("Digite a coluna que voce deseja analisar:\n");
    scanf_s("%d", &coluna);

    GeraNum(num);

    coluna--;

    printf("A linha que voce selecionou tem os seguintes valores:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", sudoku[i][coluna]);
    }
    printf("\n");

    printf("Os valores que faltam sao:\n");
    for (int i = 0; i < 9; i++) {
        existe = 0;
        for (int j = 0; j < 9; j++) {

            if (num[i] == sudoku[j][coluna]) {
                existe++;
            }

        }

        if (existe == 0) {
            printf("%d ", num[i]);
        }
    }

    printf("\n\n");
}

void SelecionaGrupo(int existe, int num[9]) {
    int grupoLin[3], grupoCol[3], i = 0, j = 0;

    int grupo = 0;
    printf("Digite o grupo que voce deseja analisar:\n");
    printf("Lembrando que os grupos vao de 1 a 9, da esquerda para a direita\n");
    scanf_s("%d", &grupo);
    printf("\n");

    CriaGrupo(grupoLin, grupoCol, grupo);
    GeraNum(num);

    grupo--;

    printf("O grupo que voce selecionou tem os seguintes valores:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", sudoku[grupoLin[i]][grupoCol[j]]);
        }
    }

    printf("\n");

    printf("Os valores que faltam sao:\n");
    for (int i = 0; i < 9; i++) {
        existe = 0;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (num[i] == sudoku[grupoLin[j]][grupoCol[k]]) {
                    existe++;
                }
            }
        }

        if (existe == 0) {
            printf("%d ", num[i]);
        }


    }

    printf("\n\n");


}

void VerificaValores(int parametro) {
    int existe = 0, linha = 0, coluna = 0, grupo = 0, existencia = 0;

    printf("Digite a linha que voce deseja analisar:\n");
    scanf_s("%d", &linha);
    linha--;
    printf("Digite a coluna que voce deseja analisar:\n");
    scanf_s("%d", &coluna);
    coluna--;
    printf("Digite o grupo ao qual a celula pertence:\n");
    printf("Lembrando que os grupos vao de 1 a 9, da esquerda para a direita\n");
    scanf_s("%d", &grupo);

    if (VerificaExistencia(linha, coluna)) {
        printf("Essa celula ja contem valor definido.\n\n");
        existencia++;
    }

    if (parametro == 1 && existencia == 0) {
        VerificaCelula(linha, coluna, grupo);

    }

    if (parametro == 2 && existencia == 0) {
        NaoAceita(linha, coluna, grupo);

    }
}

void NaoAceita(int linha, int coluna, int grupo) {
    int num[9], grupoLin[3], grupoCol[3], naoAceita[9], itera = 0;

    GeraNum(num);
    CriaGrupo(grupoLin, grupoCol, grupo);

    for (int i = 0; i < 9; i++) {
        naoAceita[i] = 0;
    }

    for (int i = 0; i < 9; i++) {

        if (sudoku[linha][i] != 0) {
            naoAceita[sudoku[linha][i] - 1] = sudoku[linha][i];
        }

        if (sudoku[i][coluna] != 0) {
            naoAceita[sudoku[i][coluna] - 1] = sudoku[i][coluna];
        }

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (sudoku[grupoLin[j]][grupoCol[k]] != 0) {

                    naoAceita[sudoku[grupoLin[j]][grupoCol[k]] - 1] = sudoku[grupoLin[j]][grupoCol[k]];
                }
            }
        }
    }


    printf("Os valores que nao sao aceitos na celula sao:\n");
    for (int i = 0; i < 9; i++) {

        if (naoAceita[i] != 0) {

            printf("%d ", naoAceita[i]);
        }
    }

    printf("\n\n");
}

void GeraInfoContemVizinho(int verificaLinha[2], int verificaColuna[2], int linha, int coluna, int respostaAvancada[9][2]) {
    int existeLinha = 0, existeColuna = 0;
    for (int i = 0; i < 2; i++) {
        existeLinha = 0;

        if (sudoku[verificaLinha[i]][coluna] != 0) {

            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    if (respostaAvancada[j][0] == sudoku[verificaLinha[i]][k]) {
                        existeLinha++;
                    }
                }

                if (i == 0 && existeLinha == 0)
                    respostaAvancada[j][1] = respostaAvancada[j][1] + 1;

                if (i == 1 && existeLinha == 0)
                    respostaAvancada[j][1] = respostaAvancada[j][1] + 1;
            }
        }

        if (sudoku[linha][verificaColuna[i]] != 0) {

            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    if (respostaAvancada[j][0] == sudoku[k][verificaColuna[i]]) {
                        existeColuna++;
                    }
                }

                if (i == 0 && existeColuna == 0)
                    respostaAvancada[j][1] = respostaAvancada[j][1] + 1;

                if (i == 1 && existeColuna == 0)
                    respostaAvancada[j][1] = respostaAvancada[j][1] + 1;
            }
        }
    }
}

void GerenciaRespAvancada(int lin, int col, int respostaAvancada[9][2], int existe) {

    if (existe == 1) {
        for (int i = 0; i < 9; i++) {
            if (respostaAvancada[i][0] != 1 && respostaAvancada[i][0] != 2 && respostaAvancada[i][0] != 3
                && respostaAvancada[i][0] != 4 && respostaAvancada[i][0] != 5 && respostaAvancada[i][0] != 6
                && respostaAvancada[i][0] != 7 && respostaAvancada[i][0] != 8 && respostaAvancada[i][0] != 9) {
                respostaAvancada[i][0] = sudoku[lin][col];
                respostaAvancada[i][1] = 1;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < 9; i++) {
            if (respostaAvancada[i][0] == sudoku[lin][col]) {
                respostaAvancada[i][1] = respostaAvancada[i][1] + 1;
            }
        }
    }

}

void VerificaCelula(int linha, int coluna, int grupo) {
    int num[9], existe = 0, conta = 0, unico = 0, numItera = 0, matrizSolucao[27], grupoLin[3], grupoCol[3], resposta[9], respostaAvancada[9][2];
    int qtdResLinha = 0, respostaResult = 0;

    GeraNum(num);
    CriaGrupo(grupoLin, grupoCol, grupo);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            respostaAvancada[i][j] = 0;
        }
    }

    for (int i = 0; i < 9; i++) {
        matrizSolucao[numItera] = sudoku[linha][i];
        numItera++;
    }

    for (int i = 0; i < 9; i++) {
        matrizSolucao[numItera] = sudoku[i][coluna];
        numItera++;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizSolucao[numItera] = sudoku[grupoLin[i]][grupoCol[j]];
            numItera++;
        }
    }

    for (int i = 0; i < 9; i++) {
        existe = 0;
        for (int j = 0; j < 27; j++) {
            if (num[i] == matrizSolucao[j]) {
                existe++;
                conta++;
            }
        }

        if (existe == 0) {
            resposta[i] = num[i];
            unico = num[i];
        }
    }

    if (conta == 1) {
        printf("Nessa celula existe apenas uma solução, o valor %d\n", unico);
    }
    else {
        VerificacaoAvancada(linha, coluna, grupo, resposta, respostaAvancada);
    }

    for (int i = 0; i < 9; i++) {

        if (respostaAvancada[i][0] != 0) {

            qtdResLinha++;
        }

        if (respostaAvancada[i][1] == 4) {
            respostaResult = respostaAvancada[i][0];
        }
    }

    printf("Os possiveis valores para a celula sao:\n");
    for (int i = 0; i < 9; i++) {
        if (respostaAvancada[i][0] != 0)
            printf("%d ", respostaAvancada[i][0]);
    }
    printf("\n");

    if (qtdResLinha == 1) {
        printf("Realizado uma analise avancada\n");
        printf("A resposta para a linha eh: %d\n", respostaAvancada[0][0]);
        printf("Adionado valor na matriz!!!\n\n");
        sudoku[linha][coluna] = respostaResult;
    }
    else {
        if (respostaResult != 0) {
            printf("Realizado uma analise avancada\n");
            printf("A resposta para a linha eh: %d\n", respostaResult);
            printf("Adionado valor na matriz!!!\n\n");
            sudoku[linha][coluna] = respostaResult;
        }
    }

    printf("\n");

}

void VerificacaoAvancada(int linha, int coluna, int grupo, int resposta[9], int respostaAvancada[9][2]) {
    int verificaLinha[2], verificaColuna[2], validaRespostaLinha[9];
    int existe = 0, qtdResLinha = 0, respostaResult = 0;

    VerifLinColGrpTest(verificaLinha, verificaColuna, linha, coluna);

    for (int i = 0; i < 9; i++) {
        existe = 0;
        for (int j = 0; j < 9; j++) {
            if (resposta[i] == sudoku[verificaLinha[0]][j]) {
                existe++;
                GerenciaRespAvancada(verificaLinha[0], j, respostaAvancada, existe);
            }

            if (resposta[i] == sudoku[verificaLinha[1]][j]) {
                existe++;
                GerenciaRespAvancada(verificaLinha[1], j, respostaAvancada, existe);
            }

            if (resposta[i] == sudoku[j][verificaColuna[0]]) {
                existe++;
                GerenciaRespAvancada(j, verificaColuna[0], respostaAvancada, existe);
            }

            if (resposta[i] == sudoku[j][verificaColuna[1]]) {
                existe++;
                GerenciaRespAvancada(j, verificaColuna[1], respostaAvancada, existe);
            }
        }
    }

    GeraInfoContemVizinho(verificaLinha, verificaColuna, linha, coluna, respostaAvancada);



}

int VerificaExistencia(int linha, int coluna) {
    int retorno = 0;

    if (sudoku[linha][coluna] != 0) {
        retorno++;
    }

    return retorno;
}

void ProcuraValores(int seleciona) {
    int existe = 0, num[9];

    if (seleciona == 1) {

        SelecionaLinha(existe, num);
    }

    if (seleciona == 2) {
        SelecionaColuna(existe, num);
    }

    if (seleciona == 3) {
        SelecionaGrupo(existe, num);
    }


}

void GeraNum(int* num) {
    int i = 0;

    for (int i = 0; i < 9; i++) {
        num[i] = i + 1;
    }
}

void VerifLinColGrpTest(int verificaLinha[2], int verificaColuna[2], int linha, int coluna) {
    int linhaItera, colunaItera;

    if (linha == 0 || linha == 3 || linha == 6) {
        linhaItera = linha + 1;
        verificaLinha[0] = linhaItera;
        linhaItera++;
        verificaLinha[1] = linhaItera;
    }
    if (linha == 1 || linha == 4 || linha == 7) {
        linhaItera = linha - 1;
        verificaLinha[0] = linhaItera;
        linhaItera = linha + 1;
        verificaLinha[1] = linhaItera;
    }
    if (linha == 2 || linha == 5 || linha == 8) {
        linhaItera = linha - 1;
        verificaLinha[1] = linhaItera;
        linhaItera = linha - 2;
        verificaLinha[0] = linhaItera;
    }
    if (coluna == 0 || coluna == 3 || coluna == 6) {
        colunaItera = coluna + 1;
        verificaColuna[0] = colunaItera;
        colunaItera++;
        verificaColuna[1] = colunaItera;
    }
    if (coluna == 1 || coluna == 4 || coluna == 7) {
        colunaItera = coluna - 1;
        verificaColuna[0] = colunaItera;
        colunaItera = coluna + 1;
        verificaColuna[1] = colunaItera;
    }
    if (coluna == 2 || coluna == 5 || coluna == 8) {
        colunaItera = coluna - 1;
        verificaColuna[1] = colunaItera;
        colunaItera--;
        verificaColuna[0] = colunaItera;
    }
}

void CriaGrupo(int* grupoLin, int* grupoCol, int grupo) {

    if (grupo == 1 || grupo == 2 || grupo == 3) {
        grupoLin[0] = 0, grupoLin[1] = 1, grupoLin[2] = 2;
    }

    if (grupo == 4 || grupo == 5 || grupo == 6) {
        grupoLin[0] = 3, grupoLin[1] = 4, grupoLin[2] = 5;
    }

    if (grupo == 7 || grupo == 8 || grupo == 9) {
        grupoLin[0] = 6, grupoLin[1] = 7, grupoLin[2] = 8;
    }

    if (grupo == 1 || grupo == 4 || grupo == 7) {
        grupoCol[0] = 0, grupoCol[1] = 1, grupoCol[2] = 2;
    }

    if (grupo == 2 || grupo == 5 || grupo == 8) {
        grupoCol[0] = 3, grupoCol[1] = 4, grupoCol[2] = 5;
    }

    if (grupo == 3 || grupo == 6 || grupo == 9) {
        grupoCol[0] = 6, grupoCol[1] = 7, grupoCol[2] = 8;
    }
}

void CriarSudoku() {
    int i=0, j=0;
    //linha 1
    sudoku[0][0] = 9;
    sudoku[0][1] = 4;
    sudoku[0][2] = 0;
    sudoku[0][3] = 1;
    sudoku[0][4] = 0;
    sudoku[0][5] = 2;
    sudoku[0][6] = 0;
    sudoku[0][7] = 5;
    sudoku[0][8] = 8;
    //linha 2
    sudoku[1][0] = 6;
    sudoku[1][1] = 0;
    sudoku[1][2] = 0;
    sudoku[1][3] = 0;
    sudoku[1][4] = 5;
    sudoku[1][5] = 0;
    sudoku[1][6] = 0;
    sudoku[1][7] = 0;
    sudoku[1][8] = 4;
    //linha 3
    sudoku[2][0] = 0;
    sudoku[2][1] = 0;
    sudoku[2][2] = 2;
    sudoku[2][3] = 4;
    sudoku[2][4] = 0;
    sudoku[2][5] = 3;
    sudoku[2][6] = 1;
    sudoku[2][7] = 0;
    sudoku[2][8] = 0;
    //linha 4
    sudoku[3][0] = 0;
    sudoku[3][1] = 2;
    sudoku[3][2] = 0;
    sudoku[3][3] = 0;
    sudoku[3][4] = 0;
    sudoku[3][5] = 0;
    sudoku[3][6] = 0;
    sudoku[3][7] = 6;
    sudoku[3][8] = 0;
    //linha 5
    sudoku[4][0] = 5;
    sudoku[4][1] = 0;
    sudoku[4][2] = 8;
    sudoku[4][3] = 0;
    sudoku[4][4] = 2;
    sudoku[4][5] = 0;
    sudoku[4][6] = 4;
    sudoku[4][7] = 0;
    sudoku[4][8] = 1;
    //linha 6 
    sudoku[5][0] = 0;
    sudoku[5][1] = 6;
    sudoku[5][2] = 0;
    sudoku[5][3] = 0;
    sudoku[5][4] = 0;
    sudoku[5][5] = 0;
    sudoku[5][6] = 0;
    sudoku[5][7] = 8;
    sudoku[5][8] = 0;
    //linha 7
    sudoku[6][0] = 0;
    sudoku[6][1] = 0;
    sudoku[6][2] = 1;
    sudoku[6][3] = 6;
    sudoku[6][4] = 0;
    sudoku[6][5] = 8;
    sudoku[6][6] = 7;
    sudoku[6][7] = 0;
    sudoku[6][8] = 0;
    //linha 8
    sudoku[7][0] = 7;
    sudoku[7][1] = 0;
    sudoku[7][2] = 0;
    sudoku[7][3] = 0;
    sudoku[7][4] = 4;
    sudoku[7][5] = 0;
    sudoku[7][6] = 0;
    sudoku[7][7] = 0;
    sudoku[7][8] = 3;
    //linha 9 
    sudoku[8][0] = 4;
    sudoku[8][1] = 3;
    sudoku[8][2] = 0;
    sudoku[8][3] = 5;
    sudoku[8][4] = 0;
    sudoku[8][5] = 9;
    sudoku[8][6] = 0;
    sudoku[8][7] = 1;
    sudoku[8][8] = 2;
}