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

int n, m, p[3], offset[3];
char c[3]; // R : 0, B : 1

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    SCC.init(2 * n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %c %d %c %d %c", p, c, p + 1, c + 1, p + 2, c + 2);
        for (int j = 0; j < 3; ++j) offset[j] = c[j] == 'B' ? n : 0;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                SCC.add_edge(p[j] + n - offset[j], p[k] + offset[k]);
            }
        }
    }
    SCC.strongly_connected_component();

    bool valid = true;
    for (int i = 1; i <= n; ++i)
        if (SCC.group[i] == SCC.group[i + n])
            valid = false;

    if (!valid) puts("-1");
    else {
        for (int i = 1; i <= n; ++i) 
            printf("%c", SCC.group[i] > SCC.group[i + n] ? 'R' : 'B');
        puts("");
    }

    close();
    return 0;
}
