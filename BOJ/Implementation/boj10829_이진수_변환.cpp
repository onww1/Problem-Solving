#include <stdio.h>
void solve(long long n) {
	if (!n) return;
	solve(n / 2LL);
	printf("%d", n % 2LL);
}
int main() {
	long long N;
	scanf("%lld", &N);
	solve(N);
	return 0;
}