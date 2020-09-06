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

struct SCC_Kosaraju {
    int size, scc_count;
    vector<vector<int>> edges, redges, scc;
    vector<int> _stack, visit, group;

    void init(int _size) {
        this->size = _size;
        scc_count = 0;
        edges.clear(); redges.clear(); scc.clear();
        _stack.clear(); visit.clear(); group.clear();
        edges.resize(this->size + 1);
        redges.resize(this->size + 1);
        visit.resize(this->size + 1, 0);
        group.resize(this->size + 1, -1);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        redges[v].push_back(u);
    }

    void dfs(int node) {
        visit[node] = 1;
        for (int next: edges[node]) 
            if (!visit[next])
                dfs(next);
        _stack.push_back(node);
    }

    void rdfs(int node, int group_number) {
        visit[node] = 0;
        group[node] = group_number;
        scc[group_number].push_back(node);
        for (int next: redges[node])
            if (visit[next])
                rdfs(next, group_number);
    }

    void strongly_connected_component() {
        for (int node = 1; node <= this->size; ++node) 
            if (!visit[node])
                dfs(node);
        while (!_stack.empty()) {
            int node = _stack.back();
            _stack.pop_back();
            if (visit[node]) {
                scc.push_back(vector<int>());
                rdfs(node, scc_count++);
            }
        }
    }
} SCC;

int n, m;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    SCC.init(n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        SCC.add_edge(x, i);
    }
    SCC.strongly_connected_component();

    auto& scc = SCC.scc;
    auto& group = SCC.group;
    vector<int> in(SCC.scc_count, 0);
    for (int i = 0; i < SCC.scc_count; ++i)
        for (int node: scc[i])
            for (int next: SCC.edges[node])
                if (group[node] != group[next])
                    in[group[next]]++;

    vector<int> count(SCC.scc_count, 0);
    vector<bool> dp(m + 1, false); dp[0] = true;
    
    queue<int> q;
    for (int i = 0; i < SCC.scc_count; ++i)
        if (!in[i])
            q.push(i);

    while (!q.empty()) {
        int grp = q.front(); q.pop();
        int num = scc[grp].size();
        for (int i = m - num; i >= count[grp]; --i)
            if (dp[i])
                dp[i + num] = true;
        for (int node: scc[grp])
            for (int next: SCC.edges[node]) 
                if (group[node] != group[next]) {
                    if (--in[group[next]] == 0) {
                        q.push(group[next]);
                        count[group[next]] += count[grp] + num;
                    }
                }
    }
    
    for (int i = m; i >= 0; --i)
        if (dp[i]) {
            printf("%d\n", i);
            break;
        }

    close();
    return 0;
}
