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

int n, m;
char in[2005][2005], ans[2005][2005];

char change(char c) {
    return c == 'B' ? 'W' : 'B';
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf(" %s", in[i] + 1);
    for (int j = 1; j <= m; ++j) ans[1][j] = '1';
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (in[i - 1][j] == 'B') {
                ans[i][j] = '2';
                for (int k = 0; k < 4; ++k) {
                    int dr = i + move_r[k];
                    int dc = j + move_c[k];
                    if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
                    in[dr][dc] = change(in[dr][dc]);
                }
            }
            else ans[i][j] = '1';
        }
    }
    queue<pii> q;
    for (int j = 1; j <= m; ++j) {
        if (in[n][j] == 'B') {
            if (ans[n][j] == '1') {
                q.push({n, j});
                ans[n][j] = '3';
            }
            else ans[n][j] = ans[n][j] == '2' ? '3' : '2';
        }
    }
    while (!q.empty()) {
        int r = q.front().X;
        int c = q.front().Y;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
            if (ans[dr][dc] == '1') {
                q.push({dr, dc});
                ans[dr][dc] = '3';
            } else ans[dr][dc] = ans[dr][dc] == '2' ? '3' : '2';
        }
    }

    puts("1");
    for (int i = 1; i <= n; ++i) printf("%s\n", ans[i] + 1);

    close();
    return 0;
}