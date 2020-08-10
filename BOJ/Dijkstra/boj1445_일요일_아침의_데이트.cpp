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

struct Info {
    int r, c;
    pii gs;
    Info() {}
    Info(int _r, int _c, pii _gs): r(_r), c(_c), gs(_gs){}
    bool operator< (const Info& other) const {
        return gs > other.gs;
    };
};

int n, m, str, stc;
pii gs[55][55];
char mp[55][55];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    str = stc = -1;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", mp[i]);
        if (str == -1) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'S') {
                    str = i;
                    stc = j;
                    break;
                }
            }
        }
    }
    memset(gs, 0x3f, sizeof(gs));
    priority_queue<Info> pq;
    gs[str][stc] = {0, 0};
    pq.push({str, stc, gs[str][stc]});

    while (!pq.empty()) {
        Info cur = pq.top();
        pq.pop();

        if (gs[cur.r][cur.c] < cur.gs) continue;
        if (mp[cur.r][cur.c] == 'F') return !printf("%d %d\n", cur.gs.X, cur.gs.Y);

        for (int k = 0; k < 4; ++k) {
            int dr = cur.r + move_r[k];
            int dc = cur.c + move_c[k];
            if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
            bool isS = false;
            for (int l = 0; l < 4; ++l) {
                int ldr = dr + move_r[l];
                int ldc = dc + move_c[l];
                if (ldr < 0 || ldr >= n || ldc < 0 || ldc >= m) continue;
                if (mp[ldr][ldc] == 'g') {
                    isS = true;
                    break;
                }
            }
            if (mp[dr][dc] == 'F' && gs[dr][dc] > cur.gs) {
                gs[dr][dc] = cur.gs;
                pq.push({dr, dc, cur.gs});
            }
            else if (mp[dr][dc] == 'g' && gs[dr][dc] > pii(cur.gs.X + 1, cur.gs.Y)) {
                gs[dr][dc] = {cur.gs.X + 1, cur.gs.Y};
                pq.push({dr, dc, gs[dr][dc]});
            }
            else if (mp[dr][dc] == '.' && gs[dr][dc] > pii(cur.gs.X, cur.gs.Y + (isS ? 1 : 0))) {
                gs[dr][dc] = {cur.gs.X, cur.gs.Y + (isS ? 1 : 0)};
                pq.push({dr, dc, gs[dr][dc]});
            }
        }
    }

    close();
    return 0;
}
