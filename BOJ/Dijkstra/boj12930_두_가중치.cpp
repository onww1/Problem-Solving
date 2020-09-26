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
typedef pair <pii, pii> pi4;
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

int n, dist[22];
char cost[2][22][22];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j) {
            scanf(" %s", cost[i][j]);
            for (int k = 0; k < n; ++k)
                cost[i][j][k] = cost[i][j][k] == '.' ? 0 : cost[i][j][k] - '0';
        }
    
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pi4, vector<pi4>, greater<pi4>> pq;
    dist[0] = 0; pq.push({{dist[0], 0}, {0, 0}});
    while (!pq.empty()) {
        pi4 cur = pq.top();
        pq.pop();

        if (dist[cur.X.Y] != cur.X.X) continue;

        for (int next = 0; next < n; ++next) {
            if (next == cur.X.Y || !cost[0][cur.X.Y][next]) continue;
            int c1 = cur.Y.X + cost[0][cur.X.Y][next];
            int c2 = cur.Y.Y + cost[1][cur.X.Y][next];
            if (dist[next] > c1 * c2) {
                dist[next] = c1 * c2;
                pq.push({{dist[next], next}, {c1, c2}});
            }
        }
    }
    printf("%d\n", dist[1] == INF ? -1 : dist[1]);

    close();
    return 0;
}
