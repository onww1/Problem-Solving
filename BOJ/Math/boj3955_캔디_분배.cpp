#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b) { return b ? _gcd(b, a % b) : a; }

ll uclid(ll r1, ll r2) {
	ll t, r, s, q, p = r1;
	ll s1 = 1, s2 = 0;
	ll t1 = 0, t2 = 1;

	while (r2) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2, r2 = r;

		s = s1 - q * s2;
		s1 = s2, s2 = s;

		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}

	if (t1 < 0) t1 += p;
	return t1;
}

int main(int argc, char *argv[]) {
	ll t, k, c;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &k, &c);
		if (c == 1) (k == 1e9 ? puts("IMPOSSIBLE") : printf("%lld\n", k + 1));
		else if (k == 1) puts("1");
		else {
			ll GCD = _gcd(k, c);
			if (GCD > 1) puts("IMPOSSIBLE");
			else {
				ll ans = uclid(k, c);
				if (ans > 1e9) puts("IMPOSSIBLE");
				else printf("%lld\n", ans);
			}
		}
	}
	return 0;
}