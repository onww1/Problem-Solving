#include <stdio.h>

int main(void){
	int t, n, min, i;
	scanf("%d", &t);
	char prime[10001] = {1, 1};
	for(i=2; i<=10000; i++){
		if(prime[i] == 0)
			for(int j=2*i; j<=10000; j+=i) prime[j] = 1;
	}
	while(t--){
		scanf("%d", &n);
		for(i=2; i<n; i++){
			if(prime[i] == 0 && prime[n-i] == 0){
				if(i > n-i) break;
				min = i;
			}
		}
		printf("%d %d\n", min, n-min);
	}
	return 0;
}