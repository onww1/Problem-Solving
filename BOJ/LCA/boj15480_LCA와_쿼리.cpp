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

const int BS = 1 << 17;
char buf[BS];

inline char read() {
    static int idx = BS;
    if (idx == BS) {
        int nidx = fread(buf, 1, BS, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return buf[idx++];
}

inline int readInt() {
    int sum = 0, minus = 0;
    char now = read();
    while (now == ' ' || now == '\n') now = read();
    if (now == '-') minus = 1, now = read();
    while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
    return minus ? -sum : sum;
}

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, pa[17][MAX], depth[MAX];
vector <int> edges[MAX];

void init(int node, int parent) {
    pa[0][node] = parent;
    depth[node] = depth[parent] + 1;

    for (int i = 1; i < 17; ++i)
        pa[i][node] = pa[i - 1][pa[i - 1][node]];

    for (int next : edges[node])
        if (next != parent)
            init(next, node);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = 16; i >= 0; --i)
        if (depth[pa[i][u]] >= depth[v])
            u = pa[i][u];

    if (u == v) return u;

    for (int i = 16; i >= 0; --i)
        if (pa[i][u] != pa[i][v])
            u = pa[i][u], v = pa[i][v];

    return pa[0][u];
}

int main(int argc, char *argv[]) {
    open();

    n = readInt();
    for (int i = 1, u, v; i < n; ++i) {
        u = readInt(), v = readInt();
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    init(1, 0);

    m = readInt();
    for (int i = 0, r, u, v; i < m; ++i) {
        r = readInt();
        u = readInt();
        v = readInt();
        int lcau = lca(r, u);
        int lcav = lca(r, v);
        if (lcau == lcav) 
            printf("%d\n", lca(u, v));
        else if (min(lcau, lcav) > 1) 
            printf("%d\n", lcau + lcav - lca(lcau, lcav));
        else 
            printf("%d\n", max(lcav, lcau));
    }

    close();
    return 0;
}