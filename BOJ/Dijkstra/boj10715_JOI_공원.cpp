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

pli dist[MAX];
int n, m, c;
bool valid[MAX];
vector <pii> edges[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    for (int i = 1; i <= n; ++i) dist[i] = { LL_INF, i };
    priority_queue <pli, vector<pli>, greater<pli>> pq;
    dist[0].X = dist[1].X = 0; pq.push({dist[1].X, 1});

    while (!pq.empty()) {
        ll d = pq.top().X;
        int cur = pq.top().Y;
        pq.pop();

        if (d > dist[cur].X) continue;

        for (pii edge : edges[cur])
            if (dist[edge.X].X > d + edge.Y) {
                dist[edge.X].X = d + edge.Y;
                pq.push({ dist[edge.X].X, edge.X });
            }
    }

    sort(dist + 1, dist + n + 1);

    ll ans = c * dist[n].X, sum = 0;
    for (int i = n; i > 0; --i) {
        ll val = c * dist[i - 1].X;
        valid[dist[i].Y] = true;
        for (pii edge : edges[dist[i].Y])
            if (!valid[edge.X])
                sum += edge.Y;
        ans = min(ans, val + sum);
    }

    printf("%lld\n", ans);

    close();
    return 0;
}