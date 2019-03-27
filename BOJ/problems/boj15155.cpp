#include <cstdio>
int N, K, A, S, C;
int main() {
	scanf("%d %d", &N, &K); S = K;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A);
		if (S + A > K) {
			S = A;
			C++;
		} else S += A;
	}
	printf("%d\n", C);
	return 0;
}