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
typedef pair<int, pii> piii;

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

int n, m, mp[1002][1002], v[1002][1002];
int h, w, sr, sc, fr, fc;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%d", mp[i] + j);
    scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &fr, &fc);

    queue <pii> q; 
    q.push({sr, sc}); v[sr][sc] = 1;
    while (!q.empty()) {
        int r = q.front().X;
        int c = q.front().Y;
        q.pop();

        if (r == fr && c == fc) return !printf("%d\n", v[r][c] - 1);

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 1 || dr + h - 1 > n || dc < 0 || dc + w - 1 > m || v[dr][dc]) continue;
            if (move_r[k]) {
                bool valid = true;
                for (int j = c; j < c + w; ++j) {
                    if (move_r[k] > 0 && mp[r + h][j]) valid = false;
                    if (move_r[k] < 0 && mp[dr][j]) valid = false;
                    if (!valid) break;
                }
                if (!valid) continue;
            }
            if (move_c[k]) {
                bool valid = true;
                for (int i = r; i < r + h; ++i) {
                    if (move_c[k] > 0 && mp[i][c + w]) valid = false;
                    if (move_c[k] < 0 && mp[i][dc]) valid = false;
                    if (!valid) break;
                }
                if (!valid) continue;
            }
            v[dr][dc] = v[r][c] + 1;
            q.push({dr, dc});
        }
    }

    puts("-1");
    close();
    return 0;
}