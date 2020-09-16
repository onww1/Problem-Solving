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

int n, m, a[SZ], tree[SZ << 1][2];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][a[start]] = 1;
        return;
    }
    int mid = (start + end) >> 1;
    init(node << 1, start, mid);
    init(node << 1 | 1, mid + 1, end);
    tree[node][0] = tree[node << 1][0] + tree[node << 1 | 1][0];
    tree[node][1] = tree[node << 1][1] + tree[node << 1 | 1][1];
}

void update(int node, int start, int end, int idx, int val) {
    if (end < idx || idx < start) return;
    if (start == end) {
        tree[node][val] = 1;
        tree[node][1 - val] = 0;
        return;
    }
    int mid = (start + end) >> 1;
    update(node << 1, start, mid, idx, val);
    update(node << 1 | 1, mid + 1, end, idx, val);
    tree[node][0] = tree[node << 1][0] + tree[node << 1 | 1][0];
    tree[node][1] = tree[node << 1][1] + tree[node << 1 | 1][1];
}

int query(int node, int start, int end, int left, int right, int p) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node][p];
    int mid = (start + end) >> 1;
    return query(node << 1, start, mid, left, right, p) + query(node << 1 | 1, mid + 1, end, left, right, p);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a[i] &= 1;
    }
    init(1, 1, n);
    scanf("%d", &m);
    for (int i = 1, q, l, r; i <= m; ++i) {
        scanf("%d %d %d", &q, &l, &r);
        if (q == 1) update(1, 1, n, l, r & 1);
        else printf("%d\n", query(1, 1, n, l, r, q & 1));
    }

    close();
    return 0;
}
