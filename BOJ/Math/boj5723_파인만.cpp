#include <stdio.h>
int N;
int main() {
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		printf("%d\n", N * (N + 1) * (2 * N + 1) / 6);
	}
	return 0;
}