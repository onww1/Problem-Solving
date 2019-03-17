#include <cstdio>
int N, K, A[21];
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d,", A + i);
	while (K--) {
		for (int i = 0; i < N - 1; ++i) 
			A[i] = A[i + 1] - A[i];
		N--;
	}
	for (int i = 0; i < N; ++i) {
		if (i) printf(",%d", A[i]);
		else printf("%d", A[i]);
	}
	puts("");
	return 0;
}