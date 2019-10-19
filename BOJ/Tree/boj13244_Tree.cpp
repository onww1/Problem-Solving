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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, n, m, pa[1005];
bool vv[1005][1005];

int _find(int u) {
	if (pa[u] < 0) return u;
	return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
	u = _find(u), v = _find(v);
	if (u != v) {
		pa[u] = v;
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
    	scanf("%d %d", &n, &m);
    	for (int i = 1; i <= n; ++i) pa[i] = -1;

    	int cnt = 0;
    	bool tree = true;
    	for (int i = 0, u, v; i < m; ++i) {
    		scanf("%d %d", &u, &v);
    		if (!vv[u][v]) {
    			vv[u][v] = vv[v][u] = true;
    			if (_union(u, v)) cnt++;
    			else tree = false;
    		}
    		else tree = false;
    	}

    	puts((tree && cnt == n - 1) ? "tree" : "graph");

    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= n; ++j)
    			vv[i][j] = false;
    }

    close();
    return 0;
}