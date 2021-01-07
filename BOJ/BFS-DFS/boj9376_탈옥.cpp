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

const int MAX = 1e2 + 3;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, n, m, d[3][MAX][MAX];
char mp[MAX][MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int k = 0; k < 3; ++k) {
            for (int i = 0; i <= n + 1; ++i) 
                for (int j = 0; j <= m + 1; ++j) 
                    d[k][i][j] = INF;
        }
        deque<piii> dq; 
        dq.push_back({0, {0, 0}}); d[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf(" %s", mp[i] + 1);
            for (int j = 1; j <= m; ++j)
                if (mp[i][j] == '$') {
                    d[dq.size()][i][j] = 0;
                    dq.push_back({dq.size(), {i, j}});
                }
        }
        for (int j = 0; j <= m + 1; ++j) mp[0][j] = mp[n + 1][j] = 0;
        for (int i = 1; i <= n; ++i) mp[i][0] = mp[i][m + 1] = 0;
        
        while (!dq.empty()) {
            int p = dq.front().X;
            int r = dq.front().Y.X;
            int c = dq.front().Y.Y;
            dq.pop_front();

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr > n + 1 || dc < 0 || dc > m + 1 || d[p][dr][dc] != INF) continue;
                if (mp[dr][dc] != '*') {
                    if (mp[dr][dc] == '#') {
                        d[p][dr][dc] = d[p][r][c] + 1;
                        dq.push_back({p, {dr, dc}});
                    } else {
                        d[p][dr][dc] = d[p][r][c];
                        dq.push_front({p, {dr, dc}});
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= n + 1; ++i)
            for (int j = 0; j <= m + 1; ++j)
                if (mp[i][j] != '*')
                    ans = min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - (mp[i][j] == '#' ? 2 : 0));

        printf("%d\n", ans);
    }

    close();
    return 0;
}
