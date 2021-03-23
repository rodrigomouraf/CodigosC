#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void) {
int a,b,c;
double x1,x2;
scanf("%d %d %d",&a,&b,&c);

	if( a == 0 ) {
        exit(-1);
    }
    
    double delta = b*b - 4 *a*c;
    double sqrtDelta = sqrt(delta);
    int i = -1;
    
    if(sqrtDelta < 0){
    	x1 = (-b + i*sqrt(-delta) )/2*a;
		x2 = (-b - i*sqrt(-delta) )/2*a;	
	}
	
	if(sqrt > 0){
		x1 = (-b + sqrtDelta) / 2*a;
		x2 = (-b - sqrtDelta) / 2*a;
	}
    
	
	
 	printf("%.2f\n%.2f\n",x1,x2);
}
