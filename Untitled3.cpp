#include <stdio.h>

int main(){
	
	int a=0, b=0, c=0, ordena[3];
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	if(a>b && a>c){
		ordena[0] = a;
		
		if(b>c){
			ordena[1] = b;
			ordena[2] = c;
		}else{
			ordena[1] = c;
			ordena[2] = b;
		}
	}
	
	if(b>c && b>a){
		ordena[0] = b;
		
		if(a>c){
			ordena[1] = a;
			ordena[2] = c;
		}else{
			ordena[1] = c;
			ordena[2] = a;
		}
	}
	
	if(c>a && c>b){
		ordena[0] = c;
		
		if(a>b){
			ordena[1] = a;
			ordena[2] = b;
		}else{
			ordena[1] = b;
			ordena[2] = a;
		}
	}
	
	for(int i = 2; i > -1; i--){
		printf("%d \n", ordena[i]);
	}
		
	return 0;
}



