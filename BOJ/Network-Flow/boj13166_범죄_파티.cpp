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

const int MAX = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct info {
    int a, ka, b, kb;
};

int n;
vector<info> e;

struct HopcroftKarp {
    int size, a[MAX], b[2 * MAX], lv[MAX];
    bool used[MAX];
    vector<int> edges[MAX];    

    void init(int n) {
        size = n;
        for (int i = 1; i <= n; ++i) {
            a[i] = b[i] = b[i + n] = -1;
            used[i] = false;
            edges[i].clear();
        }
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }

    void bfs() {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                lv[i] = 0;
                q.push(i);
            }
            else lv[i] = INF;
        }
        while (!q.empty()) {
            int an = q.front(); q.pop();
            for (int bn: edges[an]) {
                if (b[bn] != -1 && lv[b[bn]] == INF) {
                    lv[b[bn]] = lv[an] + 1;
                    q.push(b[bn]);
                }
            }
        }
    }

    bool dfs(int an) {
        for (int bn: edges[an]) {
            if (b[bn] == -1 || lv[b[bn]] == lv[an] + 1 && dfs(b[bn])) {
                used[an] = true;
                a[an] = bn; b[bn] = an;
                return true;
            }
        }
        return false;
    }

    int maximum_matching() {
        int match = 0;
        while (1) {
            bfs();

            int flow = 0;
            for (int i = 1; i <= size; ++i) 
                if (!used[i] && dfs(i)) 
                    flow++;
            
            if (!flow) break;
            match += flow;
        }
        return match;
    }
} HK;

int hopcroft_karp(int mx) {
    HK.init(n);
    for (int i = 0; i < e.size(); ++i) {
        if (e[i].ka <= mx) HK.add_edge(i + 1, e[i].a);
        if (e[i].kb <= mx) HK.add_edge(i + 1, e[i].b);
    }
    return HK.maximum_matching();
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1, a, ka, b, kb; i <= n; ++i) {
        scanf("%d %d %d %d", &a, &ka, &b, &kb);
        e.push_back({a, ka, b, kb});
    }
    
    int lo = 0, hi = 1e6;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int matching = hopcroft_karp(mid);
        if (matching == n) hi = mid - 1;
        else lo = mid + 1;
    }
    printf("%d\n", lo == 1000001 ? -1 : lo);

    close();
    return 0;
}
