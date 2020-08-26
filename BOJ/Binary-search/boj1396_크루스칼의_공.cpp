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

int n, m, q, x, y, lo[MAX], hi[MAX], c[MAX], pa[MAX], cnt[MAX];
vector<int> idx[MAX]; 
vector<piii> edges;
vector<pii> qs;

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (u == v) return;
    if (u < v) swap(u, v);
    pa[v] = u;
    cnt[u] += cnt[v];
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    scanf("%d", &q);
    for (int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        qs.push_back({a, b});
        lo[i] = 0, hi[i] = m - 1;
    }

    bool updated = true;
    while (updated) {
        updated = false;
        for (int i = 1; i <= n; ++i) pa[i] = i, cnt[i] = 1;
        for (int i = 0; i < m; ++i) idx[i].clear();
        for (int i = 0; i < q; ++i) if (lo[i] <= hi[i]) {
            updated = true;
            idx[(lo[i] + hi[i]) >> 1].push_back(i);
        }
        for (int i = 0; i < edges.size(); ++i) {
            _union(edges[i].Y.X, edges[i].Y.Y);
            while (!idx[i].empty()) {
                int j = idx[i].back(); idx[i].pop_back();
                if (_find(qs[j].X) == _find(qs[j].Y)) {
                    hi[j] = i - 1;
                    c[j] = cnt[_find(qs[j].X)];
                } else lo[j] = i + 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        if (lo[i] == m) puts("-1");
        else printf("%d %d\n", edges[lo[i]].X, c[i]);
    }

    close();
    return 0;
}
