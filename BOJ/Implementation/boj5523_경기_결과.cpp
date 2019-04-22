#include <stdio.h>
int N, A, B;
int main() {
	scanf("%d", &N);
	for (int i = 0, a, b; i < N; ++i) {
		scanf("%d %d", &a, &b);
		if (a == b) continue;
		(a > b ? A : B)++;
	}
	printf("%d %d\n", A, B);
	return 0;
}