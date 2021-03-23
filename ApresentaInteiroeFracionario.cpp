#include <stdio.h>

int main(){
	float a = 0, resto = 0;
	
	scanf("%f", &a);
	
	resto = a - (int)a;
		

	printf("%d\n", (int)a);
	printf("%0.3f", resto);

}
