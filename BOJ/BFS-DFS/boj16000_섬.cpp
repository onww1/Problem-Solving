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

const int MAX = 2e3 + 3;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int move_c[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m, cnt, v[MAX][MAX], num[MAX][MAX];
char in[MAX][MAX];

int main(int argc, char *argv[]) {
    open();
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf(" %s", in[i] + 1);
    queue<pii> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!v[i][j] && in[i][j] == '#') {
                q.push({i, j}); v[i][j] = 1; num[i][j] = ++cnt;
                while (!q.empty()) {
                    int r = q.front().X;
                    int c = q.front().Y;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int dr = r + move_r[k];
                        int dc = c + move_c[k];
                        if (dr < 1 || dr > n || dc < 1 || dc > m || v[dr][dc]) continue;
                        if (in[dr][dc] == '#') {
                            q.push({dr, dc});
                            num[dr][dc] = cnt;
                            v[dr][dc] = 1;
                        }
                    }
                }
            }

    vector<bool> safe(cnt + 1, false);
    q.push({1, 1}); v[1][1] = 1;
    while (!q.empty()) {
        int r = q.front().X;
        int c = q.front().Y;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int dr = r + move_r[k];
            int dc = c + move_c[k];
            if (dr < 1 || dr > n || dc < 1 || dc > m) continue;
            if (!v[dr][dc] && in[dr][dc] == '.') {
                q.push({dr, dc});
                v[dr][dc] = 1;
            }
            else if (num[dr][dc]) {
                safe[num[dr][dc]] = true;
                int kk = (k + 1) % 4;
                int pr = r + move_r[kk];
                int pc = c + move_c[kk];
                int ddr = r + move_r[k + 4];
                int ddc = c + move_c[k + 4];
                if (pr < 1 || pr > n || pc < 1 || pc > m) continue;
                if (num[pr][pc] && num[pr][pc] != num[dr][dc] && in[ddr][ddc] == '.' && !v[ddr][ddc]) {
                    q.push({ddr, ddc});
                    v[ddr][ddc] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (num[i][j]) in[i][j] = safe[num[i][j]] ? 'O' : 'X';
    for (int i = 1; i <= n; ++i) printf("%s\n", in[i] + 1);
    

    close();
    return 0;
}
