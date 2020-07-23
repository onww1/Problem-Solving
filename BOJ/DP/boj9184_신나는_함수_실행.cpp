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

int a, b, c, dp[21][21][21];

int solve(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) return 1;
    if (x > 20 || y > 20 || z > 20) x = y = z = 20;

    int& ret = dp[x][y][z];
    if (ret != INF) return ret;
    if (x < y && y < z) ret = solve(x, y, z - 1) + solve(x, y - 1, z - 1) - solve(x, y - 1, z);
    else ret = solve(x - 1, y, z) + solve(x - 1, y - 1, z) + solve(x - 1, y, z - 1) - solve(x - 1, y - 1, z - 1);
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    memset(dp, 0x3f, sizeof(dp));
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
    }

    close();
    return 0;
}
