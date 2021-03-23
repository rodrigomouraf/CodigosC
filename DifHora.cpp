#include <stdio.h>

int main(){
	int hora=0,minuto=0,segundo=0;
	int hora2=0,minuto2=0,segundo2=0;
	int resph, respm, resps;
	int aux=0;
	
	scanf("%d", &hora);
	scanf("%d", &minuto);
	scanf("%d", &segundo);
	scanf("%d", &hora2);
	scanf("%d", &minuto2);
	scanf("%d", &segundo2);
	
	if(hora == 0){
		hora = 60;
	}
	
	
	if(segundo == 0){		
		segundo = 60;
		
		if(minuto == 0 && segundo == 60){
			minuto = 59;
			if(hora != 0){
				hora--;
			}else{
				hora = 23;
			}
		
		}else{
			
			minuto--;
			if(hora != 0){
				hora--;
			}else{
				hora = 23;
			}
			
		}
	}
	
	if(segundo < segundo2){
		
		aux = segundo2 - segundo;
		resps = 60 - aux;
		minuto--;
		aux = 0;
	}else{
		resps = segundo - segundo2;
	}
	
	if(minuto < minuto2){
		aux = minuto2 - minuto;
		respm = 60 - aux;
		hora--;
		aux=0;
	}else{
		respm = minuto - minuto2;
	}
	
	if(hora < hora2){
		aux = hora2 - hora;
		resph = 60 - aux;
		aux=0;
	}else{
		resph = hora - hora2;
	}
	
	printf("%d:%d:%d\n", resph, respm, resps);
	
	
}
