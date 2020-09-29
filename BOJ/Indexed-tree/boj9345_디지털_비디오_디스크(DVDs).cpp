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

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, n, k, a[SZ];
pii tree[SZ << 1];

void init(int v, int s, int e) {
    if (s == e) {
        tree[v] = {a[s], a[s]};
        return;
    }
    int mid = (s + e) >> 1;
    init(v << 1, s, mid);
    init(v << 1 | 1, mid + 1, e);
    tree[v] = {min(tree[v << 1].X, tree[v << 1 | 1].X), max(tree[v << 1].Y, tree[v << 1 | 1].Y)};
}

void update(int v, int s, int e, int p) {
    if (e < p || p < s) return;
    if (s == e) {
        tree[v] = {a[p], a[p]};
        return;
    }
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, p);
    update(v << 1 | 1, mid + 1, e, p);
    tree[v] = {min(tree[v << 1].X, tree[v << 1 | 1].X), max(tree[v << 1].Y, tree[v << 1 | 1].Y)};
}

pii query(int v, int s, int e, int l, int r) {
    if (e < l || r < s) return {INF, -INF};
    if (l <= s && e <= r) return tree[v];
    int mid = (s + e) >> 1;
    pii lo = query(v << 1, s, mid, l, r);
    pii hi = query(v << 1 | 1, mid + 1, e, l, r);
    return {min(lo.X, hi.X), max(lo.Y, hi.Y)};
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) a[i] = i;
        init(1, 0, n - 1);
        for (int i = 0, q, x, y; i < k; ++i) {
            scanf("%d %d %d", &q, &x, &y);
            if (q) {
                pii res = query(1, 0, n - 1, x, y);
                puts(res.X == x && res.Y == y ? "YES" : "NO");
            } else {
                swap(a[x], a[y]);
                update(1, 0, n - 1, x);
                update(1, 0, n - 1, y);
            }
        }
    }

    close();
    return 0;
}
