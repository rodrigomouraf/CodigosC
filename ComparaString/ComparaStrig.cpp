#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int CalculaIteracoes(char str1[], char str2[]){
	int size1=0, size2=0, i=0, j=0;
	
	/*for(i = 0; i < sizeof(str1); i++){
		
		if(str1[i] == 0)
			break;
		else			
			size1++;
	}
	
	for(j = 0; j < sizeof(str1); j++){
		
		if(str2[j] == 0)
			break;
		else			
			size2++;
	}	
	
	if(size1 > size2 || size1 == size2)
		return size1;*/
	
		
	size1 = strlen(str1);
	size2 = strlen(str2);	
	
	if(size1 > size2 || size1 == size2)
		return size1;
	
		
	return size2;
	
}
int ComparaString(char str1[], char str2[]) {
	
	int i = 0, compara1 = 0, compara2 = 0, compara = 0, n = 0;
	char *ptr1 = NULL, *ptr2 = NULL;
	
	n = CalculaIteracoes(str1, str2);
	
	ptr1 = str1;
	ptr2 = str2;
	
	for (i = 0; i < n; i++)
	{
		compara1 += str1[i];
		compara2 += str2[i];
	}

	if (compara1 < compara2)
		compara = -1;

	if (compara1 > compara2)
		compara = 1;
		
	if(compara1 == compara2)
		compara = 0;

	return compara;
}

int main()
{
	char str1[50], str2[50];
	int compara = 0, teste, ch=0, ch2, ch3;

	printf("Informe a primeira palavra:\n");
	gets(str1);
	printf("Informe a segunda palavra:\n");
	gets(str2);
	
	ch = getchar();
	ch2 = getchar();
	ch3 = getchar();
	teste = atoi(str1);
	teste = atoi(str2);  


	compara = ComparaString(str1, str2);

	printf("%d", compara);

	return 0;
}
