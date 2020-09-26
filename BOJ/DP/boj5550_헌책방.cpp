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

int n, k, ci[11], c[11][2001], dp[11][2001];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &k);
    for (int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        c[b][++ci[b]] = a;
    }
    for (int i = 1; i <= 10; ++i) {
        sort(c[i] + 1, c[i] + n + 1, greater<int>());
        for (int j = 1; j <= n; ++j) c[i][j] += c[i][j - 1];
    }
    for (int j = 1; j <= ci[1]; ++j)
        dp[1][j] = c[1][j] + j * (j - 1);
    for (int i = 2; i <= 10; ++i) {
        for (int j = 1; j <= k; ++j) {
            int lim = min(ci[i], j);
            dp[i][j] = dp[i - 1][j];
            for (int l = 1; l <= lim; ++l) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + c[i][l] + l * (l - 1));
        }
    }
    printf("%d\n", dp[10][k]);

    close();
    return 0;
}

// dp[i][j] : i번째 장르까지 보았고, 전체 j개를 팔 때 최대 수익
// dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + psum[i][k] + extra)