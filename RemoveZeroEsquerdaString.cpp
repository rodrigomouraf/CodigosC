#include <stdio.h>

int main(){
	char string[80];
	int i=0, teste = 0;
	scanf("%s", &string);
	
	
	for (i = 0; i < sizeof(string); i++){
		
		if(string[i] != '0'){
			teste = 1;
		}
		
		if(teste == 1){
			if(string[i] == '\0'){
				break;
			}
			printf("%c", string[i]);
		}
		
	}
	
	return 0;
}


