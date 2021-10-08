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

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, cnt[501][501];
char board[501][501];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(" %s", board[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'B') {
                for (int k = 0; k < 8; k++) {
                    int c = 0, y = i + move_r[k], x = j + move_c[k];
                    while (0 <= x && x < n && 0 <= y && y < n && board[y][x] == 'W') {
                        c++;
                        y += move_r[k];
                        x += move_c[k];
                    }
                    if (0 <= x && x < n && 0 <= y && y < n && board[y][x] == '.') {
                        cnt[y][x] += c;
                    }
                }
            }
        }
    }

    int mx = 0, y = -1, x = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt[i][j] > mx) {
                mx = cnt[i][j];
                y = i; x = j;
            }
        }
    }

    if (mx == 0) puts("PASS");
    else printf("%d %d\n%d\n", x, y, mx);

    close();
    return 0;
}