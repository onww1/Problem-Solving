#include <stdio.h>

int main(void){
	int N, cnt[10001] = {0}, in;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &in);
		cnt[in]++;
	}
	for(int i=2; i<=10000; i++) cnt[i] += cnt[i-1];
	int i=1, j=1;
	while(i<=N){
		if(i<=cnt[j]){
			printf("%d\n", j);
			i++;
		} else j++;
	}
	return 0;
}