#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 100000;
ll N, X, Y;
pll points[MAX + 2];

ll CCW(pll p1, pll p2, pll p3) {
	ll ret = 0;
	ret += p1.X * (p2.Y - p3.Y);
	ret += p2.X * (p3.Y - p1.Y);
	ret += p3.X * (p1.Y - p2.Y);
	return ret;
}

bool cmp(pll a, pll b) {
	ll ccw = CCW(points[0], a, b);
	if (ccw > 0) return true;
	else if (ccw < 0) return false;
	return a.X < b.X;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld %lld", &X, &Y);
		points[i] = { X, Y };
	}
	
	sort(points, points + N);
	sort(points + 1, points + N, cmp);
	
	vector <int> convex;
	convex.push_back(0);
	convex.push_back(1);
	int convex_size = 2;
	for (int i = 2; i < N; ++i) {
		while (convex_size > 1 && CCW(points[convex[convex_size - 2]], points[convex[convex_size - 1]], points[i]) <= 0) {
			convex.pop_back();
			convex_size--;
		}
		convex.push_back(i);
		convex_size++;
	}
	
	return !printf("%d\n", convex_size);
}