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

const int MAX = 50 + 2;
const int MOD = 1e9 + 7;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int INF = 0x3f3f3f3f;
const int S = 100, T = 101;

struct Dinic {
    struct Edge {
        int v, c, f;
        Edge* op;
        Edge(): Edge(-1, 0){}
        Edge(int _v, int _c): v(_v), c(_c), f(0), op(nullptr){}
        int spare() { return c - f; }
        void addFlow(int flow) {
            f += flow;
            op->f -= flow;
        }
    };
    vector<Edge*> edges[T + 1];
    int level[T + 1], work[T + 1];

    void init() {
        for (int i = 0; i <= T; ++i) {
            for (auto &it: edges[i]) delete it;
            edges[i].clear();
        }
    }

    void addEdge(int u, int v, int c) {
        Edge* e1 = new Edge(v, c);
        Edge* e2 = new Edge(u, 0);
        e1->op = e2, e2->op = e1;
        edges[u].push_back(e1);
        edges[v].push_back(e2);
    }

    bool bfs() {
        memset(level, -1, sizeof(level));
        queue<int> q; q.push(S); level[S] = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto &it: edges[node]) {
                if (level[it->v] == -1 && it->spare()) {
                    level[it->v] = level[node] + 1;
                    q.push(it->v);
                }
            }
        }
        return level[T] != -1;
    }

    int dfs(int node, int flow) {
        if (node == T) return flow;
        for (int &i = work[node]; i < edges[node].size(); ++i) {
            Edge *e = edges[node][i];
            if (level[e->v] == level[node] + 1 && e->spare()) {
                int res = dfs(e->v, min(flow, e->spare()));
                if (res) {
                    e->addFlow(res);
                    return res;
                }
            }
        }
        return 0;
    }

    int maximumFlow() {
        int ret = 0, res;
        while (bfs()) {
            memset(work, 0, sizeof(work));
            while (res = dfs(S, INF)) ret += res;
        }
        return ret;
    }
} MF;

int n, tot, r[MAX], c[MAX];

int solve(int val) {
    MF.init();
    for (int i = 0; i < n; ++i) {
        MF.addEdge(S, i, r[i]);
        MF.addEdge(i + 50, T, c[i]);
        for (int j = 0; j < n; ++j) 
            MF.addEdge(i, j + 50, val);
    }
    return MF.maximumFlow();
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", r + i), tot += r[i];
    for (int i = 0; i < n; ++i) scanf("%d", c + i);

    int lo = 0, hi = 10000;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (solve(mid) == tot) hi = mid - 1;
        else lo = mid + 1;
    }

    printf("%d\n", lo);
    solve(lo);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", MF.edges[i][j + 1]->f);
        puts("");
    }

    close();
    return 0;
}
