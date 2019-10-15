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

int n, dp[MAX][3];

int main(int argc, char *argv[]) {
    open();

    for (int tc = 1; 1; ++tc) {
        scanf("%d", &n);
        if (!n) break;

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 3; ++j)
                scanf("%d", dp[i] + j);

        dp[1][2] += dp[1][1];
        dp[2][0] += dp[1][1];
        dp[2][1] += min({dp[1][1], dp[1][2], dp[2][0]});
        dp[2][2] += min({dp[1][1], dp[1][2], dp[2][1]});
        for (int i = 3; i <= n; ++i) {
            dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] += min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][2] += min({dp[i][1], dp[i - 1][1], dp[i - 1][2]});
        }
        printf("%d. %d\n", tc, dp[n][1]);
    }

    close();
    return 0;
}