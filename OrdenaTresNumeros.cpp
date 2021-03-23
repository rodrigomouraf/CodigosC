#include <stdio.h>

int main(){
	int ordena[3],a=0,b=0,c=0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	if(a > b && a > c){
		ordena[0] = a;
		if(b > c){
			ordena[1] = b;
			ordena[2] = c;	
		}
		else{
			ordena[1] = c;
			ordena[2] = b;
		}
	}
	
	if(a > b && a < c){
		ordena[0] = c;
		ordena[1] = a;
		ordena[2] = b;
	}
	
	if(a < b && a > c){
		ordena[0] = b;
		ordena[1] = a;
		ordena[2] = c;
	}
	
	
	if(a < b && a < c){
		ordena[2] = a;
		if(b > c){
			ordena[0] = b;
			ordena[1] = c;
		}
		else{
			ordena[1] = b;
			ordena[0] = c;
		}
	}
	
	for(int i = 2; i>-1; i--){
		printf("%d\n", ordena[i]);
	}
	
	return 0;
}
