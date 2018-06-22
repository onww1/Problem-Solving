#include <cstdio>

int dp[11] = {0, };

int main(void){
	int t;
	scanf("%d", &t);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=4; i<=10; i++){
		dp[i] = 
	}

	int n;
	while(t--){
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}

