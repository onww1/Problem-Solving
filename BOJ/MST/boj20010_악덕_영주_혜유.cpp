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

int n, m, di, pa[1001];
vector<pii> edges[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        return true;
    }
    return false;
}

int solve(int v, int p) {
    vector<int> d; d.push_back(0);
    for (pii &edge: edges[v]) {
        if (edge.X == p) continue;
        d.push_back(edge.Y + solve(edge.X, v));
    }
    sort(d.begin(), d.end(), greater<int>());
    if (d.size() > 1) di = max(di, d[0] + d[1]);
    di = max(di, d[0]);
    return d[0];
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) pa[i] = i;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        pq.push({w, {u, v}});
    } 

    int ans = 0;
    while (!pq.empty()) {
        int u = pq.top().Y.X;
        int v = pq.top().Y.Y;
        int w = pq.top().X;
        pq.pop();

        if (_union(u, v)) {
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
            ans += w;
        }
    }

    printf("%d\n", ans);
    solve(0, 0);
    printf("%d\n", di);

    close();
    return 0;
}
