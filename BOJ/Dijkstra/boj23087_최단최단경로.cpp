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
const int MOD = 1e9 + 9;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct Data {
    ll v, d, p;
    Data(ll _v, ll _d, ll _p): v(_v), d(_d), p(_p) {}
    bool operator< (const Data &other) const {
        if (d == other.d) return d > other.d;
        return p > other.p;
    }
};

int n, m, x, y;
ll d[MAX], p[MAX], c[MAX];
vector<pii> edges[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].emplace_back(v, w);
    }

    memset(d, 0x3f, sizeof(d));
    d[x] = 0; c[x] = 1;
    priority_queue<Data> pq;
    pq.emplace(x, 0, 0);
    while (!pq.empty()) {
        Data cur = pq.top(); pq.pop();

        if (d[cur.v] != cur.d || p[cur.v] != cur.p) continue;
        
        for (pii &edge : edges[cur.v]) {
            if (d[edge.X] > edge.Y + cur.d || (d[edge.X] == edge.Y + cur.d && p[edge.X] > p[cur.v] + 1)) {
                d[edge.X] = edge.Y + cur.d;
                p[edge.X] = p[cur.v] + 1;
                c[edge.X] = c[cur.v];
                pq.emplace(edge.X, d[edge.X], p[edge.X]);
            } else if (d[edge.X] == edge.Y + cur.d && p[edge.X] == p[cur.v] + 1) {
                c[edge.X] = (c[edge.X] + c[cur.v]) % MOD;
            }
        }
    }

    if (d[y] == LL_INF) puts("-1");
    else printf("%lld\n%lld\n%lld\n", d[y], p[y], c[y]);

    close();
    return 0;
}