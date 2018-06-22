#include <stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = (90-a)/5;
	if(a%5 == 0) printf("%d\n", b+c);
	else printf("%d\n", b+c+1);
	return 0;
}