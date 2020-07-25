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

int t, k, n, m, co, dist[MAX][MAX], cost[256];
char mp[MAX][MAX], cl;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &k, &m, &n);
        for (int i = 0; i < k; ++i) {
            scanf(" %c %d", &cl, &co);
            cost[cl] = co;
        }

        priority_queue<piii, vector<piii>, greater<piii>> pq;
        for (int i = 0; i < n; ++i) {
            scanf(" %s", mp[i]);
            for (int j = 0; j < m; ++j) {
                dist[i][j] = INF;
                if (mp[i][j] == 'E') {
                    dist[i][j] = 0;
                    pq.push({dist[i][j], {i, j}});
                }
            }
        }

        while (!pq.empty()) {
            int _cost = pq.top().X;
            int r = pq.top().Y.X;
            int c = pq.top().Y.Y;
            pq.pop();

            if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                printf("%d\n", _cost);
                break;
            }
            if (_cost > dist[r][c]) continue;
            for (int kk = 0; kk < 4; ++kk) {
                int dr = r + move_r[kk];
                int dc = c + move_c[kk];
                if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                if (dist[dr][dc] > _cost + cost[mp[dr][dc]]) {
                    dist[dr][dc] = _cost + cost[mp[dr][dc]];
                    pq.push({dist[dr][dc], {dr, dc}});
                }
            }
        }
    }

    close();
    return 0;
}
