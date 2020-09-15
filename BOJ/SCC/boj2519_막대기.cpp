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

struct Geometry {
    struct Point {
        int x, y;
        Point(): Point(0, 0){}
        Point(int _x, int _y): x(_x), y(_y){}
    };

    struct Line {
        Point p, q;
        Line(){}
        Line(Point _p, Point _q): p(_p), q(_q){}
    };

    int ccw(Point a, Point b, Point c) {
        ll res = 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x);
        if (res > 0)  // CCW
            return 1; 
        else if (res < 0)  // CW
            return -1; 
        else  // Line
            return 0; 
    }

    bool is_intersect(Line a, Line b) {
        int scope_a = ccw(a.p, a.q, b.p) * ccw(a.p, a.q, b.q);
        int scope_b = ccw(b.p, b.q, a.p) * ccw(b.p, b.q, a.q);
        if (scope_a > 0 || scope_b > 0) return false;
        if (min(a.p.x, a.q.x) > max(b.p.x, b.q.x) || min(b.p.x, b.q.x) > max(a.p.x, a.q.x) ||
            min(a.p.y, a.q.y) > max(b.p.y, a.q.y) || min(b.p.y, b.q.y) > max(a.p.y, a.q.y))
            return false;
        return true;
    }
} GP;

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

int n, m;
vector<Geometry::Line> lines;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n); 
    m = 3 * n;
    SCC.init(2 * m);
    lines.emplace_back(Geometry::Point(), Geometry::Point());
    for (int i = 1, ax, ay, bx, by; i <= m; ++i) {
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        lines.emplace_back(Geometry::Point(ax, ay), Geometry::Point(bx, by));
        for (int j = 1; j < i; ++j) {
            if (GP.is_intersect(lines[i], lines[j])) {
                SCC.add_edge(i, j + m);
                SCC.add_edge(j, i + m);
            }
        }
    }
    for (int i = 1; i <= m; i += 3) {
        SCC.add_edge(i + m, i + 1);
        SCC.add_edge(i + m, i + 2);
        SCC.add_edge(i + 1 + m, i);
        SCC.add_edge(i + 1 + m, i + 2);
        SCC.add_edge(i + 2 + m, i);
        SCC.add_edge(i + 2 + m, i + 1);
    }
    SCC.strongly_connected_component();

    bool valid = true;
    for (int i = 1; i <= m; ++i) 
        if (SCC.group[i] == SCC.group[i + m])
            valid = false;

    if (!valid) return !printf("-1\n");

    vector<int> ans;
    for (int i = 1; i <= m; i += 3) {
        int cnt = 0, p = -1;
        for (int j = 0; j < 3; ++j) {
            if (SCC.group[i + j] > SCC.group[i + j + m]) {
                cnt++;
                p = i + j;
            }
        }
        if (cnt > 1) return !printf("-1\n");
        if (p != -1) ans.push_back(p);
    }

    printf("%lu\n", ans.size());
    if (!ans.empty()) {
        for (int node: ans) 
            printf("%d ", node); 
        puts("");
    }

    close();
    return 0;
}
