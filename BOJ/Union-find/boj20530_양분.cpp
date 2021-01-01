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

int n, q, pa[MAX], cycle[MAX];
vector<int> edges[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) pa[u] = v;
}

int find_cycle(int node, int par) {
    cycle[node] = 1;
    for (int next: edges[node]) {
        if (next == par) continue;
        if (cycle[next]) return next;
        int res = find_cycle(next, node);
        if (res > 0) {
            if (res != node) return res;
            else return 0;
        }
    }
    cycle[node] = 0;
    return 0;
}

void dfs(int node, int par, int root) {
    _union(root, node);
    for (int next: edges[node]) 
        if (next != par && !cycle[next])
            dfs(next, node, root);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 1, u, v; i <= n; i++) {
        pa[i] = i;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    find_cycle(1, 0);
    for (int i = 1; i <= n; i++) {
        if (cycle[i]) {
            dfs(i, 0, i);
        }
    }

    int u, v;
    while (q--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", _find(u) == _find(v)? 1 : 2);
    }

    close();
    return 0;
}
