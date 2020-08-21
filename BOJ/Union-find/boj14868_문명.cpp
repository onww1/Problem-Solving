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

int n, k, pa[2000 * 2000 + 1], v[2000 * 2000 + 1], cnt[2000 * 2000 + 1];
queue<int> q[2];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        cnt[v] += cnt[u];
        return cnt[v] == k;
    }
    return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n * n; ++i) pa[i] = i;
    for (int i = 0, r, c; i < k; ++i) {
        scanf("%d %d", &r, &c); r--; c--;
        q[0].push(r * n + c);
        v[r * n + c] = cnt[r * n + c] = 1;
    }

    while (!q[0].empty()) {
        int cur = q[0].front(); q[0].pop();
        int r = cur / n, c = cur % n;
        for (int l = 0; l < 4; ++l) {
            int dr = r + move_r[l];
            int dc = c + move_c[l];
            int next = dr * n + dc;
            if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
            if (v[next] && _union(next, cur)) return !printf("0\n");
        }
        q[1].push(cur);
    }

    for (int t = 1; ; ++t) {
        int p = t & 1;
        while (!q[p].empty()) {
            int cur = q[p].front(); q[p].pop();
            int r = cur / n, c = cur % n;
            for (int l = 0; l < 4; ++l) {
                int dr = r + move_r[l];
                int dc = c + move_c[l];
                int next = dr * n + dc;
                if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
                if (_find(next) == _find(cur)) continue;
                if (_union(next, cur)) return !printf("%d\n", t);
                v[next] = 1;
                q[1 - p].push(next);
                for (int s = 0; s < 4; ++s) {
                    int ddr = dr + move_r[s];
                    int ddc = dc + move_c[s];
                    int nnext = ddr * n + ddc;
                    if (ddr < 0 || ddr >= n || ddc < 0 || ddc >= n) continue;
                    if (v[nnext] && _union(nnext, next)) return !printf("%d\n", t);
                }
            }
        }
    }

    close();
    return 0;
}
