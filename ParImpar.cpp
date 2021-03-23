#include <stdio.h>

int main(){
	int num=0;
	
	do{
		scanf("%d", &num);
		
		if(num == 0)
			break;
	
	if((num%2) == 0){
			printf("%d par\n", num);
		}			
		else{
			printf("%d impar\n", num);
		}
	
	} while(num != 0);
	
	return 0;
}
