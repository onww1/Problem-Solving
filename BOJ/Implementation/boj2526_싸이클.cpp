#include <stdio.h>
int N, P, A[100];
int main() {
	scanf("%d %d", &N, &P);
	for (int i = 1, val = N % P; true; ++i) {
		if (A[val] > 0) return !printf("%d\n", i - A[val]);
		A[val] = i;
		val = (val * N) % P;
	}
	return 0;
}