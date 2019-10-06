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

int n, m, v[1005][1005], adj[1005][1005];
char in[1005][1005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    queue <pii> q[2];
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; j < m; ++j)
            if (in[i][j] == '.') {
                q[0].push({i, j});
                v[i][j] = 1;
            }
    }

    int t = 0, qn = 0, changed = true;
    while (changed) {
        changed = false;
        while (!q[qn].empty()) {
            int r = q[qn].front().X;
            int c = q[qn].front().Y;
            q[qn].pop();

            for (int k = 0; k < 8; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                adj[dr][dc]++;
                if (!v[dr][dc] && in[dr][dc] != '.' && adj[dr][dc] >= in[dr][dc] - '0') {
                    v[dr][dc] = 1;
                    q[1 - qn].push({dr, dc});
                    changed = true;
                }
            }
        }
        qn ^= 1;
        t++;
    }

    printf("%d\n", t - 1);
    close();
    return 0;
}