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

int n, m, t, d, dist[25][25][25][25];
char mp[25][26];

void dijkstra(int sr, int sc) {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dist[sr][sc][sr][sc] = 0;
    pq.push({dist[sr][sc][sr][sc], {sr, sc}});
    while (!pq.empty()) {
        int cost = pq.top().X;
        int r = pq.top().Y.X;
        int c = pq.top().Y.Y;
        pq.pop();

        if (cost > dist[sr][sc][r][c]) continue;

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
            if (abs(mp[dr][dc] - mp[r][c]) <= t) {
                int cc = mp[dr][dc] > mp[r][c] ? (int)(mp[dr][dc] - mp[r][c]) * (mp[dr][dc] - mp[r][c]) : 1;
                if (dist[sr][sc][dr][dc] > cost + cc) {
                    dist[sr][sc][dr][dc] = cost + cc;
                    pq.push({dist[sr][sc][dr][dc], {dr, dc}});
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &m, &t, &d);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", mp[i]);
        for (int j = 0; j < m; ++j) {
            if ('a' <= mp[i][j] && mp[i][j] <= 'z') mp[i][j] -= 'a' - 26;
            else mp[i][j] -= 'A';
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dijkstra(i, j);

    int ans = mp[0][0];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (dist[0][0][i][j] + dist[i][j][0][0] <= d)
                ans = max(ans, (int)mp[i][j]);

    printf("%d\n", ans);

    close();
    return 0;
}
