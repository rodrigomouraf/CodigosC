#include <stdio.h>
#include <string.h>


/*void func(char vet[], int num) {
	int aux  = 0, teste=0;
	for (aux = 32; aux >= 0; aux--)
   	{
      if (num % 2 == 0)
         vet[aux] = '0';
      else
     	 vet[aux] = '1';
      num = num / 2;
  	}
  	
  	for (aux = 0; aux < 8; aux++){
		
		if(bin[aux] != 0){
			teste = 1;
		}
		
		if(teste == 1){
			printf("%d", bin[aux]);
		}
		
	}
}

int main(void) {
	int num;
	char str[33];
	scanf("%d",&num);
	func(str,num);
	printf("%s\n",str);
}*/



void func(char vet[], int num) {
	int aux  = 0;
	for (aux = 32; aux >= 0; aux--)
   	{
      if (num % 2 == 0)
         vet[aux] = '0';
      else
     	 vet[aux] = '1';
      num = num / 2;
  	}
}

int main(void) {
	int num;
	char str[33];
	scanf("%d",&num);
	func(str,num);
	printf("%s\n",str);
}


