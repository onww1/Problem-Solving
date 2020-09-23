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

int n, m, mx, dp[2001][2001];
char s[2005], t[2005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (s[i] == 'I' || t[j] == 'I') dp[i][j] = 1;
            if (i > 1 && s[i] == 'I' && s[i - 1] == 'O' && dp[i - 2][j]) dp[i][j] = max(dp[i][j], dp[i - 2][j] + 2);
            if (j > 1 && t[j] == 'I' && t[j - 1] == 'O' && dp[i][j - 2]) dp[i][j] = max(dp[i][j], dp[i][j - 2] + 2);
            if (i > 0 && j > 0 && s[i] != t[j] && dp[i - 1][j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            mx = max(mx, dp[i][j]);
        }
    }
    printf("%d\n", mx);

    close();
    return 0;
}
