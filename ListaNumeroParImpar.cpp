#include <stdio.h>

//Fa�a um programa que leia uma lista de n�meros inteiros terminados por 0, 
//para cada n�mero lido o programa deve informar o n�mero e se o n�mero � par ou �mpar. 
//N�o utilize vetores/matrizes.'

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
