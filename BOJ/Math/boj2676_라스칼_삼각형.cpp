#include <cstdio>
int main() {
	int T, N, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		printf("%lld\n", 1 + 1LL * (N - M) * M);
	}
	return 0;
}
