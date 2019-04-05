#include <cstdio>
typedef long long ll;

int main(int argc, char *argv[]) {
	ll x, y, z;
	scanf("%lld %lld", &x, &y);
	z = y * 100LL / x;

	if (z >= 99) return !printf("-1\n");

	ll l = 0, r = x, m, v, ans = -1;
	while (l <= r) {
		m = (l + r) / 2LL;
		v = (y + m) * 100LL / (x + m);
		if (v > z) r = m - 1, ans = m;
		else l = m + 1;
	}
	return !printf("%lld\n", ans);
}