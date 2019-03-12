#include <cstdio>
int N, K;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i < K; ++i) {
		printf("%d\n", i);
		N -= i;
	}
	return !printf("%d\n", N);
}