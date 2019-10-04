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

int n, m, pa[MAX], cnt[MAX];
vector <ti3> edges;

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

ll _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        ll ret = 1LL * cnt[u] * cnt[v];
        cnt[v] += cnt[u];
        return ret;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) pa[i] = -1, cnt[i] = 1;

    ll sum = 0, ans = 0;
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({w, u, v});
        sum += w;
    }
    sort(edges.begin(), edges.end(), greater<ti3>());

    for (int i = 0, u, v, w; i < edges.size(); ++i) {
        tie(w, u, v) = edges[i];
        ans = (ans + sum * _union(u, v)) % 1000000000;
        sum -= w;
    }

    printf("%lld\n", ans);

    close();
    return 0;
}