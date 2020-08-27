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

const int QMAX = 1e5 + 1;
const int MAX = 5e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, q, h[501][501], id[501][501], pa[250001], lo[100001], hi[100001], qs[100001][4];
vector<int> mid[250001];
vector<pii> ps[1000001];

int _find(int u) {
    if (pa[u] == u) return u;
    return pa[u] = _find(pa[u]);
}

void _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) pa[u] = v;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &q);
    vector<int> hs;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        scanf("%d", h[i] + j);
        hs.push_back(h[i][j]);
        id[i][j] = i * m + j;
        ps[h[i][j]].push_back({i, j});
    }

    sort(hs.begin(), hs.end());
    hs.resize(unique(hs.begin(), hs.end()) - hs.begin());

    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", qs[i], qs[i] + 1, qs[i] + 2, qs[i] + 3);
        qs[i][0]--; qs[i][1]--; qs[i][2]--; qs[i][3]--;
        lo[i] = 0, hi[i] = hs.size() - 1;
    }

    bool updated = true;
    int nm = n * m;
    while (updated) {
        updated = false;
        for (int i = 0; i <= nm; ++i) pa[i] = i;
        for (int i = 0; i < q; ++i) if (lo[i] <= hi[i]) mid[(lo[i] + hi[i]) >> 1].push_back(i);
        for (int i = 0; i < hs.size(); ++i) {
            for (pii& rc: ps[hs[i]]) {
                for (int k = 0; k < 4; ++k) {
                    int dr = rc.X + move_r[k];
                    int dc = rc.Y + move_c[k];
                    if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                    if (h[dr][dc] <= hs[i]) _union(id[rc.X][rc.Y], id[dr][dc]);
                }
            }
            while (!mid[i].empty()) {
                updated = true;
                int qi = mid[i].back(); mid[i].pop_back();
                if (_find(id[qs[qi][0]][qs[qi][1]]) == _find(id[qs[qi][2]][qs[qi][3]]) && hs[i] >= h[qs[qi][0]][qs[qi][1]]) hi[qi] = i - 1;
                else lo[qi] = i + 1;
            }
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", hs[lo[i]]);

    close();
    return 0;
}
