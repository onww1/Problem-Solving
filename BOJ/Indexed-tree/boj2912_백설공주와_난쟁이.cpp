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

const int SZ = 1 << 19;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, c, m, l, r, a[SZ];
vector<int> tree[SZ << 1];

void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while (i < a.size()) c.push_back(a[i++]);
    while (j < b.size()) c.push_back(b[j++]);
}

void init(int v, int s, int e) {
    if (s == e) {
        tree[v].push_back(a[s]);
        return;
    }
    int md = (s + e) >> 1;
    init(v * 2, s, md);
    init(v * 2 + 1, md + 1, e);
    merge(tree[v * 2], tree[v * 2 + 1], tree[v]);
}

int count(int v, int s, int e, int l, int r, int x) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
    int md = (s + e) >> 1;
    return count(v * 2, s, md, l, r, x) + count(v * 2 + 1, md + 1, e, l, r, x);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    init(1, 1, n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l, &r);
        int lo = 1, hi = c;
        while (lo <= hi) {
            int md = (lo + hi) >> 1;
            if (2 * count(1, 1, n, l, r, md) > r - l + 1) hi = md - 1;
            else lo = md + 1;
        }
        if (2 * (count(1, 1, n, l, r, lo) - count(1, 1, n, l, r, lo - 1)) > r - l + 1) 
            printf("yes %d\n", lo);
        else
            printf("no\n");
    }

    close();
    return 0;
}
