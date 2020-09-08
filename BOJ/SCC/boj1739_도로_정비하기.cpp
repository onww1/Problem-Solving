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

struct SCC_Tarjan {
    int size, scc_count, visit_count;
    vector<vector<int>> edges, scc;
    vector<int> _stack, visit, group;

    void init(int _size) {
        this->size = _size;
        scc_count = visit_count = 0;
        edges.clear(); scc.clear();
        _stack.clear(); visit.clear(); group.clear();
        edges.resize(this->size + 1);
        visit.resize(this->size + 1, 0);
        group.resize(this->size + 1, -1);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }

    int dfs(int node) {
        visit[node] = ++visit_count;
        int low = visit[node];
        _stack.push_back(node);
        for (int next: edges[node]) {
            if (!visit[next]) 
                low = min(low, dfs(next));
            else if (group[next] == -1) 
                low = min(low, visit[next]);
        }
        if (low == visit[node]) {
            scc.push_back(vector<int>());
            while (!_stack.empty()) {
                int pop_node = _stack.back();
                _stack.pop_back();
                scc.back().push_back(pop_node);
                group[pop_node] = scc_count;
                if (node == pop_node) break;
            }
            scc_count++;
        }
        return low;
    }

    void strongly_connected_component() {
        for (int node = 1; node <= this->size; ++node) 
            if (!visit[node])
                dfs(node);
    }
} SCC;

int t, n, m, s, k;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        s = n + m;
        SCC.init(2 * s);
        for (int i = 0, lr, lc, rr, rc; i < k; ++i) {
            scanf("%d %d %d %d", &lr, &lc, &rr, &rc);
            int dr = rr - lr, dc = rc - lc;
            int roffset = dr > 0 ? m : 0;
            int coffset = dc > 0 ? n : 0;
            if (dr != 0) {
                SCC.add_edge(lc + roffset, rc + m - roffset);
                SCC.add_edge(rc + roffset, lc + m - roffset);
                if (dc != 0) {
                    SCC.add_edge(lc + roffset, lr + 2 * m + n - coffset);
                    SCC.add_edge(rc + roffset, rr + 2 * m + n - coffset);
                }
            }
            if (dc != 0) {
                SCC.add_edge(lr + 2 * m + coffset, rr + 2 * m + n - coffset);
                SCC.add_edge(rr + 2 * m + coffset, lr + 2 * m + n - coffset);
                if (dr != 0) {
                    SCC.add_edge(lr + 2 * m + coffset, lc + m - roffset);
                    SCC.add_edge(rr + 2 * m + coffset, rc + m - roffset);
                }
            }
        }
        SCC.strongly_connected_component();

        bool valid = true;
        for (int i = 1; i <= m; ++i)
            if (SCC.group[i] == SCC.group[i + m])
                valid = false;
        for (int i = 1; i <= n; ++i)
            if (SCC.group[2 * m + i] == SCC.group[2 * m + n + i])
                valid = false;

        puts(valid ? "Yes" : "No");
    }

    close();
    return 0;
}
