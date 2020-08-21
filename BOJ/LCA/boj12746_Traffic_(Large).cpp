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

const int MAX = 222222 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q, pa[MAX][18], d[MAX], c[MAX];
vector<int> edges[MAX];

void init(int node, int parent) {
    d[node] = d[parent] + 1;
    pa[node][0] = parent;
    for (int i = 1; i < 18; ++i)
        pa[node][i] = pa[pa[node][i - 1]][i - 1];
    for (int next: edges[node])
        if (next != parent)
            init(next, node);
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int i = 17; i >= 0; --i)
        if (d[u] - (1 << i) >= d[v])
            u = pa[u][i];
    if (u == v) return u;
    for (int i = 17; i >= 0; --i)
        if (pa[u][i] != pa[v][i]) {
            u = pa[u][i];
            v = pa[v][i];
        }
    return pa[u][0];
}

void dfs(int node, int parent) {
    for (int next: edges[node])
        if (next != parent)
            dfs(next, node);
    c[parent] += c[node];
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    init(1, 0);

    for (int i = 0, u, v; i < q; ++i) {
        scanf("%d %d", &u, &v);
        int LCA = lca(u, v);
        c[u]++; c[v]++; c[LCA] -= 2;
    }
    dfs(1, 0);

    int mx = -1;
    pii pos = {-1, -1};
    for (int i = 2; i <= n; ++i) {
        if (c[i] > mx) {
            mx = c[i];
            pos = {i, pa[i][0]};
            if (pos.X > pos.Y) swap(pos.X, pos.Y);
        } else if (c[i] == mx) {
            pii npos = {i, pa[i][0]};
            if (npos.X > npos.Y) swap(npos.X, npos.Y);
            pos = min(pos, npos);
        }
    }

    printf("%d %d %d\n", pos.X, pos.Y, mx);

    close();
    return 0;
}
