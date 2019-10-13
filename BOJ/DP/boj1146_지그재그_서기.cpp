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

ll dp[101][2], comb[101][101];
int n;

int main(int argc, char *argv[]) {
    open();

    for (int i = 0; i <= 100; ++i) comb[i][i] = comb[i][0] = 1;
    for (int i = 2; i <= 100; ++i) 
        for (int j = 1; j < i; ++j)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000;

    scanf("%d", &n);
    if (n == 1) return !printf("1\n");

    dp[0][0] = dp[0][1] = dp[1][1] = dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = j ? 2 : 1; k <= i; k += 2) {
                dp[i][j] = (dp[i][j] + dp[k - 1][k % 2] * dp[i - k][0] % 1000000 * comb[i - 1][k - 1] % 1000000) % 1000000;
            }
        }
    }
    
    printf("%lld\n", (dp[n][0] + dp[n][1]) % 1000000);

    close();
    return 0;
}