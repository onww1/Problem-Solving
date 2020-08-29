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
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, q, k, c[MAX][3], dp[MAX][3][10];
vector<int> edges[MAX], pos[3];

void solve(int node, int pa) {
    for (int i = 0; i < 3; ++i) 
        dp[node][i][c[node][i] % k] = 1;
    for (int next: edges[node]) {
        if (next == pa) continue;
        solve(next, node);
        for (int color = 0; color < 3; ++color) {
            vector<int> tmp(k, 0);
            for (int i = 0; i < k; ++i) {
                if (!dp[node][color][i]) continue;
                for (int j = 0; j < k; ++j) {
                    int sum = 0;
                    for (int ncolor: pos[color]) 
                        sum = (sum + dp[next][ncolor][j]) % q;
                    tmp[(i + j) % k] += dp[node][color][i] * sum;
                    tmp[(i + j) % k] %= q;
                }
            }
            for (int i = 0; i < k; ++i) dp[node][color][i] = tmp[i];
        }
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &q, &k);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) 
        scanf("%d %d %d", c[i], c[i] + 1, c[i] + 2);
    pos[0] = {0, 1}; pos[1] = {0, 2}; pos[2] = {1};

    solve(1, 0);

    int ans = 0;
    for (int i = 0; i < 3; ++i) ans = (ans + dp[1][i][0]) % q;
    printf("%d\n", ans);

    close();
    return 0;
}
