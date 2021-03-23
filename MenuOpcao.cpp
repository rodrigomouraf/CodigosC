#include <stdio.h>

/*int main()
{  
    int opcao = 0;

    do {

        printf("1 - Opcao 1\n");
        printf("2 - Opcao 2\n");
        printf("3 - Opcao 3\n");
        printf("4 - Opcao 4\n");
        
        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 1:
                printf("Opcao 1\n");
                break;
            case 2:
                printf("Opcao 2\n");
                break;
            case 3:
                printf("Opcao 3\n");
                break;
            case 4:
                printf("Opcao 4\n");
                break;
        }

    } while (opcao != 4);
} */

int main(){
	
	int a=0, b=0, c=0, ordena[3];
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	if(a>b && a>c){
		ordena[0] = a;
		
		if(b>c){
			ordena[1] = b;
			ordena[2] = c;
		}else{
			ordena[1] = c;
			ordena[2] = b;
		}
	}
	
	if(b>c && b>a){
		ordena[0] = b;
		
		if(a>c){
			ordena[1] = a;
			ordena[2] = c;
		}else{
			ordena[1] = c;
			ordena[2] = a;
		}
	}
	
	if(c>a && c>b){
		ordena[0] = c;
		
		if(a>b){
			ordena[1] = a;
			ordena[2] = b;
		}else{
			ordena[1] = b;
			ordena[2] = a;
		}
	}
	
	for(int i = 0; i < 3; i++){
		printf("%d", ordena[i]);
	}

}



