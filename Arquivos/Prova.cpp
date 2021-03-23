#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char arquivo1[30], arquivo2[30];
	char buffer[4096];
	char buffer2[4096];
	char teste[3];
	int i = 0;
	FILE* fp;
	FILE* pf;
	FILE* fi;
	
	printf("Digite o nome do arquivo:\n");
	scanf("%s", &arquivo1);
	
	printf("Digite o nome do segundo arquivo:\n");
	scanf("%s", &arquivo2);
	
	if ((fp = fopen(arquivo1, "rt")) == NULL) {
        printf("Arquivo 1 nao encontrado.\n");
        exit(-1);
    }
    
    if ((pf = fopen(arquivo2, "rt")) == NULL) {
        printf("Arquivo 2 nao encontrado.\n");
        exit(-1);
    }
	
	fi = fopen("TerceiroArquivo.txt", "r+w+");
	
	while ( !feof(fp) && !feof(pf) ) {
		i++;
		
		fgets(buffer,4096,fp);
		printf("%s", buffer);
		
		fgets(buffer2,4096,pf);
		printf("%s", buffer2);
		
		
		fputs(buffer, fi);
		fputs(buffer2, fi);
		
		if(!feof(fp)){
			strcat(teste, "pf");
		}
		
		if(!feof(fp)){
			strcat(teste, "fp");
		}
	
	}
	
	if(teste != ""){
		
		/*while( !feof(teste) ){
			
			memset(buffer,0, 4096);
			fgets(buffer,4096,teste);
			printf("%s", buffer);
		}*/
	}
	
	fclose(fp);
	fclose(fp);
	fclose(fi);
	
	return 0;
}
