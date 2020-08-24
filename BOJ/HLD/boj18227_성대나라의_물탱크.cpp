/*
 *  Segment Tree with lazy propagation
**/

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

int n, r, q, qq, nn, hcnt, pa[MAX], cnt[MAX], hld[MAX], dep[MAX];
vector<int> edges[MAX], path[MAX];
vector<ll> tree[MAX], lazy[MAX];

int preprocess(int node, int parent) {
    dep[node] = dep[parent] + 1;
    pa[node] = parent;
    cnt[node] = 1;
    for (int next: edges[node])
        if (next != parent)
            cnt[node] += preprocess(next, node);
    return cnt[node];
}

void init(int root) {
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next: edges[node]) 
            if (next != pa[node]) 
                q.push(next);
        if (cnt[node] * 2 >= cnt[pa[node]] && node != root) 
            hld[node] = hld[pa[node]];
        else 
            hld[node] = hcnt++;
        path[hld[node]].push_back(node);
    }
}

void init_seg() {
    for (int i = 0; i < hcnt; ++i) {
        int sz = 1;
        while (sz < path[i].size()) sz <<= 1;
        tree[i].resize(sz << 1);
        lazy[i].resize(sz << 1);
    }
}

void update_lazy(int h, int v, int s, int e) {
    if (lazy[h][v]) {
        tree[h][v] += (e - s + 1) * lazy[h][v];
        if (s != e) {
            lazy[h][v * 2] += lazy[h][v];
            lazy[h][v * 2 + 1] += lazy[h][v];
        }
        lazy[h][v] = 0;
    }
}

void update_seg(int h, int v, int s, int e, int l, int r, int d) {
    update_lazy(h, v, s, e);
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        lazy[h][v] += d;
        update_lazy(h, v, s, e);
        return;
    }
    int mid = (s + e) >> 1;
    update_seg(h, v * 2, s, mid, l, r, d);
    update_seg(h, v * 2 + 1, mid + 1, e, l, r, d);
    tree[h][v] = tree[h][v * 2] + tree[h][v * 2 + 1];
}

void update(int node) {
    while (hld[node] != hld[r]) {
        update_seg(hld[node], 1, 0, path[hld[node]].size() - 1, 0, dep[node] - dep[path[hld[node]][0]], 1);
        node = pa[path[hld[node]][0]];
    }
    update_seg(hld[node], 1, 0, path[hld[node]].size() - 1, 0, dep[node] - dep[r], 1);
}

ll query(int h, int v, int s, int e, int p) {
    update_lazy(h, v, s, e);
    if (e < p || p < s) return 0;
    if (s == e) return tree[h][v];
    int mid = (s + e) >> 1;
    return query(h, v * 2, s, mid, p) + query(h, v * 2 + 1, mid + 1, e, p);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &r);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    preprocess(r, 0);
    init(r);
    init_seg();

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &qq, &nn);
        if (qq == 1) update(nn);
        else printf("%lld\n", dep[nn] * query(hld[nn], 1, 0, path[hld[nn]].size() - 1, dep[nn] - dep[path[hld[nn]][0]]));
    }

    close();
    return 0;
}


/*
 *  fenwick tree
**/
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

int n, r, q, qq, nn, hcnt, pa[MAX], cnt[MAX], hld[MAX], dep[MAX];
vector<int> edges[MAX], tree[MAX], path[MAX];

int preprocess(int node, int parent) {
    dep[node] = dep[parent] + 1;
    pa[node] = parent;
    cnt[node] = 1;
    for (int next: edges[node])
        if (next != parent)
            cnt[node] += preprocess(next, node);
    return cnt[node];
}

void init(int root) {
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int next: edges[node]) 
            if (next != pa[node]) 
                q.push(next);
        if (cnt[node] * 2 >= cnt[pa[node]] && node != root) 
            hld[node] = hld[pa[node]];
        else 
            hld[node] = hcnt++;
        path[hld[node]].push_back(node);
    }
}

void init_seg() {
    for (int i = 0; i < hcnt; ++i) 
        tree[i].resize(path[i].size() + 2);
}

void update_seg(int h, int v, int d) {
    while (v < tree[h].size()) {
        tree[h][v] += d;
        v += v & -v;
    }
}

void update(int node) {
    while (hld[node] != hld[r]) {
        update_seg(hld[node], 1, 1);
        update_seg(hld[node], dep[node] - dep[path[hld[node]][0]] + 2, -1);
        node = pa[path[hld[node]][0]];
    }
    update_seg(hld[node], 1, 1);
    update_seg(hld[node], dep[node] - dep[path[hld[node]][0]] + 2, -1);
}

int query(int h, int v) {
    int ret = 0;
    while (v) {
        ret += tree[h][v];
        v -= v & -v;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &r);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    preprocess(r, 0);
    init(r);
    init_seg();

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &qq, &nn);
        if (qq == 1) update(nn);
        else printf("%lld\n", 1LL * dep[nn] * query(hld[nn], dep[nn] - dep[path[hld[nn]][0]] + 1));
    }

    close();
    return 0;
}
