#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, *left, *right, *none; 
	scanf("%d", &N);
	left  = (int*)malloc(sizeof(int)*(N+1));
	right = (int*)malloc(sizeof(int)*(N+1));
	none  = (int*)malloc(sizeof(int)*(N+1));
	left[0] = right[0] = 0; none[0] = 1;
	for(int i=1; i<=N; i++){
		left[i]  = (none[i-1] + right[i-1])%9901;
		right[i] = (none[i-1] + left[i-1])%9901;
		none[i] = (left[i-1] + right[i-1] + none[i-1])%9901;
	}
	printf("%d\n", (left[N]+right[N]+none[N])%9901);
	free(left);
	free(right);
	free(none);
	return 0;
}