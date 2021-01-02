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

const int MAX = 1e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, mx, ch[MAX], dp[MAX][142];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1, p; i <= m; i++) {
        scanf("%d", &p);
        ch[p] = 1;
    }

    mx = 1;
    while (mx * (mx + 1) <= 2 * n) mx++;
    mx--;

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;

    for (int i = 1; i < n; i++) {
        if (ch[i]) continue;
        for (int j = 0; j <= mx; j++) {
            if (dp[i][j] != INF) {
                for (int k = -1; k <= 1; k++) {
                    if (j + k > 0 && i + j + k <= n && !ch[i + j + k] && dp[i + j + k][j + k] > dp[i][j] + 1) {
                        dp[i + j + k][j + k] = dp[i][j] + 1;
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= mx; i++) ans = min(ans, dp[n][i]);
    printf("%d\n", ans == INF ? -1 : ans);

    close();
    return 0;
}
