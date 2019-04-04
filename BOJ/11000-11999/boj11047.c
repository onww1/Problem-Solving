#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N, K, *value, *cnt;
	scanf("%d %d", &N, &K);
	value = (int*)malloc(sizeof(int) * N);
	cnt   = (int*)calloc(N, sizeof(int));
	for(int i=0; i<N; i++) scanf("%d", &value[i]);

	int i=N-1;
	while(K > 0){
		cnt[i] = K/value[i];
		K %= value[i];
		if(i == 0 && K != 0){
			
		}
		i--;
	}


	free(value);
	free(cnt);
	return 0;
}