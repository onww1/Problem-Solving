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

int n, m, p, dmg[26], hp, dist[1005][1005];
char mp[1005][1005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &m, &p);
    memset(dist, 0x3f, sizeof(dist));
    queue<pii> q;
    int ans = 0, tot = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", mp[i] + 1);
        for (int j = 1; j <= m; ++j)
            if (mp[i][j] == 'B') {
                dist[i][j] = 0;
                q.push({i, j});
            }
    }
    char ch;
    for (int i = 0, dd; i < p; ++i) {
        scanf(" %c %d", &ch, &dd);
        dmg[ch - 'a'] = dd;
    }
    scanf("%d", &hp);

    int sz = 0;
    while (!q.empty()) {
        if (!sz) {
            sz = q.size();
            hp -= tot;
            if (hp <= 0) break;
        }
        int r = q.front().X;
        int c = q.front().Y;
        q.pop();
        sz--;

        if ('a' <= mp[r][c] && mp[r][c] <= 'z') {
            ans++;
            tot += dmg[mp[r][c] - 'a'];
        }

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
            if (dist[dr][dc] == INF && mp[dr][dc] != 'X') {
                dist[dr][dc] = dist[r][c] + 1;
                q.push({dr, dc});
            }
        }
    }

    printf("%d\n", ans);

    close();
    return 0;
}
