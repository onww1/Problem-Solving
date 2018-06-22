#include <stdio.h>

int main(void){
	int N, okay[1001] = {0, 1, 2}, absence[1001] = {0, 1, 2}, onceLate[1001] = {0, 1, 4};
	scanf("%d", &N);

	for(int i=3; i<=N; i++){
		okay[i] = 
	}
	printf("noLate\toncLate\n");
	for(int i=0; i<=N; i++) printf("%d\t%d\n", noLate[i], onceLate[i]);
	printf("%d\n", (noLate[N] + onceLate[N])%1000000);
	return 0;
}