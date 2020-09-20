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

int s, n, k, d, r1, r2, c1, c2;
char ans[55][55];

bool isValid(int lr, int lc, int rr, int rc) {
    return !(lr > r2 || rr < r1 || lc > c2 || rc < c1);
}

void solve(int r, int c, int sz) {
    if (sz == 1) return;
    int padding = sz / n * d;
    int lr = r + padding, rr = r + sz - padding - 1;
    int lc = c + padding, rc = c + sz - padding - 1;
    if (isValid(lr, lc, rr, rc)) {
        int lor = max(lr, r1), loc = max(lc, c1);
        int hir = min(rr, r2), hic = min(rc, c2);
        for (int i = lor; i <= hir; ++i)
            for (int j = loc; j <= hic; ++j)
                ans[i - r1][j - c1] = '1';
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i >= d && i < n - d && j >= d && j < n - d) continue;
            if (isValid(r + sz / n * i, c + sz / n * j, r + sz / n * (i + 1), c + sz / n * (j + 1)))
                solve(r + sz / n * i, c + sz / n * j, sz / n);
        }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
    r1++; r2++; c1++; c2++;
    d = (n - k) >> 1;
    int len = 1;
    for (int i = 0; i < s; ++i) len *= n;
    for (int i = 0; i <= r2 - r1; ++i)
        for (int j = 0; j <= c2 - c1; ++j)
            ans[i][j] = '0';
    solve(1, 1, len);
    for (int i = 0; i <= r2 - r1; ++i)
        printf("%s\n", ans[i]);

    close();
    return 0;
}
