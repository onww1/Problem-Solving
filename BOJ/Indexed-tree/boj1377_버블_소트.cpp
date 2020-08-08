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

int n, tree[SZ << 1];

void update(int v, int s, int e, int i) {
    if (e < i || i < s) return;
    if (s == e) {
        tree[v]++;
        return;
    }
    int m = (s + e) >> 1;
    update(v * 2, s, m, i);
    update(v * 2 + 1, m + 1, e, i);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int query(int v, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[v];
    int m = (s + e) >> 1;
    return query(v * 2, s, m, l, r) + query(v * 2 + 1, m + 1, e, l, r);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    int mx = 0;
    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        mx = max(mx, query(1, 1, SZ, a + 1, SZ));
        update(1, 1, SZ, a);
    }
    printf("%d\n", mx + 1);
    
    close();
    return 0;
}
