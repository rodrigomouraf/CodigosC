#include <stdio.h>

int main(){
	int i = 0, numeroMaior=0, numeroAtual=0;
	
	do{
		scanf("%d", &numeroAtual);
		
		if(numeroAtual > numeroMaior)
			numeroMaior = numeroAtual;
		
		i++;
		
	} while(i != 9);
	
	printf("%d", numeroMaior);
}
