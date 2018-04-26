#include <stdio.h>

int main(void){
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0) break;
		a *= a;
		b *= b;
		c *= c;
		if(a+b == c || b+c == a || c+a == b) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}