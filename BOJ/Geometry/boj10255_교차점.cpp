#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct line {
	pll p1, p2;
};

ll CCW(pll p1, pll p2, pll p3) {
	ll ret = 0LL;
	ret += p1.X * (p2.Y - p3.Y);
	ret += p2.X * (p3.Y - p1.Y);
	ret += p3.X * (p1.Y - p2.Y);
	return ret;
}

line lines[4];
void _swap(ll &a, ll &b) { ll tmp = a; a = b; b = tmp; }

int _count(line &a, line &b) {
	if (min(a.p1.X, a.p2.X) > max(b.p1.X, b.p2.X) || max(a.p1.X, a.p2.X) < min(b.p1.X, b.p2.X)) return 0;
	if (min(a.p1.Y, a.p2.Y) > max(b.p1.Y, b.p2.Y) || max(a.p1.Y, a.p2.Y) < min(b.p1.Y, b.p2.Y)) return 0;

	ll ccw1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
	ll ccw2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);

	if (ccw1 < 0 && ccw2 < 0) return 1;
	if (ccw1 < 0 && ccw2 == 0) return 1;
	if (ccw1 == 0 && ccw2 < 0) {
		if (CCW(a.p1, a.p2, b.p1) == 0) return 1;
		return 0;
	}
	if (ccw1 == 0 && ccw2 == 0) {
		if ((b.p2.X - b.p1.X) * (a.p2.Y - a.p1.Y) == (a.p2.X - a.p1.X) * (b.p2.Y - b.p1.Y)) {
			if (a.p1.Y == a.p2.Y && (min(a.p1.X, a.p2.X) == max(b.p1.X, b.p2.X) || max(a.p1.X, a.p2.X) == min(b.p1.X, b.p2.X))) {
				if (a.p1.X == b.p1.X || a.p2.X == b.p1.X) return 1;
				else return 0;
			}
			if (a.p1.X == a.p2.X && (min(a.p1.Y, a.p2.Y) == max(b.p1.Y, b.p2.Y) || max(a.p1.Y, a.p2.Y) == min(b.p1.Y, b.p2.Y))) {
				if (a.p1.Y == b.p1.Y || a.p2.Y == b.p1.Y) return 1;
				else return 0;
			}
			return 4;
		}
		else if (CCW(a.p1, a.p2, b.p1) == 0) return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int T;
	for (scanf("%d", &T); T; T--) {
		ll x, y, xx, yy;
		scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
		lines[0] = { { x, y },{ x, yy } };
		lines[1] = { { x, yy },{ xx, yy } };
		lines[2] = { { xx, yy },{ xx, y } };
		lines[3] = { { xx, y },{ x, y } };

		scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
		if (x > xx) {
			_swap(x, xx);
			_swap(y, yy);
		}
		line L = { { x, y },{ xx, yy } };

		int cnt = 0;
		for (int i = 0; i < 4; ++i)
			cnt += _count(L, lines[i]);

		printf("%d\n", cnt > 2 ? 4 : cnt);
	}
	return 0;
}