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

const int NMAX = 1e3 + 1;
const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, mp[NMAX][NMAX], pa[MAX], cnt[MAX], v[MAX];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u); v = _find(v);
    if (u != v) {
        pa[v] = u;
        cnt[u] += cnt[v];
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", mp[i] + j);
            int idx = i * m + j;
            pa[idx] = idx;
            cnt[idx] = mp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            if (mp[i][j] && _find(idx) == idx) {
                for (int k = 0; k < 2; k++) {
                    int dr = i + move_r[k];
                    int dc = j + move_c[k];
                    if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                    if (mp[dr][dc]) _union(idx, dr * m + dc);
                }
            }
        }
    }

    int mx = 0, vcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            if (mp[i][j]) {
                mx = max(mx, cnt[_find(idx)]);
                continue;
            }
            int sum = 1; ++vcnt;
            for (int k = 0; k < 4; k++) {
                int dr = i + move_r[k];
                int dc = j + move_c[k];
                if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                int didx = dr * m + dc;
                int p = _find(didx);
                if (v[p] == vcnt) continue;
                sum += cnt[p];
                v[p] = vcnt;
            }
            mx = max(mx, sum);
        }
    }

    printf("%d\n", mx);

    close();
    return 0;
}
