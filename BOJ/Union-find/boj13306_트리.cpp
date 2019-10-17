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

struct Query {
    int x, y, z;
} qry[2 * MAX];

int n, q, p[MAX], pa[MAX];
bool ans[MAX];

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) pa[u] = v;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; ++i) scanf("%d", p + i);

    for (int i = 1 ; i < n + q; ++i) {
        scanf("%d %d", &qry[i].x, &qry[i].y);
        if (qry[i].x) scanf("%d", &qry[i].z);
    }

    memset(pa, -1, sizeof(pa));
    int idx = q;
    for (int i = n + q - 1; i > 0; --i) {
        if (qry[i].x) {
            ans[idx--] = (_find(qry[i].y) == _find(qry[i].z));
        } else {
            _union(qry[i].y, p[qry[i].y]);
        }
    }

    for (int i = 1; i <= q; ++i)
        puts(ans[i] ? "YES" : "NO");

    close();
    return 0;
}