#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, pii> piii;
typedef tuple <int, int, int> ti3;

clock_t start_time, end_time;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
    TEST(start_time = clock());
}

void close() {
    TEST(end_time = clock());
    TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
}

const int MAX = 5e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct rec {
	int x, y, w, h;
} recs[MAX];

struct line {
	int x, lo, hi, idx;
	bool operator< (const line& other) const {
		return x == other.x ? hi > other.hi : x > other.x;
	}
} xx[MAX * 2], yy[MAX * 2];

int n;
pii pa[MAX];

int _find(int u) {
	if (pa[u].X < 0) return u;
	return pa[u].X = _find(pa[u].X);
}

void _union(int u, int v) {
	u = _find(u), v = _find(v);
	if (u != v) {
		pa[u].X = v;
		pa[v].Y += pa[u].Y;
	}
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d %d %d %d", &recs[i].x, &recs[i].y, &recs[i].w, &recs[i].h);
    	xx[2 * i - 1] = { recs[i].x, recs[i].y, recs[i].y + recs[i].h, i };
    	xx[2 * i] = { recs[i].x + recs[i].w, recs[i].y, recs[i].y + recs[i].h, i };
    	yy[2 * i - 1] = { recs[i].y, recs[i].x, recs[i].x + recs[i].w, i };
    	yy[2 * i] = { recs[i].y + recs[i].h, recs[i].x, recs[i].x + recs[i].w, i };
    }

    sort(xx + 1, xx + 2 * n + 1, [](const line& a, const line &b) {
    	return a.x == b.x ? a.lo < b.lo : a.x < b.x;
    });
    sort(yy + 1, yy + 2 * n + 1, [](const line& a, const line &b) {
    	return a.x == b.x ? a.lo < b.lo : a.x < b.x;
    });
    for (int i = 1; i <= n; ++i) pa[i] = { -1, recs[i].w * recs[i].h };

    priority_queue <line> pq; n *= 2;
	for (int i = 1; i < n; ++i) {
		while (!pq.empty() && (pq.top().x != xx[i].x || pq.top().hi < xx[i].lo)) pq.pop();
		if (!pq.empty()) _union(pq.top().idx, xx[i].idx);
		pq.push(xx[i]);
	}
	while (!pq.empty()) pq.pop();
	for (int i = 1; i < n; ++i) {
		while (!pq.empty() && (pq.top().x != yy[i].x || pq.top().hi < yy[i].lo)) pq.pop();
		if (!pq.empty()) _union(pq.top().idx, yy[i].idx);
		pq.push(yy[i]);
	}
	n /= 2;

	int ans = 0;
	for (int i = 1; i < MAX; ++i) 
		ans = max(ans, pa[i].Y);

	printf("%d\n", ans);

    close();
    return 0;
}
