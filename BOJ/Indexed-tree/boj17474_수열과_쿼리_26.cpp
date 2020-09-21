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

const int SZ = 1 << 20;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct node {
    ll mx, smx, cnt, sum;
    node(): node(0, 0, 0, 0){}
    node(ll _mx, ll _smx, ll _cnt, ll _sum): mx(_mx), smx(_smx), cnt(_cnt), sum(_sum){}
    node operator+ (const node &other) const {
        node ret;
        if (mx == other.mx) {
            ret.mx = mx;
            ret.smx = max(smx, other.smx);
            ret.cnt = cnt + other.cnt;
        } else if (mx < other.mx) {
            ret.mx = other.mx;
            ret.smx = max(mx, other.smx);
            ret.cnt = other.cnt;
        } else {
            ret.mx = mx;
            ret.smx = max(smx, other.mx);
            ret.cnt = cnt;
        }
        ret.sum = sum + other.sum;
        return ret;
    }
} tree[SZ << 1];

int n, m, q, l, r, x, a[SZ];

void init(int v, int s, int e) {
    if (s == e) {
        tree[v] = node(a[s], 0, 1, a[s]);
        return;
    }
    int mid = (s + e) >> 1;
    init(v << 1, s, mid);
    init(v << 1 | 1, mid + 1, e);
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

void update_lazy(int v, int s, int e) {
    if (s != e) {
        for (int nv: {v << 1, v << 1 | 1}) {
            if (tree[v].mx < tree[nv].mx) {
                tree[nv].sum -= (tree[nv].mx - tree[v].mx) * tree[nv].cnt;
                tree[nv].mx = tree[v].mx;
            }
        }
    }
}

void update(int v, int s, int e, int l, int r, int x) {
    update_lazy(v, s, e);
    if (e < l || r < s || tree[v].mx <= x) return;
    if (l <= s && e <= r && (tree[v].smx < x || s == e)) {
        tree[v].sum -= (tree[v].mx - x) * tree[v].cnt;
        tree[v].mx = x;
        update_lazy(v, s, e);
        return;
    }
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, l, r, x);
    update(v << 1 | 1, mid + 1, e, l, r, x);
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

pll query(int v, int s, int e, int l, int r) {
    update_lazy(v, s, e);
    if (e < l || r < s) return {0, 0};
    if (l <= s && e <= r) return {tree[v].mx, tree[v].sum};
    int mid = (s + e) >> 1;
    pll lo = query(v << 1, s, mid, l, r);
    pll hi = query(v << 1 | 1, mid + 1, e, l, r);
    return {max(lo.X, hi.X), lo.Y + hi.Y};
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    init(1, 1, n);

    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) {
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
        } else {
            pll res = query(1, 1, n, l, r);
            printf("%lld\n", q == 2 ? res.X : res.Y);
        }
    }

    close();
    return 0;
}
