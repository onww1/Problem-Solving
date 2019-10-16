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

int n, m, q, aa, bb, cc, a[SZ];
ll tree[2 * SZ], lazy[2 * SZ];

void init(int node = 1, int start = 1, int end = n) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node = 1, int start = 1, int end = n) {
    if (lazy[node]) {
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int left, int right, int val, int node = 1, int start = 1, int end = n) {
    update_lazy(node, start, end);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] += val;
        update_lazy(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update_range(left, right, val, node * 2, start, mid);
    update_range(left, right, val, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int idx, int node = 1, int start = 1, int end = n) {
    update_lazy(node, start, end);
    if (idx < start || end < idx) return 0;
    if (start == end && idx == start) return tree[node];
    int mid = (start + end) >> 1;
    return query(idx, node * 2, start, mid) + query(idx, node * 2 + 1, mid + 1, end);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    init();

    scanf("%d", &m);
    while (m--) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d %d %d", &aa, &bb, &cc);
            update_range(aa, bb, cc);
        } else {
            scanf("%d", &aa);
            printf("%lld\n", query(aa));
        }
    }

    close();
    return 0;
}