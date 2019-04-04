#include <cstdio>
char A[110], B[110];
int T, N, C, i;
int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %s %s", &N, A, B);
		for (i = C = 0; i < N; ++i) if (A[i] - B[i]) C++;
		printf("Case %d: %d\n", tc, C);
	}
	return 0;
}