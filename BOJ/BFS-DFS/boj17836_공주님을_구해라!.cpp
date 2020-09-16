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

int n, m, t, d[101][101], mp[101][101];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d\n", &n, &m, &t);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        scanf("%d", mp[i] + j);
        d[i][j] = INF;
    }

    queue<pii> q; q.push({1, 1}); d[1][1] = 0;
    int ans = INF;

    while (!q.empty()) {
        int r = q.front().X;
        int c = q.front().Y;
        q.pop();

        if (mp[r][c] == 2) ans = min(ans, d[r][c] + n - r + m - c);
        
        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 1 || dr > n || dc < 1 || dc > m || mp[dr][dc] == 1 || d[dr][dc] != INF) continue;
            d[dr][dc] = d[r][c] + 1;
            q.push({dr, dc});
        }
    }

    ans = min(ans, d[n][m]);
    if (ans > t) puts("Fail");
    else printf("%d\n", ans);

    close();
    return 0;
}
