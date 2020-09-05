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

const int MAX = 1e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct BCC {
    int size, group_count, bcc_count, visit_count;
    vector<vector<int>> edges;
    vector<vector<pii>> bcc;
    vector<pii> _stack;
    vector<int> visit;

    void init(int _size) {
        size = _size;
        group_count = bcc_count = visit_count = 0;
        edges.clear(); bcc.clear(); _stack.clear(); visit.clear(); 
        edges.resize(size + 1);
        visit.resize(size + 1, 0);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int dfs(int node, int parent) {
        int low = visit[node] = ++visit_count;
        for (int next: edges[node]) {
            if (next == parent) continue;
            if (visit[node] > visit[next]) _stack.push_back({node, next});
            if (visit[next]) low = min(low, visit[next]);
            else {
                int ret = dfs(next, node);
                low = min(low, ret);
                if (visit[node] <= ret) {
                    pii current_edge = {node, next};
                    bcc.push_back(vector<pii>());
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

int n, m;

int main(int argc, char *argv[]) {
    open();

    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;
        BCC.init(n);
        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            BCC.add_edge(u + 1, v + 1);
        }
        BCC.biconnected_component();

        auto &bcc = BCC.bcc;
        int group_count = BCC.group_count, bcc_count = BCC.bcc_count;
        vector<int> group(n + 1, -1), connected(n + 1, 0);
        for (int i = 0; i < bcc_count; ++i) 
            for (pii &edge: bcc[i]) {
                if (group[edge.X] != i) connected[edge.X]++;
                if (group[edge.Y] != i) connected[edge.Y]++;
                group[edge.X] = group[edge.Y] = i;
            }
        
        int mx = 0;
        for (int i = 1; i <= n; ++i)
            mx = max(mx, connected[i]);
        
        printf("%d\n", group_count + mx - 1);
    }

    close();
    return 0;
}
