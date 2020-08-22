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

int n, q, x, y, z, pa[MAX][17], dep[MAX];
vector<int> edges[MAX];

struct info {
    int dist, x, y, lca;
    info(int _d, int _x, int _y, int _l): dist(_d), x(_x), y(_y), lca(_l){}
    bool operator< (const info& other) const {
        return dist > other.dist;
    };
};

void init(int node, int parent) {
    dep[node] = dep[parent] + 1;
    pa[node][0] = parent;
    for (int i = 1; i < 17; ++i)
        pa[node][i] = pa[pa[node][i - 1]][i - 1];
    for (int next: edges[node])
        if (next != parent)
            init(next, node);
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

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    init(1, 0);

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &x, &y, &z);
        int LCA_xy = lca(x, y);
        int LCA_yz = lca(y, z);
        int LCA_zx = lca(z, x);
        vector<info> v;
        v.emplace_back(dep[x] + dep[y] - 2 * dep[LCA_xy], x, y, LCA_xy);
        v.emplace_back(dep[y] + dep[z] - 2 * dep[LCA_yz], y, z, LCA_yz);
        v.emplace_back(dep[z] + dep[x] - 2 * dep[LCA_zx], z, x, LCA_zx);
        if (v[0].dist % 2 || v[1].dist % 2 || v[2].dist % 2) {
            puts("-1");
            continue;
        }
        sort(v.begin(), v.end());

        if (dep[v[0].x] < dep[v[0].y]) swap(v[0].x, v[0].y);
        int d = v[0].dist >> 1, p = v[0].x;
        for (int i = 16; i >= 0; --i)
            if (d - (1 << i) >= 0) {
                d -= (1 << i);
                p = pa[p][i];
            }
        int r = x + y + z - v[0].x - v[0].y;
        int LCA_pr = lca(p, r);
        if (dep[p] + dep[r] - 2 * dep[LCA_pr] == v[0].dist / 2) printf("%d\n", p);
        else puts("-1");
    }

    close();
    return 0;
}
