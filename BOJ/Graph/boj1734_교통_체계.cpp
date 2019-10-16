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

int n, m, q, qq, aa, bb, cc, dd, order, ap_dis[MAX], ae_dis[MAX];
vector <int> edges[MAX];
vector <pii> ap[MAX];
map <pii, pii> ae;

int articulation_point(int node) {
    ap_dis[node] = ++order;
    int low = order, cnt = 0; 
    for (int next : edges[node]) {
        if (ap_dis[next]) low = min(low, ap_dis[next]);
        else {
            ++cnt;
            int call_dis = order;
            int val = articulation_point(next);
            if (ap_dis[node] <= val) 
                ap[node].push_back({call_dis + 1, order});
            low = min(low, val);
        }
    }
    if (node == 1 && cnt < 2) ap[node].clear();
    return low; 
}

int articulation_edge(int node, int parent) {
    ae_dis[node] = ++order;
    int low = order;
    for (int next : edges[node]) {
        if (next == parent) continue;
        if (ae_dis[next]) low = min(low, ae_dis[next]);
        else {
            int call_dis = order;
            int val = articulation_edge(next, node);
            if (ae_dis[node] < val)
                ae[pii(min(next,node), max(next,node))] = { call_dis + 1, order };
            low = min(low, val);
        }
    }
    return low;
}

bool isIn(pii &p, int v) {
    return p.X <= v && v <= p.Y;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    order = 0; articulation_point(1);
    order = 0; articulation_edge(1, 0);

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &qq);
        if (qq == 1) {
            scanf("%d %d %d %d", &aa, &bb, &cc, &dd);
            if (cc > dd) swap(cc, dd);
            pii &p = ae[pii(cc, dd)];
            if (p.X && (isIn(p, ae_dis[aa]) ^ isIn(p, ae_dis[bb]))) puts("no");
            else puts("yes");
        } else {
            scanf("%d %d %d", &aa, &bb, &cc);
            bool flag = false;
            for (pii &p : ap[cc]) 
                if (isIn(p, ap_dis[aa]) ^ isIn(p, ap_dis[bb]))
                    flag = true;

            if (!ap[cc].empty() && flag) puts("no");
            else puts("yes");
        }
    }

    close();
    return 0;
}