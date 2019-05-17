#include <cstdio>
typedef long long ll;

ll A, B, C;

ll _pow(ll base, ll exp, ll mod) {
	ll ret = 1LL;
	while (exp) {
		if (exp % 2LL) {
			ret *= base;
			ret %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2;
	}
	return ret;
}

int main() {
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n", _pow(A, B, C));
	return 0;
}