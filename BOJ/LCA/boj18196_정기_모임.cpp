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

const int SZ = 1 << 19;
const int MAX = 3e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q, pa[MAX][19], mv[MAX][19], dep[MAX], LCA[MAX], tree[SZ << 1];
vector<pii> edges[MAX];

void init_lca(int node, int parent, int w) {
    dep[node] = dep[parent] + 1;
    pa[node][0] = parent;
    mv[node][0] = w;

    for (int i = 1; i < 19; ++i) {
        pa[node][i] = pa[pa[node][i - 1]][i - 1];
        mv[node][i] = max(mv[node][i - 1], mv[pa[node][i - 1]][i - 1]);
    }

    for (pii& edge: edges[node])
        if (edge.X != parent)
            init_lca(edge.X, node, edge.Y);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int mx = 0;
    for (int i = 18; i >= 0; --i)
        if (dep[u] - (1 << i) >= dep[v]) {
            mx = max(mx, mv[u][i]);
            u = pa[u][i];
        }
    if (u == v) return mx;
    for (int i = 18; i >= 0; --i)
        if (pa[u][i] != pa[v][i]) {
            mx = max({mx, mv[u][i], mv[v][i]});
            u = pa[u][i];
            v = pa[v][i];
        }
    mx = max({mx, mv[u][0], mv[v][0]});
    return mx;
}

void init_seg(int v, int s, int e) {
    if (s == e) {
        tree[v] = 0;
        return;
    }
    int md = (s + e) >> 1;
    init_seg(v * 2, s, md);
    init_seg(v * 2 + 1, md + 1, e);
    tree[v] = max({tree[v * 2], tree[v * 2 + 1], LCA[md]});
}

int query(int v, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[v];
    int md = (s + e) >> 1;
    int ret = max(query(v * 2, s, md, l, r), query(v * 2 + 1, md + 1, e, l, r));
    if (l <= md && md + 1 <= r) ret = max(ret, LCA[md]);
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    init_lca(1, 0, 0);
    for (int i = 1; i < n; ++i) LCA[i] = lca(i, i + 1);

    init_seg(1, 1, n);
    for (int i = 1, u, v; i <= q; ++i) {
        scanf("%d %d", &u, &v);
        printf("%d\n", query(1, 1, n, u, v));
    }

    close();
    return 0;
}
