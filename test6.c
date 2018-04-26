#include <stdio.h>

int main(void){
	int a, b=6, c=5, d=4;
	a = (0<<b)|(0<<c)|(0<<d);
	printf("%d\n", a);
	return 0;
}