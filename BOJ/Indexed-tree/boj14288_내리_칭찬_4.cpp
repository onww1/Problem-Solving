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

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, k, cnt, pa, tree[2][MAX], nodes[MAX][2];
vector<int> edges[MAX];

void dfs(int node) {
    nodes[node][0] = ++cnt;
    for (int next: edges[node]) dfs(next);
    nodes[node][1] = cnt;
}

void update(int v, int node, int val) {
    while (node < MAX) {
        tree[v][node] += val;
        node += node & -node;
    }
}

int sum(int v, int node) {
    int ret = 0;
    while (node) {
        ret += tree[v][node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &pa);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &pa);
        edges[pa].push_back(i);
    }
    dfs(1);
    for (int i = 0, q, x, y; i < m; ++i) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d %d", &x, &y);
            update(k, nodes[x][0], y);
            if (!k) update(k, nodes[x][1] + 1, -y);
        } else if (q == 2) {
            scanf("%d", &x);
            printf("%d\n", sum(0, nodes[x][0]) + sum(1, nodes[x][1]) - sum(1, nodes[x][0] - 1));
        } else {
            k = 1 - k;
        }
    }

    close();
    return 0;
}
