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

const int SZ = 1 << 18;
const int MAX = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, k, cc, c[MAX], d[MAX][2], idx[MAX];
vector<int> edges[MAX];
vector<int> tree[SZ << 1];

int numbering(int node, int pa) {
    d[node][0] = ++cc;
    idx[cc] = node;
    for (int next: edges[node])
        if (next != pa)
            d[node][1] += numbering(next, node);
    return d[node][1] + 1;
}

void init(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(c[idx[start]]);
        return;
    }
    int mid = (start + end) >> 1;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    int l = 0, r = 0;
    while (l < tree[node * 2].size() && r < tree[node * 2 + 1].size()) {
        if (tree[node * 2][l] < tree[node * 2 + 1][r]) tree[node].push_back(tree[node * 2][l++]);
        else tree[node].push_back(tree[node * 2 + 1][r++]);
    }
    while (l < tree[node * 2].size()) tree[node].push_back(tree[node * 2][l++]);
    while (r < tree[node * 2 + 1].size()) tree[node].push_back(tree[node * 2 + 1][r++]);
}

int query(int node, int start, int end, int left, int right, int val) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) 
        return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right, val)
            + query(node * 2 + 1, mid + 1, end, left, right, val);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", c + i);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    numbering(1, 0);
    init(1, 1, n);

    int vn, cn, ans = 0;
    while (m--) {
        scanf("%d %d", &vn, &cn);
        ans = (ans + query(1, 1, n, d[vn][0], d[vn][0] + d[vn][1], cn)) % MOD;
    }
    printf("%d\n", ans);

    close();
    return 0;
}
