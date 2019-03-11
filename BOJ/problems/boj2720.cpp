#include <cstdio>
int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d ", N / 25);
		N %= 25;
		printf("%d ", N / 10);
		N %= 10;
		printf("%d ", N / 5);
		N %= 5;
		printf("%d\n", N);
	}
	return 0;
}