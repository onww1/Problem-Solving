#include <cstdio>
int N, S;
int main() {
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		while (N > 9) {
			S = 0;
			while (N) {
				S += N % 10;
				N /= 10;
			}
			N = S;
		}
		printf("%d\n", N);
	}
	return 0;
}