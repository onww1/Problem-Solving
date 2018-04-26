#include <stdio.h>

int main(void){
	int R, C, A, B;
	scanf("%d %d %d %d", &R, &C, &A, &B);

	for(int i=0; i<R*A; i++){
		for(int j=0; j<C*B; j++){
			if(((i/A)%2 == 0 && (j/B)%2 == 0) || ((i/A)%2 == 1 && (j/B)%2 == 1)) printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}