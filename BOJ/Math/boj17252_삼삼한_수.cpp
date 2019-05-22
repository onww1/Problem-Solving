#include <cstdio>
int main() {
	long long N, C = 0;
	scanf("%lld", &N);
	while (N) {
		if (N % 3LL == 2) return !printf("NO\n");
		C += N % 3LL;
		N /= 3LL;
	}
	puts(C ? "YES" : "NO");
	return 0;
}