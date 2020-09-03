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

int n, m, pa[2 * MAX], vis[2 * MAX], cnt[2 * MAX];
char c;

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u); v = _find(v);
    if (u < v) swap(u, v);
    if (u != v) {
        pa[u] = v;
        cnt[v] += cnt[u];
    }
}

void make_team(int u, int v) {
    _union(u, v);
    _union(u + n, v + n);
}

void make_enemy(int u, int v) {
    _union(u, v + n);
    _union(u + n, v);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 2 * n; ++i) pa[i] = i, cnt[i] = 1;
    for (int i = 0, u, v; i < m; ++i) {
        scanf(" %c %d %d", &c, &u, &v);
        if (c == 'S') make_team(u, v);
        else make_enemy(u, v);
    }

    for (int i = 1; i <= n; ++i) 
        if (_find(i) == _find(i + n)) 
            return !printf("0\n");

    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[_find(i)] && !vis[_find(i + n)]) {
            tot++;
            vis[_find(i + n)] = vis[_find(i)] = 1;
        }
    }

    printf("1");
    for (int i = 1; i <= tot; ++i) printf("0"); puts("");

    close();
    return 0;
}
