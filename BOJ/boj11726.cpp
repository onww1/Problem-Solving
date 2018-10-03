#include <cstdio>
using namespace std;

int main(){
	int n;
	int dp[1001] = {0, 1, 2, };

	scanf("%d", &n);
	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2])%10007;
	}

	printf("%d\n", dp[n]);
	return 0;
}