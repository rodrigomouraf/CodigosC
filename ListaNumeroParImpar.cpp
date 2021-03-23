#include <stdio.h>

//Faça um programa que leia uma lista de números inteiros terminados por 0, 
//para cada número lido o programa deve informar o número e se o número é par ou ímpar. 
//Não utilize vetores/matrizes.'

int main(){
	int numero[80], i=0, j=0;
	
	do{
		scanf("%d", &numero[j]);	
		j++;	

	} while(numero[(j - 1)] != 0);
	
	for(i = 0; i < (j-1); i++){
		
		if((numero[i]%2) == 0){
			printf("par\n");
		}			
		else{
			printf("impar\n");
		}
		
	}
	
	return 0;
	
}
