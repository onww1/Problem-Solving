#include <stdio.h>

int main(void){
	int n;
	int t[16], p[16];
	int dp[16] = {0};

	t[0] = p[0] = dp[0] = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &t[i], &p[i]);
		dp[i] = 0;
	}

	for(int i=1; i<=n; i++){
		if( i + t[i] - 1 <= n && dp[i-1] + p[i] > dp[i + t[i] - 1] )
			dp[i + t[i] - 1] = dp[i-1] + p[i];
		if( dp[i] < dp[i-1] ) 
			dp[i] = dp[i-1];
	}

	printf("%d\n", dp[n]);
	return 0;
}