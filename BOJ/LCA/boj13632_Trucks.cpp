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

const int MAX = 2e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, q, pa[MAX][15], mv[MAX][15], dep[MAX], p[MAX];
vector<pii> edges[MAX];
priority_queue<piii> pq;

int _find(int u) {
    if (p[u] == u) return u;
    return p[u] = _find(p[u]);
}

bool _union(int u, int v) {
    u = _find(u), v = _find(v);
    p[u] = v;
    return u != v;
}

void init(int node, int parent, int w) {
    dep[node] = dep[parent] + 1;
    pa[node][0] = parent;
    mv[node][0] = w;

    for (int i = 1; i < 15; ++i) {
        mv[node][i] = min(mv[node][i - 1], mv[pa[node][i - 1]][i - 1]);
        pa[node][i] = pa[pa[node][i - 1]][i - 1];
    }

    for (pii& edge: edges[node])
        if (edge.X != parent)
            init(edge.X, node, edge.Y);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int mn = INF;
    for (int i = 14; i >= 0; --i)
        if (dep[u] - (1 << i) >= dep[v]) {
            mn = min(mn, mv[u][i]);
            u = pa[u][i];
        }
    if (u == v) return mn;
    for (int i = 14; i >= 0; --i)
        if (pa[u][i] != pa[v][i]) {
            mn = min({mn, mv[u][i], mv[v][i]});
            u = pa[u][i], v = pa[v][i];
        }
    return min({mn, mv[u][0], mv[v][0]});
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        pq.push({w, {u, v}});
    }
    
    while (!pq.empty()) {
        piii cur = pq.top(); pq.pop();
        if (_union(cur.Y.X, cur.Y.Y)) {
            edges[cur.Y.X].push_back({cur.Y.Y, cur.X});
            edges[cur.Y.Y].push_back({cur.Y.X, cur.X});
        }
    }

    init(1, 0, INF);
    for (int i = 0, u, v; i < q; ++i) {
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u, v));
    }

    close();
    return 0;
}
