#include <stdio.h>

int main(){
	int a=0, b=0, c=1, i=0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	for(int i = 0; i < b; i++){
		c = c*a;
	}
	
	printf("%d", c);
}
