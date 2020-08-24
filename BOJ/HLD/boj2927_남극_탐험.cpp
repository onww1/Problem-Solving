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

const int MAX = 3e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q, hcnt, pn[MAX], cne[MAX], cnt[MAX], dep[MAX], hld[MAX], pa[MAX], pp[MAX];
char in[20];
vector<piii> qs;
vector<pii> tree[MAX];
vector<int> edges[MAX], path[MAX];

int _find(int u) {
    if (pp[u] == u) return u;
    return pp[u] = _find(pp[u]);
}

void _union(int u, int v) {
    int pu = _find(u);
    int pv = _find(v);
    if (pu != pv) {
        pp[pu] = pv;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}

int preprocess(int node, int parent) {
    cne[node] = cnt[node] = 1;
    dep[node] = dep[parent] + 1;
    pa[node] = parent;
    for (int next: edges[node])
        if (next != parent)
            cnt[node] += preprocess(next, node);
    return cnt[node];
}

void init_seg(int h, int v, int s, int e) {
    if (s == e) {
        tree[h][v] = {pn[path[h][s]], cne[path[h][s]]};
        return;
    }
    int mid = (s + e) >> 1;
    init_seg(h, v * 2, s, mid);
    init_seg(h, v * 2 + 1, mid + 1, e);
    tree[h][v] = {tree[h][v * 2].X + tree[h][v * 2 + 1].X, tree[h][v * 2].Y + tree[h][v * 2 + 1].Y};
}

void init(int root) {
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next: edges[node])
            if (next != pa[node])
                q.push(next);
        if (cnt[node] * 2 >= cnt[pa[node]] && node != root) hld[node] = hld[pa[node]];
        else hld[node] = hcnt++;
        path[hld[node]].push_back(node);
    }

    for (int i = 0; i < hcnt; ++i) {
        int sz = 1;
        while (sz < path[i].size()) sz <<= 1;
        tree[i].resize(sz << 1);
        init_seg(i, 1, 0, path[i].size() - 1);
    }
}

void update_seg(int h, int v, int s, int e, int idx) {
    if (e < idx || idx < s) return;
    if (s == e) {
        tree[h][v].X = pn[path[h][s]];
        tree[h][v].Y = cne[path[h][s]];
        return;
    }
    int mid = (s + e) >> 1;
    update_seg(h, v * 2, s, mid, idx);
    update_seg(h, v * 2 + 1, mid + 1, e, idx);
    tree[h][v].X = tree[h][v * 2].X + tree[h][v * 2 + 1].X;
    tree[h][v].Y = tree[h][v * 2].Y + tree[h][v * 2 + 1].Y;
}

pii query_seg(int h, int v, int s, int e, int l, int r) {
    if (e < l || r < s) return {0, 0};
    if (l <= s && e <= r) return tree[h][v];
    int mid = (s + e) >> 1;
    pii left = query_seg(h, v * 2, s, mid, l, r);
    pii right = query_seg(h, v * 2 + 1, mid + 1, e, l, r);
    return {left.X + right.X, left.Y + right.Y};
}

pii query(int u, int v) {
    pii ret = {0, 0}, res;
    while (hld[u] != hld[v]) {
        if (dep[path[hld[u]][0]] < dep[path[hld[v]][0]]) swap(u, v);
        res = query_seg(hld[u], 1, 0, path[hld[u]].size() - 1, 0, dep[u] - dep[path[hld[u]][0]]);
        ret.X += res.X;
        ret.Y += res.Y;
        u = pa[path[hld[u]][0]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    res = query_seg(hld[u], 1, 0, path[hld[u]].size() - 1, dep[v] - dep[path[hld[u]][0]], dep[u] - dep[path[hld[u]][0]]);
    ret.X += res.X;
    ret.Y += res.Y;
    res = query_seg(hld[u], 1, 0, path[hld[u]].size() - 1, dep[v] - dep[path[hld[u]][0]], dep[v] - dep[path[hld[u]][0]]);
    ret.Y -= res.Y;
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", pn + i);
        pp[i] = i;
    }

    scanf("%d", &q);
    for (int i = 0, u, v; i < q; ++i) {
        scanf(" %s %d %d", in, &u, &v);
        if (in[0] == 'b') {
            qs.push_back({0, {u, v}});
            _union(u, v);
        } 
        else qs.push_back({in[0] == 'p' ? 1 : 2, {u, v}});
    }
    for (int i = 2; i <= n; ++i) _union(i - 1, i);

    cne[1] = 0;
    preprocess(1, 0);
    init(1);

    for (piii& qq: qs) {
        if (qq.X == 0) {
            pii res = query(qq.Y.X, qq.Y.Y);
            if (res.Y == 0) puts("no");
            else {
                puts("yes");
                int vv = -1;
                if (dep[qq.Y.X] > dep[qq.Y.Y]) {
                    cne[qq.Y.X] = 0;
                    vv = qq.Y.X;
                } else {
                    cne[qq.Y.Y] = 0;
                    vv = qq.Y.Y;
                }
                update_seg(hld[vv], 1, 0, path[hld[vv]].size() - 1, dep[vv] - dep[path[hld[vv]][0]]);
            }
        } else if (qq.X == 1) {
            pn[qq.Y.X] = qq.Y.Y;
            update_seg(hld[qq.Y.X], 1, 0, path[hld[qq.Y.X]].size() - 1, dep[qq.Y.X] - dep[path[hld[qq.Y.X]][0]]);
        } else {
            pii res = query(qq.Y.X, qq.Y.Y);
            if (res.Y > 0) puts("impossible");
            else printf("%d\n", res.X);
        }
    }

    close();
    return 0;
}
