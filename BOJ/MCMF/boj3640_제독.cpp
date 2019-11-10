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

int n, m, c[2001][2001], f[2001][2001], d[2001][2001], prv[2001], dist[2001];
bool inQ[2001];
vector <int> edges[2001];

int main(int argc, char *argv[]) {
    open();

    while (~scanf("%d %d", &n, &m)) {
    	int S = 1, T = 2 * n;
    	for (int i = 1; i <= n; ++i) {
    		int u = 2 * i - 1, v = 2 * i;
    		edges[u].push_back(v);
    		edges[v].push_back(u);
    		c[u][v] = 1;
    	}
    	c[1][2]++, c[2 * n - 1][2 * n]++;

    	for (int i = 0, u, v, w; i < m; ++i) {
    		scanf("%d %d %d", &u, &v, &w);
    		edges[2 * u].push_back(2 * v - 1);
    		edges[2 * v - 1].push_back(2 * u);
    		d[2 * u][2 * v - 1] = w;
    		d[2 * v - 1][2 * u] = -w;
    		c[2 * u][2 * v - 1] = 1;
    	}

    	int ans = 0;
    	while (1) {
    		memset(prv, -1, sizeof(prv));
    		memset(dist, 0x3f, sizeof(dist));
    		memset(inQ, false, sizeof(inQ));

    		dist[S] = 0; inQ[S] = true;
    		queue <int> q; q.push(S);

    		while (!q.empty()) {
    			int here = q.front(); q.pop();
    			inQ[here] = false;
    			for (int next : edges[here]) {
    				if (c[here][next] > f[here][next] && dist[next] > dist[here] + d[here][next]) {
    					dist[next] = dist[here] + d[here][next];
    					prv[next] = here;
    					if (!inQ[next]) {
    						inQ[next] = true;
    						q.push(next);
    					}
    				}
    			}
    		}
    		
    		if (prv[T] == -1) break;

    		int flow = INF;
    		for (int i = T; i != S; i = prv[i])
    			flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
    		for (int i = T; i != S; i = prv[i]) {
    			ans += flow * d[prv[i]][i];
    			f[prv[i]][i] += flow;
    			f[i][prv[i]] -= flow;
    		}
    	}

    	printf("%d\n", ans);

    	memset(c, 0, sizeof(c));
    	memset(f, 0, sizeof(f));
    	memset(d, 0, sizeof(d));
    	for (int i = 1; i <= 2000; ++i) edges[i].clear();
    }

    close();
    return 0;
}
