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

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, e, w, pa, cnt, nodes[SZ][2], tree[SZ << 1], lazy[SZ << 1];
vector<int> edges[SZ];

void dfs(int node) {
    nodes[node][0] = ++cnt;
    for (int next: edges[node]) dfs(next);
    nodes[node][1] = cnt;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        } else tree[node] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int diff) {
    update_lazy(node, start, end);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] += diff;
        update_lazy(node, start, end);
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, end, left, right, diff);
}

int query(int node, int start, int end, int idx) {
    update_lazy(node, start, end);
    if (end < idx || idx < start) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, idx) + query(node * 2 + 1, mid + 1, end, idx);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &pa);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &pa);
        edges[pa].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &e, &w);
        update(1, 1, n, nodes[e][0], nodes[e][1], w);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", query(1, 1, n, nodes[i][0])); puts("");

    close();
    return 0;
}
