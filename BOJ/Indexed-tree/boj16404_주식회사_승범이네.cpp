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

int n, m, cc, x[MAX][2], tree[MAX];
vector<int> edges[MAX];

void numbering(int node) {
    x[node][0] = ++cc;
    for (int next: edges[node])
        numbering(next);
    x[node][1] = cc + 1;
}

void update(int node, int x) {
    while (node <= n) {
        tree[node] += x;
        node += node & -node;
    }
}

int sum(int node) {
    int ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %*d", &n, &m);
    for (int i = 2, p; i <= n; ++i) {
        scanf("%d", &p);
        edges[p].push_back(i);
    }
    numbering(1);
    for (int i = 0, q, p, w; i < m; ++i) {
        scanf("%d %d", &q, &p);
        if (q == 1) {
            scanf("%d", &w);
            update(x[p][0], w);
            update(x[p][1], -w);
        } else {
            printf("%d\n", sum(x[p][0]));
        }
    }

    close();
    return 0;
}
