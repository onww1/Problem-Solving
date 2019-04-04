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

bool check(line &a, line &b) {
	if (a.p2.X < b.p1.X || a.p1.X > b.p2.X) return false;
	if (min(a.p1.Y, a.p2.Y) > max(b.p1.Y, b.p2.Y) || max(a.p1.Y, a.p2.Y) < min(b.p1.Y, b.p2.Y)) return false;
	ll ccw1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
	ll ccw2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);
	return ccw1 <= 0 && ccw2 <= 0;
}

int main(int argc, char *argv[]) {
	int T;
	for (scanf("%d", &T); T; T--) {
		ll x, y, xx, yy;

		scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
		if (x > xx) {
			_swap(x, xx);
			_swap(y, yy);
		}
		line L = { { x, y },{ xx, yy } };

		scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
		if (x > xx) _swap(x, xx);
		if (y < yy) _swap(y, yy);
		lines[0] = { {x, y}, {xx, y} };
		lines[1] = { {x, yy}, {xx, yy} };
		lines[2] = { {x, y}, {x, yy} };
		lines[3] = { {xx, yy}, {xx, y} };

		bool isMet = false;
		for (int i = 0; i < 4; ++i) 
			isMet |= check(lines[i], L);

		if (x <= L.p1.X && L.p2.X <= xx &&
			yy <= min(L.p1.Y, L.p2.Y) && max(L.p1.Y, L.p2.Y) <= y)
			isMet = true;

		if (isMet) puts("T");
		else puts("F");
	}

	return 0;
}