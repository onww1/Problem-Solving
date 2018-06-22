#include <stdio.h>

int main(void){
	char prime[246913]={1, 1};
	int n;
	for(int i=2; i<=123456; i++){
		if(prime[i] == 0)
			for(int j=i*2; j<246913; j+=i) prime[j] = 1;
	}
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		int cnt = 0;
		for(int i=n+1; i<=2*n; i++){
			if(prime[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}