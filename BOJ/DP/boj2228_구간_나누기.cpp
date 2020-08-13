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

int n, m, mn, a[101], msum[101][101], dp[101][51];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        int mn = 0, ps = 0;
        for (int j = i; j <= n; ++j) {
            ps += a[j];
            msum[i][j] = max(i <= j - 1 ? msum[i][j - 1] : -INF, ps - mn);
            mn = min(mn, ps);
        }
    }
    
    for (int j = 1; j <= n; ++j) dp[j][1] = msum[1][j];
    for (int i = 1; i <= n; ++i) for (int j = 2; j <= m; ++j) dp[i][j] = -INF;
    for (int i = 2; i <= m; ++i) {
        for (int j = i * 2 - 1; j <= n; ++j) {
            for (int k = j; k <= n; ++k) {
                dp[k][i] = max(dp[k][i], dp[j - 2][i - 1] + msum[j][k]);
            }
        }
    }

    int ans = -INF;
    for (int i = 2 * m - 1; i <= n; ++i) ans = max(ans, dp[i][m]);
    printf("%d\n", ans);

    close();
    return 0;
}
