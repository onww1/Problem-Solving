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

int n, m, v[55][55];
char in[55][55];
vector<vector<int>> edges;
vector<int> depth, cnt;
queue<pii> q[3];

void dfs(int node) {
    depth[node] = 0;
    for (int next: edges[node]) {
        dfs(next);
        depth[node] = max(depth[node], depth[next] + 1);
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf(" %s", in[i] + 1);
    memset(v, -1, sizeof(v));

    q[0].push({0, 0}); 
    v[0][0] = 0;
    edges.push_back(vector<int>());

    int node = 0;
    while (1) {
        while (!q[0].empty()) {
            int r = q[0].front().X;
            int c = q[0].front().Y;
            q[0].pop();

            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr > n + 1 || dc < 0 || dc > m + 1) continue;
                if (v[dr][dc] == -1) {
                    v[dr][dc] = v[r][c];
                    if (in[dr][dc] == 'x') q[1].push({dr, dc});
                    else q[0].push({dr, dc});
                }
            }
        }

        if (q[1].empty()) break;
        
        while (!q[1].empty()) {
            pii cur = q[1].front();
            q[1].pop();

            if (v[cur.X][cur.Y] == INF) continue;
            edges.push_back(vector<int>());
            edges[v[cur.X][cur.Y]].push_back(++node);
            q[2].push(cur); v[cur.X][cur.Y] = INF;
            while (!q[2].empty()) {
                int r = q[2].front().X;
                int c = q[2].front().Y;
                q[2].pop();

                for (int k = 0; k < 8; ++k) {
                    int dr = r + move_r[k];
                    int dc = c + move_c[k];
                    if (dr < 0 || dr > n + 1|| dc < 0 || dc > m + 1) continue;
                    if (in[dr][dc] == 'x' && v[dr][dc] != INF) {
                        q[2].push({dr, dc});
                        v[dr][dc] = INF;
                    } else if (in[dr][dc] == '.' && v[dr][dc] == -1) {
                        q[0].push({dr, dc});
                        v[dr][dc] = node;
                    }
                }
            }
        }
    }

    if (!node) puts("-1");
    else {
        depth.resize(edges.size(), 0);
        dfs(0);
        cnt.resize(depth[0], 0);
        for (int i = 1; i <= node; ++i)
            cnt[depth[i]]++;
        for (int num: cnt) printf("%d ", num);
        puts("");
    }

    close();
    return 0;
}
