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

const int MAX = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {0, 1, 1, -1, 0, 1};
const int move_c[] = {1, 1, 0, 1, 1, 0};

int n, m, k, dp[MAX][MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0, r, c; i < k; i++) {
        scanf("%d %d", &r, &c);
        dp[r][c] = -1;
    }
    dp[1][1] = 1;

    for (int c = 1, offset = 3; c <= m; c++, offset = 3 - offset) {
        for (int r = 1; r <= n; r++) {
            if (dp[r][c] == -1) continue;
            for (int d = 0; d < 3; d++) {
                int dr = r + move_r[offset + d];
                int dc = c + move_c[offset + d];
                if (dr <= 0 || dr > n || dc <= 0 || dc > m || dp[dr][dc] == -1) continue;
                dp[dr][dc] += dp[r][c];
                if (dp[dr][dc] >= MOD) dp[dr][dc] -= MOD;
            }
        }
    }

    printf("%d\n", dp[n][m]);

    close();
    return 0;
}