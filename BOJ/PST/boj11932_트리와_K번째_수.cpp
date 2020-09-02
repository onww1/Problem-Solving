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

struct Node {
    Node *l, *r;
    int x;
    Node(): l(nullptr), r(nullptr), x(0){}
} *r[MAX];

int n, m, w[MAX], pa[MAX][17], dep[MAX];
vector<int> v, edges[MAX];

void init(Node *node, int s, int e) {
    if (s == e) return;
    node->l = new Node();
    node->r = new Node();
    int mid = (s + e) >> 1;
    init(node->l, s, mid);
    init(node->r, mid + 1, e);
}

void update(Node *node, Node *parent, int s, int e, int v) {
    if (e < v || v < s) return;
    if (s == e) {
        node->x = parent->x + 1;
        return;
    }
    int mid = (s + e) >> 1;
    if (v <= mid) {
        node->l = new Node();
        node->r = parent->r;
        update(node->l, parent->l, s, mid, v);
    }
    else {
        node->l = parent->l;
        node->r = new Node();
        update(node->r, parent->r, mid + 1, e, v);
    }
    node->x = node->l->x + node->r->x;
}

void dfs(int node, int parent) {
    dep[node] = dep[parent] + 1;
    pa[node][0] = parent;
    for (int i = 1; i < 17; ++i)
        pa[node][i] = pa[pa[node][i - 1]][i - 1];
    r[node] = new Node();
    update(r[node], r[parent], 0, n - 1, w[node]);
    for (int next: edges[node]) 
        if (next != parent)
            dfs(next, node);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 16; i >= 0; --i)
        if (dep[u] - (1 << i) >= dep[v])
            u = pa[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; --i)
        if (pa[u][i] != pa[v][i]) {
            u = pa[u][i];
            v = pa[v][i];
        }
    return pa[u][0];
}

int query(Node *u, Node *v, Node *lca, Node *lcap, int s, int e, int k) {
    if (s == e) return s;
    int sum = u->l->x + v->l->x - lca->l->x - lcap->l->x;
    int mid = (s + e) >> 1;
    if (sum < k) return query(u->r, v->r, lca->r, lcap->r, mid + 1, e, k - sum);
    else return query(u->l, v->l, lca->l, lcap->l, s, mid, k);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", w + i);
        v.push_back(w[i]);
    }

    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i) 
        w[i] = lower_bound(v.begin(), v.end(), w[i]) - v.begin();

    r[0] = new Node();
    init(r[0], 0, n - 1);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);

    for (int i = 0, x, y, k; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &k);
        int LCA = lca(x, y);
        int idx = query(r[x], r[y], r[LCA], r[pa[LCA][0]], 0, n - 1, k);
        printf("%d\n", v[idx]);
    }

    close();
    return 0;
}
