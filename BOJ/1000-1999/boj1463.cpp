#include <cstdio>

int min(int a, int b, int c){
	return a>b?(b>c?c:b):(a>c?c:a);
}

int main(void){
	int n;
	int dp[1000001];
	scanf("%d", &n);
	dp[0] = dp[1] = 0;

	for(int idx=2; idx<=n; idx++){
		dp[idx] = min( idx%3==0?dp[idx/3]:1e9, idx%2==0?dp[idx/2]:1e9, dp[idx-1] ) + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}