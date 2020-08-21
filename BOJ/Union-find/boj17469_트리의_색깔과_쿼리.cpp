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

int n, q, pa[MAX], v[MAX], e[MAX];
map<int,int> cnt[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        if (cnt[u].size() < cnt[v].size()) swap(u, v);
        pa[v] = u;
        for (auto it = cnt[v].begin(); it != cnt[v].end(); ++it)
            cnt[u][it->X] += it->Y;
        cnt[v].clear();
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    pa[1] = 1;
    for (int i = 2; i <= n; ++i) {
        scanf("%d", e + i);
        pa[i] = i;
    }
    for (int i = 1, c; i <= n; ++i) {
        scanf("%d", &c);
        cnt[i][c] = 1;
    }

    vector<pii> queries;
    q += n - 1;
    for (int i = 0, qq, vv; i < q; ++i) {
        scanf("%d %d", &qq, &vv);
        queries.push_back({qq, vv});
        if (qq == 1) v[vv] = 1;
    }
    for (int i = 2; i <= n; ++i) if (!v[i]) _union(i, e[i]);

    vector<int> ans;
    while (!queries.empty()) {
        pii query = queries.back(); queries.pop_back();
        if (query.X == 1) _union(query.Y, e[query.Y]);
        else ans.push_back(cnt[_find(query.Y)].size());
    }
    while (!ans.empty()) {
        printf("%d\n", ans.back());
        ans.pop_back();
    }

    close();
    return 0;
}
