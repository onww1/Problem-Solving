#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;

const int MAX = 30;
const ll MOD = 1000000007LL;
ll fac[MAX + 1] = { 1 }, inv[MAX + 1];

ll _pow(ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp % 2) ret = ret * base % MOD;
		base = base * base % MOD;
		exp /= 2;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int n, k, t;
	for (ll i = 1; i <= MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
	inv[MAX] = _pow(fac[MAX], MOD - 2);
	for (ll i = MAX; i > 0; --i) inv[i - 1] = inv[i] * i % MOD;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		printf("%lld\n", fac[n] * inv[k] % MOD * inv[n - k] % MOD);
	}
	return 0;
}