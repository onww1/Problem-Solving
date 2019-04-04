#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 10000;
pll p[2], first;

ll CCW(pll p[]) { return p[0].X * p[1].Y - p[1].X * p[0].Y; }

int main(int argc, char *argv[]) {
	ll ans = 0;
	int N, i;
	scanf("%d", &N);
	scanf("%lld %lld", &first.X, &first.Y);

	p[1] = first;
	for (int i = 1; i < N; ++i) {
		p[0] = p[1];
		scanf("%lld %lld", &p[1].X, &p[1].Y);
		ans += CCW(p);
	}
	p[0] = p[1];
	p[1] = first;
	ans += CCW(p);
	return !printf("%lld.%lld\n", abs(ans) / 2LL, abs(ans) % 2 ? 5LL : 0LL);
}