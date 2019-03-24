#include <cstdio>
typedef long long ll;

ll _pow(ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp % 2LL) ret *= base;
		base *= base;
		exp /= 2LL;
	}
	return ret;
}

int main() {
	int N, A;
	ll ans = 0;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &A);
		ans += _pow(A / 10, A % 10);
	}
	return !printf("%lld\n", ans);
}