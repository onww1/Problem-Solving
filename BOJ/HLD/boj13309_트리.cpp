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

const int MAX = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q, hcnt, cnt[MAX], hld[MAX], dep[MAX], pa[MAX];
vector<int> edges[MAX], hpath[MAX], trees[MAX];

int preprocess(int node) {
    dep[node] = dep[pa[node]] + 1;
    cnt[node] = 1;
    for (int next: edges[node])
        cnt[node] += preprocess(next);
    return cnt[node];
}

void init(int root) {
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next: edges[node])
            q.push(next);

        if (cnt[node] * 2 >= cnt[pa[node]] && node != root) hld[node] = hld[pa[node]];    
        else hld[node] = hcnt++;
        hpath[hld[node]].push_back(node);
    }
}

void f(int h, int v, int s, int e) {
    if (s == e) {
        trees[h][v] = 1;
        return;
    }
    int md = (s + e) >> 1;
    f(h, v * 2, s, md);
    f(h, v * 2 + 1, md + 1, e);
    trees[h][v] = trees[h][v * 2] + trees[h][v * 2 + 1];
}

void init_seg() {
    for (int i = 0; i < hcnt; ++i) {
        int sz = 1;
        while (sz < hpath[i].size()) sz <<= 1;
        trees[i].resize(sz << 1, 0);
        f(i, 1, 0, hpath[i].size() - 1);
    }
}

void update_seg(int h, int v, int s, int e, int idx) {
    if (e < idx || idx < s) return;
    if (s == e) {
        trees[h][v] = 0;
        return;
    }
    int md = (s + e) >> 1;
    update_seg(h, v * 2, s, md, idx);
    update_seg(h, v * 2 + 1, md + 1, e, idx);
    trees[h][v] = trees[h][v * 2] + trees[h][v * 2 + 1];
}

int query_seg(int h, int v, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return trees[h][v];
    int md = (s + e) >> 1;
    return query_seg(h, v * 2, s, md, l, r) + query_seg(h, v * 2 + 1, md + 1, e, l, r);
}

bool query(int u, int v) {
    int tot = 0, val = 0;
    while (hld[u] != hld[v]) {
        if (dep[hpath[hld[u]][0]] < dep[hpath[hld[v]][0]]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        tot += dep[u] - d + 1;
        val += query_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, 0, dep[u] - d);
        u = pa[hpath[hld[u]][0]];
    }
    if (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[hpath[hld[u]][0]];
        tot += dep[u] - dep[v];
        val += query_seg(hld[u], 1, 0, hpath[hld[u]].size() - 1, dep[v] + 1 - d, dep[u] - d);
        u = v;
    }
    return tot == val;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", pa + i);
        edges[pa[i]].push_back(i);
    }
    preprocess(1);
    init(1);
    init_seg();

    for (int i = 0, x, y, z; i < q; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        bool res = query(x, y);
        puts(res ? "YES" : "NO");
        if (z) {
            int target = res ? x : y;
            update_seg(hld[target], 1, 0, hpath[hld[target]].size() - 1, dep[target] - dep[hpath[hld[target]][0]]);
        }
    }

    close();
    return 0;
}
