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

int n, m, d[505][505], pa[250050];
pii v, o;
char in[505][505];
vector <pii> pp[1005];

int _find(int u) {
	if (pa[u] < 0) return u;
	return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
	u = _find(u), v = _find(v);
	if (u != v) pa[u] = v;
}

int main(int argc, char *argv[]) {
    open();

    queue <pii> q;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
    	scanf(" %s", in[i]);
    	for (int j = 0; j < m; ++j) {
    		if (in[i][j] == '+') {
    			d[i][j] = 1;
    			q.push({i, j});
    		}
    		else if (in[i][j] == 'V') v = {i, j};
    		else if (in[i][j] == 'J') o = {i, j};
    	}
    }

    while (!q.empty()) {
    	int r = q.front().X;
    	int c = q.front().Y;
    	q.pop();

    	pp[d[r][c]].push_back({r, c});

    	for (int k = 0; k < 4; ++k) {
    		int dr = r + move_r[k];
    		int dc = c + move_c[k];
    		if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
    		if (!d[dr][dc]) {
    			d[dr][dc] = d[r][c] + 1;
    			q.push({dr, dc});
    		}
    	}
    }

    memset(pa, -1, sizeof(pa));
    int src = v.X * m + v.Y, dst = o.X * m + o.Y, ans = d[v.X][v.Y];
    for (int i = ans; !pp[i].empty(); ++i) {
    	for (pii pos : pp[i]) {
    		for (int k = 0; k < 4; ++k) {
    			int dr = pos.X + move_r[k];
    			int dc = pos.Y + move_c[k];
    			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
    			if (d[dr][dc] >= ans)
    				_union(pos.X * m + pos.Y, dr * m + dc);
    		}
    	}
    }

    while (1) {
    	if (_find(src) == _find(dst)) break;
    	ans--;
    	for (pii pos : pp[ans]) {
    		for (int k = 0; k < 4; ++k) {
    			int dr = pos.X + move_r[k];
    			int dc = pos.Y + move_c[k];
    			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
    			if (d[dr][dc] >= ans)
    				_union(pos.X * m + pos.Y, dr * m + dc);
    		}
    	}
    }
    printf("%d\n", ans - 1);

    close();
    return 0;
}