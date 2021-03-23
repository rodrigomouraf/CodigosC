#include <stdio.h>
#include <math.h>

int main(){
	float numero,inteira,fracao;
	
    scanf("%f",&numero);
    printf("%d\n",(int)numero);
    printf("%f", numero - ((int)numero));
    
	return 0;
}
