#include <stdio.h>

void InverteNumArray(int num[]){
	int i=0, j=19;
	
	for(i = 0; i < 20; i++){	
		printf("%d\n", num[j]);	
		j--;	
	}	
}

void PrintaValorArray(int num[]){
	int i = 0;
	
	for(i = 0; i < 20; i++){
		
		if((num[i]%2) == 0){
			printf("%d\n", num[i]);
		}
			
	}
	
}

void InsereValorArray(int num[]){
	int numVetor=0, i=0;
	
	for(i = 0; i < 20; i++){
		numVetor++;		
		num[i] = numVetor;			
	}
	
}	

int main(){
	int num[20], i = 0;
	
	InsereValorArray(num);
	InverteNumArray(num);
	//PrintaValorArray(num);
		
}		
