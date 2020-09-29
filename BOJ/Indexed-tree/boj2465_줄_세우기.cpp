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

int n, sz, a[SZ], p[SZ], tree[SZ << 1];

void update(int x, int k) {
    x += sz;
    while (x) {
        tree[x] += k;
        x >>= 1;
    }
}

int kth(int k) {
    int x = 1;
    while (x < sz) {
        if (tree[x << 1] < k) {
            k -= tree[x << 1];
            x = x << 1 | 1;
        } else x <<= 1;
    }
    return x - sz;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    sz = 1; while (sz < n) sz <<= 1;
    for (int i = 0; i < n; ++i) tree[i + sz] = 1;
    for (int i = sz - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0; i < n; ++i) scanf("%d", p + i);
    for (int i = n - 1; i >= 0; --i) {
        int idx = kth(p[i] + 1);
        p[i] = a[idx];
        update(idx, -1);
    }
    for (int i = 0; i < n; ++i) printf("%d\n", p[i]);

    close();
    return 0;
}
