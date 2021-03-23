#include <stdio.h>

int MaiorNumero(int num1, int num2, int num3){
	int resultado = 0;
	
	if(num1 > num2){
		if(num1 > num3){
			resultado = num1;
		}
	}
	
	if(num2 > num1){
		if(num2 > num3){
			resultado = num2;
		}
	}
	
	if(num3 > num1){
		if(num3 > num2){
			resultado = num3;
		}
	}
	
	return resultado;
	
}

int main(){
	int num1=0, num2=0, num3=0, resultado=0;
	
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);
	
	resultado = MaiorNumero(num1, num2, num3);
	
	printf("%d", resultado);
	
	return 0;
}
