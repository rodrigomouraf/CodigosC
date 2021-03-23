#include <stdio.h>


/*int main( void ) {
int x=5, y=-10;
printf("x=%d y=%d\n",x,y);
x= x + y;
y= x - y;
x= x - y;
printf("x=%d y=%d\n",x,y);
}*/

int main( void ) {
	int x=5, y=-10;
	printf("x=%d y=%d\n",x,y);
	
	x ^= y;
	y ^= x;
	x ^= y;
	
	printf("x=%d y=%d\n",x,y);
}
