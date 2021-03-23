#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int mdc(int num1, int num2)
{
    if (num1 % num2 == 0)
        return num2;
    else
        return mdc(num2, num1 % num2);
}

int main(){
	int a = 0, b = 0, c = 0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	if(b > a){
		c = a;
		a = b;
		b = c;
		c = 0;
	}
		
	c = mdc(a, b);
	
	printf("%d", c);
}


