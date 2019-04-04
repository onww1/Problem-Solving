#include <cstdio>
int main() {
	int T, D, N, S, P;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &D, &N, &S, &P);
		if (S * N == D + N * P) puts("does not matter");
		else if (S * N > D + N * P) puts("parallelize");
		else puts("do not parallelize");
	}
	return 0;
}