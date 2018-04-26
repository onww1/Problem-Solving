#include <stdio.h>

int main(void){
	int t, n, divider;
	long cnt;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cnt = 0;
		divider = 1;

		for(int i=0; i<=10; i++){
			divider *= 5;
			cnt += (long)n / (long)divider;
		}

		printf("%ld\n", cnt);
	}
	return 0;
}