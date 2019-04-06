#include <cstdio>
int main() {
	int N, S = 0, A;
	scanf("%d", &N); N *= 2;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A);
		S += (A < 0 ? -A : A);
	}
	return !printf("%d\n", S);
}