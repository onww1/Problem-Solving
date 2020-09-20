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

const int MAX = 1025;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, pa[MAX];
vector<int> edges[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    pa[v] = u;
    return u != v;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 1, d; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &d);
            pq.push({d, {i, j}});
        }
    }
    for (int i = 1; i <= n; ++i) pa[i] = i;

    while (!pq.empty()) {
        piii cur = pq.top();
        pq.pop();
        if (_union(cur.Y.X, cur.Y.Y)) {
            edges[cur.Y.X].push_back(cur.Y.Y);
            edges[cur.Y.Y].push_back(cur.Y.X);
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%lu ", edges[i].size());
        sort(edges[i].begin(), edges[i].end());
        for (int node: edges[i]) printf("%d ", node);
        puts("");
    }

    close();
    return 0;
}
