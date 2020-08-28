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

int n, r, c[MAX];
ll ans;
vector<pll> edges[MAX];

pll dfs(int node, int pa, ll cost) {
    if (edges[node].size() == 1) {
        c[node] = 1;
        return {cost * cost, cost};
    }
    ll sqs = 0, ns = 0;
    for (pll& edge: edges[node]) {
        if (edge.X == pa) continue;
        pll res = dfs(edge.X, node, edge.Y);
        c[node] += c[edge.X];
        ans -= c[edge.X] * res.X;
        sqs += res.X;
        ans += 2 * ns * res.Y;
        ns += res.Y;
    }
    ans += c[node] * sqs;
    sqs += 2 * ns * cost + c[node] * cost * cost;
    ns += c[node] * cost;
    return {sqs, ns};
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i) if (edges[i].size() > 1) { r = i; break; }
    dfs(r, 0, 0);
    printf("%lld\n", ans);

    close();
    return 0;
}


// (a+k)^2 + (b+k)^2 + (c+k)^2
// = a^2 + b^2 + c^2 + 2ak + 2bk + 2ck + 3k^2


// a^2 , b^2, c^2

// (a+b)^2 + (a+c)^2 + (b+c)^2 = 2 * (a^2 + b^2 + c^2) + 2 * (ab + bc + ca)
// (a+b+c)^2 = a^2 + b^2 + c^2 + 2ab + 2bc + 2ca

// a^2 , a / b^2 , b / c^2, c



// a^2 + b^2 + c^2, a + b + c / d^2 + e^2, d + e
// (a+d)^2 + (a+e)^2 + (b+d)^2 + (b+e)^2 + (c+d)^2 + (c+e)^2
// = 2 * (a^2 + b^2 + c^2) + 3 * (d^2 + e^2) + 2ad + 2ae + 2bd + 2be + 2cd + 2ce

