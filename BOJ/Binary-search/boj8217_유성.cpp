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

const int MAX = 3e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, q, lo[MAX], hi[MAX], p[MAX];
ll tree[MAX];
vector<int> sectors[MAX], mid[MAX];
vector<piii> qs;

void update(int node, ll v) {
    while (node <= m) {
        tree[node] += v;
        node += node & -node;
    }
}

ll sum(int node) {
    ll ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1, o; i <= m; ++i) {
        scanf("%d", &o);
        sectors[o].push_back(i);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", p + i);
    scanf("%d", &q);
    for (int i = 0, a, b, c; i < q; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        qs.push_back({c, {a, b}});
    }
    for (int i = 1; i <= n; ++i) 
        lo[i] = 0, hi[i] = q - 1;

    bool updated = true;
    while (updated) {
        updated = false;

        for (int i = 1; i <= n; ++i) 
            if (lo[i] <= hi[i]) 
                mid[(lo[i] + hi[i]) >> 1].push_back(i);
        memset(tree, 0, sizeof(tree));
        
        for (int i = 0; i < q; ++i) {
            if (qs[i].Y.X > qs[i].Y.Y) {
                update(qs[i].Y.X, qs[i].X);
                update(1, qs[i].X);
                update(qs[i].Y.Y + 1, -qs[i].X);
            } else {
                update(qs[i].Y.X, qs[i].X);
                update(qs[i].Y.Y + 1, -qs[i].X);
            }
            while (!mid[i].empty()) {
                updated = true;
                int num = mid[i].back(); mid[i].pop_back();
                ll s = 0;
                for (int sec: sectors[num]) {
                    s += sum(sec);
                    if (s >= p[num]) break;
                }
                if (s >= p[num]) hi[num] = i - 1;
                else lo[num] = i + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (lo[i] == q) puts("NIE");
        else printf("%d\n", lo[i] + 1);
    }

    close();
    return 0;
}

// (Q + M)logQlogN