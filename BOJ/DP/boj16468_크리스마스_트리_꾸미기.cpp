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
const int MOD = 100030001;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, l, dp[301][301][2];

int solve(int h, int s, int k) {
    if (h == 1) return s == k;
    if (h < 9 && s >= (1 << h)) return 0;
    if (s == 0) return 1 - k;
    
    int& ret = dp[h][s][k];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < s; ++i) {
        if (k) {
            ret = (ret + 1LL * (solve(h - 1, i, 0) + solve(h - 1, i, 1)) * (solve(h - 1, s - 1 - i, 0) + solve(h - 1, s - 1 - i, 1))) % MOD;
            ret = (ret - 1LL * solve(h - 1, i, 0) * solve(h - 1, s - 1 - i, 0) + 1LL * MOD * MOD) % MOD;
        } else {
            ret = (ret + 1LL * solve(h - 1, i, 0) * solve(h - 1, s - 1 - i, 0)) % MOD;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &l);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(l, n, 1));

    close();
    return 0;
}
