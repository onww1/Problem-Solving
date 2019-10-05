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

int n, m, depth[30005], pa[15][30005];
vector <int> edges[30005];

void init(int node, int parent) {
    pa[0][node] = parent;
    depth[node] = depth[parent] + 1;

    for (int i = 1; i < 15; ++i) 
        pa[i][node] = pa[i - 1][pa[i - 1][node]];

    for (int next : edges[node])
        if (next != parent)
            init(next, node);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = 14; i >= 0; --i) 
        if (depth[pa[i][u]] >= depth[v])
            u = pa[i][u];

    if (u == v) return u;

    for (int i = 14; i >= 0; --i) 
        if (pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }

    return pa[0][u];
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

    scanf("%d", &m);
    int pos = 1, ans = 0;
    for (int i = 0, v; i < m; ++i) {
        scanf("%d", &v);
        int LCA = lca(pos, v);
        ans += depth[pos] + depth[v] - 2 * depth[LCA];
        pos = v;
    }

    printf("%d\n", ans);
    close();
    return 0;
}