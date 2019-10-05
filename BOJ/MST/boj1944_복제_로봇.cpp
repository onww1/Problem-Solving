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

int n, m, vis, v[51][51], pa[251];
char in[51][51];
vector <pii> pos;
map <pii, int> idx;

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
    for (int i = 0; i < n; ++i) {
        scanf(" %s", in[i]);
        for (int j = 0; j < n; ++j) {
            if (in[i][j] == 'S' || in[i][j] == 'K') {
                idx[pii(i, j)] = pos.size();
                pos.push_back({i, j});
                in[i][j] = 'K';
            }
        }
    }

    priority_queue <piii, vector<piii>, greater<piii>> pq;

    for (int i = 0; i <= m; ++i) {
        ++vis; v[pos[i].X][pos[i].Y] = vis;
        queue <piii> Q; Q.push({0, pos[i]});
        while (!Q.empty()) {
            int d = Q.front().X;
            int r = Q.front().Y.X;
            int c = Q.front().Y.Y;
            Q.pop();

            if (in[r][c] == 'K') pq.push({d, {i, idx[pii(r, c)]}});
            
            for (int k = 0; k < 4; ++k) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
                if (v[dr][dc] != vis && in[dr][dc] != '1') {
                    Q.push({d + 1, {dr, dc}});
                    v[dr][dc] = vis;
                }
            }
        }
    }

    memset(pa, -1, sizeof(pa));
    int ans = 0, cnt = 0;
    while (!pq.empty()) {
        piii cur = pq.top(); pq.pop();
        if (_union(cur.Y.X, cur.Y.Y)) {
            ans += cur.X;
            cnt++;
            if (cnt == m) break;
        }
    }

    if (cnt != m) puts("-1");
    else printf("%d\n", ans);
    close();
    return 0;
}