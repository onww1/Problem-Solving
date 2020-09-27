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

struct Rank {
    int d[3], idx;
} dist[MAX];

int n, m, q, a[3], nope[MAX], tree[1 << 18];
vector <pii> edges[MAX];

void dijkstra(int src, int idx) {
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    dist[src].d[idx] = 0; pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().X;
        int cur = pq.top().Y;
        pq.pop();

        if (dist[cur].d[idx] < d) continue;

        for (pii edge : edges[cur]) 
            if (dist[edge.X].d[idx] > edge.Y + d) {
                dist[edge.X].d[idx] = edge.Y + d;
                pq.push({dist[edge.X].d[idx], edge.X});
            }
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || end < idx) return;
    if (start == end && start == idx) {
        tree[node] = min(tree[node], val);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return INF;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) scanf("%d", a + i);
    scanf("%d", &m);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i <= n; ++i) dist[i].idx = i;

    for (int i = 0; i < 3; ++i) {
        dijkstra(a[i], i);
        vector <int> v;
        for (int j = 1; j <= n; ++j) v.push_back(dist[j].d[i]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for (int j = 1; j <= n; ++j) 
            dist[j].d[i] = lower_bound(v.begin(), v.end(), dist[j].d[i]) - v.begin() + 1;
    }

    sort(dist + 1, dist + n + 1, [](const Rank& a, const Rank& b) { return a.d[0] < b.d[0]; });
    memset(tree, 0x3f, sizeof(tree));

    vector<pii> tmp;
    for (int i = 1; i <= n; ++i) {
        if (dist[i].d[0] != dist[i - 1].d[0]) {
            for (pii &p: tmp) update(1, 1, n, p.X, p.Y);
            tmp.clear();
        }
        int mn = query(1, 1, n, 1, dist[i].d[1] - 1);
        if (mn < dist[i].d[2]) nope[dist[i].idx] = 1;
        tmp.emplace_back(dist[i].d[1], dist[i].d[2]);
    }

    scanf("%d", &q);
    for (int i = 0, u; i < q; ++i) {
        scanf("%d", &u);
        puts(nope[u] ? "NO" : "YES");
    }

    close();
    return 0;
}