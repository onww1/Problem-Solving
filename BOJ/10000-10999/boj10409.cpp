#include <cstdio>
int main() {
	int N, T, S = 0, A, C = 0;
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A);
		S += A;
		if (S <= T) C = i;
	}
	printf("%d\n", C);
	return 0;
}