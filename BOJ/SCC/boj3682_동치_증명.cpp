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

const int MAX = 2e4 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int t, n, m, cnt, g[MAX], in[MAX], out[MAX], v[MAX];
vector<int> edges[MAX], redges[MAX], st;

void dfs(int node) {
    v[node] = 1;
    for (int next: edges[node]) if (!v[next]) dfs(next);
    st.push_back(node);
}

void dfs2(int node, int group) {
    v[node] = 0;
    g[node] = group;
    for (int next: redges[node]) if (v[next]) dfs2(next, group);
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            redges[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i);
        while (!st.empty()) {
            int node = st.back(); st.pop_back();
            if (v[node]) dfs2(node, ++cnt);
        }
        
        for (int i = 1; i <= n; ++i)
            for (int next: edges[i])
                if (g[i] != g[next]) {
                    in[g[next]]++;
                    out[g[i]]++;
                }

        if (cnt == 1) puts("0");
        else {
            int inc = 0, outc = 0;
            for (int i = 1; i <= cnt; ++i) {
                if (!in[i]) inc++;
                if (!out[i]) outc++;
            }
            printf("%d\n", max(inc, outc));
        }

        for (int i = 1; i <= cnt; ++i) in[i] = out[i] = 0; cnt = 0;
        for (int i = 1; i <= n; ++i) {
            edges[i].clear();
            redges[i].clear();
            g[i] = 0;
        }
        st.clear();
    }

    close();
    return 0;
}


// 1. SCC로 묶어주기
// 2. 전부 묶이면 동치
// 3. 더 묶일 필요가 있으면 indegree 0인 점과 outdegree 0인 점의 수 중 큰 것