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

const int MAX = 3000;
const int INF = 0x7f7f7f7f;
line lines[MAX + 1];
int N, pa[MAX + 1];

void _swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

int _find(int a) {
	if (pa[a] < 0) return a;
	return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
	int a_root = _find(a);
	int b_root = _find(b);
	if (a_root != b_root)
		pa[a_root] = b_root;
}

bool check(line &a, line &b) {
	if (a.p2.X < b.p1.X || a.p1.X > b.p2.X) return false;
	if (min(a.p1.Y, a.p2.Y) > max(b.p1.Y, b.p2.Y) || max(a.p1.Y, a.p2.Y) < min(b.p1.Y, b.p2.Y)) return false;
	ll ccw1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
	ll ccw2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);
	return ccw1 <= 0 && ccw2 <= 0;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	memset(pa, -1, sizeof(pa));

	ll x, y, xx, yy;
	for (int i = 1; i <= N; ++i) {
		scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
		if (x > xx) {
			swap(x, xx);
			swap(y, yy);
		}

		lines[i] = { {x, y}, {xx, yy} };

		for (int j = 1; j < i; ++j) 
			if (check(lines[i], lines[j])) _union(i, j);
	}

	int count[MAX + 1] = { false, };
	int num = 0, mx = 0;
	for (int i = 1; i <= N; ++i) {
		int group = _find(i);
		if (count[group] == 0) num++;
		count[group]++;
		mx = max(mx, count[group]);
	}

	return !printf("%d\n%d\n", num, mx);
}