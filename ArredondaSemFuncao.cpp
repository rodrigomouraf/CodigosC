#include <stdio.h>

int main(){
	float a = 0, resto = 0;
	int b;
	
	scanf("%f", &a);
	
	resto = a - (int)a;
		
	if(resto >= 0.5){
		b = (int)a + 1;
		printf("%d", b);
	}
	else{
		printf("%d", (int)a);
	}
}
