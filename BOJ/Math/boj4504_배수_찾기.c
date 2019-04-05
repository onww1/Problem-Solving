#include <stdio.h>

int main(void){
	int n, in;
	scanf("%d", &n);
	while(1){
		scanf("%d", &in);
		if(in == 0) break;
		if(in%n == 0) printf("%d is a multiple of %d.\n", in, n);
		else printf("%d is NOT a multiple of %d.\n", in, n);
	}
	return 0;
}