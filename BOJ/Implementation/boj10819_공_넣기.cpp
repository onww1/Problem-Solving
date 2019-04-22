#include <stdio.h>
int N, M, B[101];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0, a, b, c; i < M; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		for (int j = a; j <= b; ++j) B[j] = c;
	}
	for (int i = 1; i <= N; ++i) printf("%d ", B[i]); puts("");
	return 0;
}