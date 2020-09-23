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

const int TMAX = 1e4 + 1;
const int MAX = 1e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, t, m, l, dist[MAX][TMAX];
vector<piii> edges[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &t, &m, &l);
    for (int i = 0, u, v, tt, bb; i < l; ++i) {
        scanf("%d %d %d %d", &u, &v, &tt, &bb);
        edges[u].push_back({v, {tt, bb}});
        edges[v].push_back({u, {tt, bb}});
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dist[1][0] = 0; pq.push({dist[1][0], {1, 0}});
    while (!pq.empty()) {
        int cost = pq.top().X;
        int node = pq.top().Y.X;
        int tt = pq.top().Y.Y;
        pq.pop();

        if (dist[node][tt] != cost) continue;
        if (cost > m) break;
        if (node == n) return !printf("%d\n", cost);

        for (piii &edge: edges[node]) {
            if (tt + edge.Y.X <= t && dist[edge.X][tt + edge.Y.X] > cost + edge.Y.Y) {
                dist[edge.X][tt + edge.Y.X] = cost + edge.Y.Y;
                pq.push({dist[edge.X][tt + edge.Y.X], {edge.X, tt + edge.Y.X}});
            }
        }
    }
    printf("-1\n");

    close();
    return 0;
}
