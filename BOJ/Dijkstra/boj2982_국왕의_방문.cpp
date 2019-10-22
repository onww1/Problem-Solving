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

int n, m, a, b, k, g, p[1005], d[1005][1005], dist[1005];
pii c[1005][1005];
vector <pii> edges[1005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &a, &b, &k, &g);
    for (int i = 1; i <= g; ++i) scanf("%d", p + i);
    for (int i = 0, u, v, w; i < m; ++i) {
    	scanf("%d %d %d", &u, &v, &w);
    	edges[u].push_back({v, w});
    	edges[v].push_back({u, w});
    	d[u][v] = d[v][u] = w;
    }
    for (int i = 1; i < g; ++i) {
    	int prv = c[p[i - 1]][p[i]].Y;
    	c[p[i + 1]][p[i]] = c[p[i]][p[i + 1]] = { prv, prv + d[p[i]][p[i + 1]] };
    }

    memset(dist, 0x3f, sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[a] = k; pq.push({dist[a], a});

    while (!pq.empty()) {
    	int dd = pq.top().X;
    	int cur = pq.top().Y;
    	pq.pop();

    	if (dist[cur] < dd) continue;
    	if (cur == b) return !printf("%d\n", dd - k);

    	for (pii edge : edges[cur]) {
    		if (c[cur][edge.X].Y && c[cur][edge.X].X <= dd && dd < c[cur][edge.X].Y) {
    			if (dist[edge.X] > c[cur][edge.X].Y + edge.Y) {
    				dist[edge.X] = c[cur][edge.X].Y + edge.Y;
    				pq.push({dist[edge.X], edge.X});
    			}
    		}
    		else if (dist[edge.X] > dd + edge.Y) {
    			dist[edge.X] = dd + edge.Y;
    			pq.push({dist[edge.X], edge.X});
    		}
    	}
    }

    close();
    return 0;
}