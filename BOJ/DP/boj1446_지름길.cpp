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
typedef pair <pii, int> piii;
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

int n, d, dp[MAX];
piii path[20];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%d %d %d", &path[i].X.X, &path[i].X.Y, &path[i].Y);
    sort(path, path + n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0, j = 0; i < d; ++i) {
        while (i == path[j].X.X) {
            if (path[j].X.Y <= d) dp[path[j].X.Y] = min(dp[path[j].X.Y], dp[i] + path[j].Y);
            j++;
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    printf("%d\n", dp[d]);

    close();
    return 0;
}
