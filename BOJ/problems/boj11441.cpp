#include <cstdio>
int N, M, L, R, A[100001]; 
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", A + i);
		A[i] += A[i - 1];
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &L, &R);
		printf("%d\n", A[R] - A[L - 1]);
	}
	return 0;
}