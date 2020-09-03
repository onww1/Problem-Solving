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

const int MAX = 3e4 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int r, c, n, p[31], col[31][MAX];
char in[MAX][35];

void process(int idx) {
    while (1) {
        while (in[p[idx]][col[idx][p[idx]]] != '.') p[idx]--;
        while (p[idx] < r && in[p[idx] + 1][col[idx][p[idx]]] == '.') {
            col[idx][p[idx] + 1] = col[idx][p[idx]];
            p[idx]++;
        }
        if (p[idx] < r && in[p[idx] + 1][col[idx][p[idx]]] == 'X') break;
        if (p[idx] < r && in[p[idx] + 1][col[idx][p[idx]]] == 'O') {
            if (col[idx][p[idx]] > 1 && in[p[idx]][col[idx][p[idx]] - 1] == '.' && in[p[idx] + 1][col[idx][p[idx]] - 1] == '.') {
                col[idx][p[idx] + 1] = col[idx][p[idx]] - 1;
                p[idx]++;
            } 
            else if (col[idx][p[idx]] < c && in[p[idx]][col[idx][p[idx]] + 1] == '.' && in[p[idx] + 1][col[idx][p[idx]] + 1] == '.') {
                col[idx][p[idx] + 1] = col[idx][p[idx]] + 1;
                p[idx]++;
            }
            else break;
        }
        if (p[idx] == r) break;
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; ++i) scanf(" %s", in[i] + 1);
    
    for (int i = 1; i <= c; ++i) {
        p[i] = 1; 
        col[i][0] = col[i][1] = i;
        process(i);
    }

    scanf("%d", &n);
    for (int i = 1, q; i <= n; ++i) {
        scanf("%d", &q);
        in[p[q]][col[q][p[q]]] = 'O';
        for (int j = 1; j <= c; ++j) process(j);
    }

    for (int i = 1; i <= r; ++i) printf("%s\n", in[i] + 1);

    close();
    return 0;
}
