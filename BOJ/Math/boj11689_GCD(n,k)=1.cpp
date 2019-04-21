#include <stdio.h>

long long N, ans;
int main(int argc, char *argv[]) {
	scanf("%lld", &N);
	ans = N;
	for (long long i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			ans = ans / i * (i - 1);
			while (N % i == 0) N /= i;
		}
	}
	if (N > 1) ans = ans / N * (N - 1);
	printf("%lld\n", ans);
	return 0;
}