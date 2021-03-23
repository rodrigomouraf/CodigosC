#include <stdio.h>
#include <stdlib.h>


int main(){
	int a, num, bin[8], aux, i=0;
	int teste = 0;
	
	scanf("%d", &num);
	
	a = num;
	
	for (aux = 7; aux >= 0; aux--)
   {
      if (num % 2 == 0)
         bin[aux] = 0;
      else
         bin[aux] = 1;
      num = num / 2;
   }
	
	printf("%d\n", a);
	
	printf("%d\n", a);
	printf("%x\n", a);
	printf("%o\n", a);
	
	for (aux = 0; aux < 8; aux++){
		
		if(bin[aux] != 0){
			teste = 1;
		}
		
		if(teste == 1){
			printf("%d", bin[aux]);
		}
		
	}
		
	for (i = 0; i < sizeof(bin); i++){
		
		if(bin[i] != '0'){
			teste = 1;
		}
		
		if(teste == 1){
			if(bin[i] == '\0'){
				break;
			}
			printf("%c", bin[i]);
		}
		
	}	
       
	
	printf("\n");
	
	return 0;
}


