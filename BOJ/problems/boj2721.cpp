#include <cstdio>
long long DP[301];
int main() {
	for (long long i = 1; i <= 300; ++i) 
		DP[i] = DP[i - 1] + i * (i + 1) * (i + 2) / 2LL;
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", DP[N]);
	}	
	return 0;
}