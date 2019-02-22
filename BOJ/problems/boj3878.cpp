#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct line {
	pll p1, p2;
};

const int MAX = 100;
ll T, N, M, X, Y;
pll black[MAX + 2], white[MAX + 2];
pll BASE, INF = { -100000, -1 };

ll CCW(pll p1, pll p2, pll p3) {
	ll ret = 0;
	ret += p1.X * (p2.Y - p3.Y);
	ret += p2.X * (p3.Y - p1.Y);
	ret += p3.X * (p1.Y - p2.Y);
	return ret;
}

bool cmp(pll a, pll b) {
	ll ccw = CCW(BASE, a, b);
	if (ccw > 0) return true;
	else if (ccw < 0) return false;
	return a.X < b.X;
}

vector <line> make_convex_hull(pll points[], ll size) {
	sort(points, points + size);
	BASE = points[0];
	sort(points + 1, points + size, cmp);

	vector <line> ret;

	if (size <= 2) {
		line L = { points[0], points[size - 1] };
		ret.push_back(L);
		return ret;
	}

	vector <int> convex;
	convex.push_back(0);
	convex.push_back(1);
	int convex_size = 2;
	for (int i = 2; i < size; ++i) {
		while (convex_size > 1 && CCW(points[convex[convex_size - 2]], points[convex[convex_size - 1]], points[i]) <= 0) {
			convex.pop_back();
			convex_size--;
		}
		convex.push_back(i);
		convex_size++;
	}

	for (int i = 1; i < convex_size; ++i) 
		ret.push_back(line({ points[convex[i - 1]], points[convex[i]] }));
	ret.push_back(line({ points[convex[convex_size - 1]], points[convex[0]] }));

	return ret;
}

bool check(line &a, line &b) {
	if (min(a.p1.X, a.p2.X) > max(b.p1.X, b.p2.X) || min(b.p1.X, b.p2.X) > max(a.p1.X, a.p2.X)) return false;
	if (min(a.p1.Y, a.p2.Y) > max(b.p1.Y, b.p2.Y) || min(b.p1.Y, b.p2.Y) > max(a.p1.Y, a.p2.Y)) return false;

	ll ccw1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
	ll ccw2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);

	if (ccw1 <= 0 && ccw2 <= 0) return true;
	return false;
}

bool isInner(pll &a, vector <line> &convex) {
	line cur = line({ a, INF });
	int cnt = 0;
	for (line L : convex) {
		ll ccw1 = CCW(cur.p1, cur.p2, L.p1) * CCW(cur.p1, cur.p2, L.p2);
		ll ccw2 = CCW(L.p1, L.p2, cur.p1) * CCW(L.p1, L.p2, cur.p2);
		if (ccw1 < 0 && ccw2 < 0) cnt++;
	}
	return cnt % 2 == 1;
}

int main(int argc, char *argv[]) {
	for (scanf("%lld", &T); T; T--) {
		scanf("%lld %lld", &N, &M);
		for (int i = 0; i < N; ++i) {
			scanf("%lld %lld", &X, &Y);
			black[i] = { X, Y };
		}
		for (int i = 0; i < M; ++i) {
			scanf("%lld %lld", &X, &Y);
			white[i] = { X, Y };
		}

		vector <line> black_convex = make_convex_hull(black, N);
		vector <line> white_convex = make_convex_hull(white, M);
		
		bool valid = true;
		for (int i = 0; valid && i < black_convex.size(); ++i) 
			for (int j = 0; valid && j < white_convex.size(); ++j) 
				if (check(black_convex[i], white_convex[j])) 
					valid = false;
			
		if (!valid) {
			puts("NO");
			continue;
		}

		if (isInner(black_convex[0].p1, white_convex) || isInner(black_convex[0].p2, white_convex)) valid = false;
		if (isInner(white_convex[0].p1, black_convex) || isInner(white_convex[0].p2, black_convex)) valid = false;

		puts(valid ? "YES" : "NO");
	}
	
	return 0;
}