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

int n, m, cycle, v[51][51], dp[51][51];
char in[51][51];

int solve(int r, int c) {
    if (cycle) return -1;
    if (v[r][c] == 2) return dp[r][c];
    else if (v[r][c] == 1) {
        cycle = 1;
        return -1;
    }
    else {
        v[r][c] = 1; dp[r][c] = 1;
        int mul = in[r][c] - '0';
        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k] * mul;
            int dc = c + move_c[k] * mul;
            if (dr < 0 || dr >= n || dc < 0 || dc >= m || in[dr][dc] == 'H') continue;
            dp[r][c] = max(dp[r][c], solve(dr, dc) + 1);
        }
        v[r][c] = 2;
        if (cycle) return -1;
        return dp[r][c];
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf(" %s", in[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0));
    close();
    return 0;
}