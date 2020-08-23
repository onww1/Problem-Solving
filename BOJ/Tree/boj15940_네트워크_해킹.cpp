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

const int MAX = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n;
ll lp[MAX][3][2], sd[MAX][2][2], pd[MAX], ans;
vector<pii> edges[MAX];

void dfs1(int node, int pa) {
    vector<pli> v, d;
    for (pii& edge: edges[node]) {
        if (edge.X == pa) continue;
        dfs1(edge.X, node);
        v.push_back({edge.Y + lp[edge.X][0][0], edge.X});
        d.push_back({max(sd[edge.X][0][0], lp[edge.X][0][0] + lp[edge.X][1][0]), edge.X});
    }
    sort(v.begin(), v.end(), greater<pli>());
    sort(d.begin(), d.end(), greater<pli>());
    for (int i = 0; i < v.size() && i < 3; ++i) {
        lp[node][i][0] = v[i].X;
        lp[node][i][1] = v[i].Y;
        if (i < 2) {
            sd[node][i][0] = d[i].X;
            sd[node][i][1] = d[i].Y;
        }
    }
    pd[node] = max(lp[node][0][0] + lp[node][1][0], sd[node][0][0]);
}

void dfs2(int node, int pa, ll r, ll rd) {
    for (pii& edge: edges[node]) {
        if (edge.X == pa) continue;
        ll dd = max(rd, r);
        if (edge.X == lp[node][0][1]) dd = max(dd, max(r + lp[node][1][0], lp[node][1][0] + lp[node][2][0]));
        else if (edge.X == lp[node][1][1]) dd = max(dd, max(r + lp[node][0][0], lp[node][0][0] + lp[node][2][0]));
        else dd = max(dd, max(r + lp[node][0][0], lp[node][0][0] + lp[node][1][0]));
        if (edge.X == sd[node][0][1]) dd = max(dd, sd[node][1][0]);
        else dd = max(dd, sd[node][0][0]);
        ans = max(ans, pd[edge.X] + edge.Y + dd);
        dfs2(edge.X, node, max(r, edge.X == lp[node][0][1] ? lp[node][1][0] : lp[node][0][0]) + edge.Y, dd);
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    dfs1(1, 0);
    dfs2(1, 0, 0, 0);
    printf("%lld\n", ans);

    close();
    return 0;
}
