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
char in[11][11];
set<int> sq;

int main(int argc, char *argv[]) {
    open();

    for (int i = 0; i <= 31622; ++i) sq.insert(i * i);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", in[i] + 1);
        for (int j = 1; j <= m; ++j) in[i][j] -= '0';
    }

    int ans = -1;
    for (int rd = -n + 1; rd <= n; ++rd) {
        for (int rc = -m + 1; rc <= m; ++rc) {
            if (!rd && !rc) continue;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    int num = 0;
                    for (int len = 0; ; ++len) {
                        int dr = i + len * rd;
                        int dc = j + len * rc;
                        if (dr < 1 || dc < 1 || dr > n || dc > m) break;
                        num = num * 10 + in[dr][dc];
                        if (sq.count(num)) ans = max(ans, num);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    close();
    return 0;
}
