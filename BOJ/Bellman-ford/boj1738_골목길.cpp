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

int n, m, dist[101], p[101], vv[101], reach[101];
vector <ti3> edgess;
vector <int> edges[101];

int dfs(int node) {
    vv[node] = 1;
    if (node == n) return reach[n] = 1;
    int &ret = reach[node];
    if (ret != -1) return ret;
    ret = 0;

    for (int next : edges[node]) {
        if (vv[next]) continue;
        ret = max(ret, dfs(next));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edgess.push_back({u, v, -w});
        edges[u].push_back(v);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0, u, v, w; j < edgess.size(); ++j) {
            tie(u, v, w) = edgess[j];
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                p[v] = u;
            }
        }
    }

    memset(reach, -1, sizeof(reach));
    dfs(1);

    bool valid = true;
    for (int j = 0, u, v, w; j < edgess.size(); ++j) {
        tie(u, v, w) = edgess[j];
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            p[v] = u;
            if (reach[v]) valid = false;
        }
    }

    if (!valid || dist[n] == INF) puts("-1");
    else {
        vector <int> ans; ans.push_back(n);
        while (1) {
            int pre = p[ans.back()];
            if (pre == 0) break;
            ans.push_back(pre);
        }
        while (!ans.empty()) {
            printf("%d ", ans.back());
            ans.pop_back();
        }
        puts("");
    }

    close();
    return 0;
}