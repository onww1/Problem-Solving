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

int n, m, a[11][11], pa[10], v[11][11], vis;
vector <ti3> edges;

int _find(int u) {
    if (pa[u] < 0) return u;
    return pa[u] = _find(pa[u]);
}

bool _union(int u, int v) {
    u = _find(u), v = _find(v);
    if (u != v) {
        pa[u] = v;
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] && !v[i][j]) {
                v[i][j] = ++vis;
                queue <pii> q; q.push({i, j});
                while (!q.empty()) {
                    int r = q.front().X;
                    int c = q.front().Y;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int dr = r + move_r[k];
                        int dc = c + move_c[k];
                        if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
                        if (a[dr][dc] && !v[dr][dc]) {
                            v[dr][dc] = vis;
                            q.push({dr, dc});
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j]) {
                int org = v[i][j], cnt = 0;
                for (int k = j + 1; k <= m; ++k) {
                    if (!a[i][k]) ++cnt;
                    else if (v[i][k] == org) break;
                    else if (v[i][k] != org) {
                        if (cnt < 2) break;
                        edges.push_back({cnt, org, v[i][k]});
                        break;
                    }
                }
                cnt = 0;
                for (int k = i + 1; k <= n; ++k) {
                    if (!a[k][j]) ++cnt;
                    else if (v[k][j] == org) break;
                    else if (v[k][j] != org) {
                        if (cnt < 2) break;
                        edges.push_back({cnt, org, v[k][j]});
                        break;
                    }
                }

            }
        }
    }

    memset(pa, -1, sizeof(pa));
    sort(edges.begin(), edges.end());
    int cnt = 0, ans = 0, u, v, w;
    for (ti3& edge : edges) {
        tie(w, u, v) = edge;
        if (_union(u, v)) {
            ans += w;
            cnt++;
            if (cnt == vis - 1) break;
        }
    }

    printf("%d\n", cnt == vis - 1 ? ans : -1);

    close();
    return 0;
}