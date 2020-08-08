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

int n, a[3], dp[61][61][61];

int solve(int a, int b, int c) {
    if (a <= 0 && b <= 0 && c <= 0) return 0;


    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    dp[a][b][c] = INF;

    int p[3] = {1, 3, 9};
    do {
        ret = min(ret, solve(max(a - p[0], 0), max(b - p[1], 0), max(c - p[2], 0)) + 1);
    } while (next_permutation(p, p + 3));
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(a[0], n > 1 ? a[1] : 0, n > 2 ? a[2] : 0));

    close();
    return 0;
}
