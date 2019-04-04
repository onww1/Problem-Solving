#include <cstdio>
int T, N, D, V, F, C;
int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d %d", &N, &D);
		int cnt = 0;
		while (N--) {
			scanf("%d %d %d", &V, &F, &C);
			if (V * F / C >= D) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}