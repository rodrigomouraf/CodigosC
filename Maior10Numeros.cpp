#include <stdio.h>

//Faça um programa que leia 10 números inteiros e apresente o maior (não utilize vetor/matriz).'

int main(){
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
	
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);
	scanf("%d", &num4);
	scanf("%d", &num5);
	scanf("%d", &num6);
	scanf("%d", &num7);
	scanf("%d", &num8);
	scanf("%d", &num9);
	scanf("%d", &num10);
	
	if(num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6 && num1 > num7 && num1 > num8 && num1 > num9 && num1 > num10){
		printf("%d", num1);
	}
	
	if(num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 && num2 > num7 && num2 > num8 && num2 > num9 && num2 > num10){
		printf("%d", num2);
	}
	
	if(num3 > num2 && num3 > num1 && num3 > num4 && num3 > num5 && num3 > num6 && num3 > num7 && num3 > num8 && num3 > num9 && num3 > num10){
		printf("%d", num3);
	}
	
	if(num4 > num2 && num4 > num3 && num4 > num1 && num4 > num5 && num4 > num6 && num4 > num7 && num4 > num8 && num4 > num9 && num4 > num10){
		printf("%d", num4);
	}
	
	if(num5 > num2 && num5 > num3 && num5 > num4 && num5 > num1 && num5 > num6 && num5 > num7 && num5 > num8 && num5 > num9 && num5 > num10){
		printf("%d", num5);
	}
	
	if(num6 > num2 && num6 > num3 && num6 > num4 && num6 > num5 && num6 > num1 && num6 > num7 && num6 > num8 && num6 > num9 && num6 > num10){
		printf("%d", num6);
	}
	
	if(num7 > num2 && num7 > num3 && num7 > num4 && num7 > num5 && num7 > num6 && num7 > num7 && num1 > num8 && num7 > num9 && num7 > num10){
		printf("%d", num7);
	}
	
	if(num8 > num2 && num8 > num3 && num8 > num4 && num8 > num5 && num8 > num6 && num8 > num7 && num8 > num1 && num8 > num9 && num8 > num10){
		printf("%d", num8);
	}
	
	if(num9 > num2 && num9 > num3 && num9 > num4 && num9 > num5 && num9 > num6 && num9 > num7 && num9 > num8 && num9 > num1 && num9 > num10){
		printf("%d", num9);
	}
	
	if(num10 > num2 && num10 > num3 && num10 > num4 && num10 > num5 && num10 > num6 && num10 > num7 && num10 > num8 && num10 > num9 && num10 > num1){
		printf("%d", num10);
	}
	
	return 0;
	
}
