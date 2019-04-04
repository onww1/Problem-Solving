#include <cstdio>
int A[101], L, R, N, M;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) A[i] = i;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &L, &R);
		for (int i = 0; L + i < R - i; ++i) {
			int tmp = A[L + i];
			A[L + i] = A[R - i];
			A[R - i]= tmp;
		}
	}
	for (int i = 1; i <= N; ++i) printf("%d ", A[i]);
	puts("");
	return 0;
}