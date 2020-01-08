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

int n, m, p, sp, dist[5005];
vector <pii> edges[5005];

void dijkstra(int src) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        int node = pq.top().Y;
        int distance = pq.top().X;
        pq.pop();

        if (distance > dist[node]) continue;

        for (pii edge : edges[node]) {
            if (dist[edge.X] > edge.Y + distance) {
                dist[edge.X] = edge.Y + distance;
                pq.push({dist[edge.X], edge.X});
            }
        }
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    dijkstra(p); 
    sp = dist[n];
    dijkstra(1);
    if (dist[p] + sp == dist[n]) puts("SAVE HIM");
    else puts("GOOD BYE");

    close();
    return 0;
}
