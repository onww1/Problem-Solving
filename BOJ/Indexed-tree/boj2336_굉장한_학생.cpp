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

const int SZ = 1 << 19;
const int MAX = 5e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Rank {
    int a, b, c;
} ranks[SZ];

int n, tree[2 * SZ];

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || end < idx) return;
    if (start == end && start == idx) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) >> 1;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return INF;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, v; i <= n; ++i) { scanf("%d", &v); ranks[v].a = i; }
    for (int i = 1, v; i <= n; ++i) { scanf("%d", &v); ranks[v].b = i; }
    for (int i = 1, v; i <= n; ++i) { scanf("%d", &v); ranks[v].c = i; }
    sort(ranks + 1, ranks + n + 1, [](const Rank& a, const Rank& b) { return a.a < b.a; });
    memset(tree, 0x3f, sizeof(tree));

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int mn = query(1, 1, n, 1, ranks[i].b);
        if (mn >= ranks[i].c) ans++;
        update(1, 1, n, ranks[i].b, ranks[i].c);
    }

    printf("%d\n", ans);
    close();
    return 0;
}