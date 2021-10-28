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

const int MAX = 3e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Query {
    int c, s, e, idx, ans;
    Query(int _c, int _s, int _e, int _i): c(_c), s(_s), e(_e), idx(_i), ans(-1) {}
};

int n, q, d[MAX][MAX];
vector<Query> queries;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", d[i] + j);
            if (!d[i][j] && i != j) d[i][j] = INF;
        }
    }
    for (int i = 1, c, s, e; i <= q; i++) {
        scanf("%d %d %d", &c, &s, &e);
        queries.emplace_back(c, s, e, i);
    }
    sort(queries.begin(), queries.end(), [](Query &a, Query &b) {
        return a.c < b.c;
    });

    int idx = 0;
    while (idx < q && queries[idx].c == 1) {
        Query &qu = queries[idx++];
        if (d[qu.s][qu.e] == INF) qu.ans = -1;
        else qu.ans = d[qu.s][qu.e];
    }

    for (int c = 1; c <= n; c++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][c] == INF || d[c][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][c] + d[c][j]);
            }
        }
        while (idx < q && queries[idx].c == c + 1) {
            Query &qu = queries[idx++];
            if (d[qu.s][qu.e] == INF) qu.ans = -1;
            else qu.ans = d[qu.s][qu.e];
        }
    }

    sort(queries.begin(), queries.end(), [](Query &a, Query &b) {
        return a.idx < b.idx;
    });

    for (Query &qu: queries) printf("%d\n", qu.ans);

    close();
    return 0;
}