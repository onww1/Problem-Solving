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

int n, m, dp[151][151], c[151];
vector<int> edges[151];

void dfs(int node, int pa) {
    c[node] = 1;
    dp[node][1] = 0;
    for (int next: edges[node]) {
        if (next == pa) continue;
        dfs(next, node);
        memset(dp[0], 0x3f, sizeof(dp[0]));
        for (int i = 1; i <= c[node]; ++i) {
            dp[0][i] = min(dp[0][i], dp[node][i] + 1);
            for (int j = 1; j <= c[next]; ++j)
                dp[0][i + j] = min(dp[0][i + j], dp[node][i] + dp[next][j]);
        }
        c[node] += c[next];
        for (int i = 1; i <= c[node]; ++i) dp[node][i] = dp[0][i];
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);

    int ans = dp[1][m];
    for (int i = 2; i <= n; ++i) if (c[i] >= m) ans = min(ans, dp[i][m] + 1);
    printf("%d\n", ans);

    close();
    return 0;
}
