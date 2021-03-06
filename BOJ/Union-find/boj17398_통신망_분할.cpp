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

int n, m, q, pa[MAX], v[MAX], cnt[MAX];
vector<pii> edges;
vector<int> qs;

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        cnt[v] += cnt[u];
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});
    }
    for (int i = 0, a; i < q; ++i) {
        scanf("%d", &a);
        qs.push_back(a);
        v[a] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        pa[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i <= edges.size(); ++i) if (!v[i]) _union(edges[i - 1].X, edges[i - 1].Y);
    ll ans = 0;
    for (int idx: qs) {
        int uu = _find(edges[idx - 1].X);
        int vv = _find(edges[idx - 1].Y);
        if (uu != vv) {
            ans += 1LL * cnt[uu] * cnt[vv];
            _union(uu, vv);
        }
    }
    printf("%lld\n", ans);

    close();
    return 0;
}
