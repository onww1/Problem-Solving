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

int n, m, pa[MAX], cnt[MAX], hld[MAX], dep[MAX];
vector<int> edges[MAX];
vector<vector<ll>> trees, lazys;
vector<vector<int>> hpath;

int preprocess(int node, int parent) {
    pa[node] = parent;
    cnt[node] = 1;
    dep[node] = dep[parent] + 1;
    for (int next: edges[node])
        if (next != parent)
            cnt[node] += preprocess(next, node);
    return cnt[node];
}

void init(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int next: edges[node])
            if (next != pa[node])
                q.push(next);

        if (node == root) {
            hld[node] = 0;
            hpath.push_back(vector<int>(1));
            hpath.back()[0] = node;
            continue;
        }
        int p = pa[node];

        if (cnt[node] * 2 >= cnt[p]) {
            int phld = hld[p];
            hpath[phld].push_back(node);
            hld[node] = phld;
        } else {
            hld[node] = hpath.size();
            hpath.push_back(vector<int>(1));
            hpath.back()[0] = node;
        }
    }
}

void resize_segment() {
    trees.resize(hpath.size());
    lazys.resize(hpath.size());
    for (int i = 0; i < hpath.size(); ++i) {
        int sz = 1;
        while (sz < hpath[i].size()) sz <<= 1;
        trees[i].resize(sz << 1);
        lazys[i].resize(sz << 1);
    }
}

void update_lazy(int h, int v, int s, int e) {
    if (lazys[h][v]) {
        trees[h][v] += lazys[h][v] * (e - s + 1);
        if (s != e) {
            lazys[h][v * 2] += lazys[h][v];
            lazys[h][v * 2 + 1] += lazys[h][v];
        }
        lazys[h][v] = 0;
    }
}

void update_seg(int h, int v, int s, int e, int l, int r) {
    update_lazy(h, v, s, e);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazys[h][v]++;
        update_lazy(h, v, s, e);
        return;
    }
    int md = (s + e) >> 1;
    update_seg(h, v * 2, s, md, l, r);
    update_seg(h, v * 2 + 1, md + 1, e, l, r);
    trees[h][v] = trees[h][v * 2] + trees[h][v * 2 + 1];
}

ll query_seg(int h, int v, int s, int e, int l, int r) {
    update_lazy(h, v, s, e);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return trees[h][v];
    int md = (s + e) >> 1;
    return query_seg(h, v * 2, s, md, l, r) + query_seg(h, v * 2 + 1, md + 1, e, l, r);
}

void update(int u, int v) {
    while (hld[u] != hld[v]) {
        if (dep[hpath[hld[u]][0]] < dep[hpath[hld[v]][0]]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        update_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, 0, dep[u] - d);
        u = pa[hpath[hld[u]][0]];
    }
    if (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        update_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, dep[v] - d + 1, dep[u] - d);
        u = v;
    }
}

ll query(int u, int v) {
    ll ret = 0;
    while (hld[u] != hld[v]) {
        if (dep[hpath[hld[u]][0]] < dep[hpath[hld[v]][0]]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        ret += query_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, 0, dep[u] - d);
        u = pa[hpath[hld[u]][0]];
    }
    if (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        ret += query_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, dep[v] - d + 1, dep[u] - d);
        u = v;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    preprocess(1, 0);
    init(1);
    resize_segment();

    while (m--) {
        char q; int u, v;
        scanf(" %c %d %d", &q, &u, &v);
        if (q == 'P') update(u, v);
        else printf("%lld\n", query(u, v));
    }

    close();
    return 0;
}
