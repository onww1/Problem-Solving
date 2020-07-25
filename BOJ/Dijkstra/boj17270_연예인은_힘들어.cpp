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

const int MAX = 1e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, s, e, dist[2][MAX];
vector<pii> edges[MAX];

void dijkstra(int src, int k) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[k][src] = 0;
    pq.push({dist[k][src], src});
    while (!pq.empty()) {
        int cost = pq.top().X;
        int node = pq.top().Y;
        pq.pop();

        if (cost > dist[k][node]) continue;

        for (pii &edge : edges[node]) {
            if (dist[k][edge.X] > cost + edge.Y) {
                dist[k][edge.X] = cost + edge.Y;
                pq.push({dist[k][edge.X], edge.X});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    scanf("%d %d", &s, &e);
    memset(dist, 0x3f, sizeof(dist));
    dijkstra(s, 0);
    dijkstra(e, 1);

    int mn = INF, mn_s = INF, ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (i == s || i == e) continue;
        if (dist[0][i] + dist[1][i] < mn) {
            mn = dist[0][i] + dist[1][i];
            mn_s = INF;
            ans = -1;
        }
        if (dist[0][i] + dist[1][i] == mn) {
            if (dist[0][i] <= dist[1][i]) {
                if (dist[0][i] < mn_s) {
                    mn_s = dist[0][i];
                    ans = i;
                }
            }    
        }
    }
    printf("%d\n", ans);

    close();
    return 0;
}
