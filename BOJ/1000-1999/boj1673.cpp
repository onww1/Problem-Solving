#include <cstdio>
int main() {
	int N, K;
	while (~scanf("%d %d", &N, &K)) {
		int ans = 0, S = 0;
		do {
			N += S / K;
			S %= K;
			ans += N;
			S += N;
			N = 0;
		} while (S >= K);
		printf("%d\n", ans);
	}
	return 0;
}