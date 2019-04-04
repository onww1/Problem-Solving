#include <cstdio>
int main() {
	int T, N, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		int cnt = 0;
		for (int a = 1; a < N - 1; ++a) {
			for (int b = a + 1; b < N; ++b) {
				if ((a * a + b * b + M) % (a * b) == 0) ++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}