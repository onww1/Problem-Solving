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

const int MAX = 5e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct BCC {
    int size, group_count, bcc_count, visit_count;
    vector<vector<pii>> edges;
    vector<vector<piii>> bcc;
    vector<piii> _stack;
    vector<int> visit;

    void init(int _size) {
        size = _size;
        group_count = bcc_count = visit_count = 0;
        edges.clear(); bcc.clear(); _stack.clear(); visit.clear(); 
        edges.resize(size + 1);
        visit.resize(size + 1, 0);
    }

    void add_edge(int u, int v, int w) {
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    int dfs(int node, int parent) {
        int low = visit[node] = ++visit_count;
        for (pii &edge: edges[node]) {
            int next = edge.X;
            if (next == parent) continue;
            if (visit[node] > visit[next]) _stack.push_back({edge.Y, {node, next}});
            if (visit[next]) low = min(low, visit[next]);
            else {
                int ret = dfs(next, node);
                low = min(low, ret);
                if (visit[node] <= ret) {
                    piii current_edge = {edge.Y, {node, next}};
                    bcc.push_back(vector<piii>());
                    while (!_stack.empty() && _stack.back() != current_edge) {
                        bcc[bcc_count].push_back(_stack.back());
                        _stack.pop_back();
                    }
                    bcc[bcc_count++].push_back(_stack.back());
                    _stack.pop_back();
                }
            }
        }
        return low;
    }

    void biconnected_component() {
        for (int node = 1; node <= size; ++node) 
            if (!visit[node]) {
                group_count++;
                dfs(node, node);
            }
    }
} BCC;

int n, m, cnt, sum, pa[MAX];
vector<pii> edges[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (u != v) {
        pa[v] = u;
        return true;
    }
    return false;
}

bool dfs(int node, int parent, int dst, int v) {
    if (node == dst) return true;
    for (pii &edge: edges[node]) {
        if (edge.X == parent) continue;
        if (dfs(edge.X, node, dst, v)) {
            if (edge.Y == v) {
                cnt--;
                sum -= v;
                edge.Y = 0;
                for (pii &te: edges[edge.X])
                    if (te.X == node) {
                        te.Y = 0;
                        break;
                    }
            }
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    BCC.init(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        BCC.add_edge(u, v, w);
    }
    BCC.biconnected_component();
    
    for (int i = 1; i <= n; ++i) pa[i] = i;
    
    for (int i = 0; i < BCC.bcc_count; ++i) {
        sort(BCC.bcc[i].begin(), BCC.bcc[i].end());
        for (int i = 1; i <= n; ++i) edges[i].clear();
        for (piii &e: BCC.bcc[i]) {
            if (_union(e.Y.X, e.Y.Y)) {
                cnt++;
                sum += e.X;
                edges[e.Y.X].push_back({e.Y.Y, e.X});
                edges[e.Y.Y].push_back({e.Y.X, e.X});
            } else dfs(e.Y.X, e.Y.X, e.Y.Y, e.X);
        }
    }
    printf("%d %d\n", cnt, sum);

    close();
    return 0;
}
