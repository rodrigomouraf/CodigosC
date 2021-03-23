#include <stdio.h>

int main(){
	int numeroTeste = 0;
	
	do{
		scanf("%d", &numeroTeste);
		
		if(numeroTeste == 0){
			break;
		}
		
		if((numeroTeste%2) == 0){
			printf("%d par\n", numeroTeste);
		}			
		else{
			printf("%d impar\n", numeroTeste);
		}			
		
	} while (numeroTeste != 0);
	
	return 0;
}
