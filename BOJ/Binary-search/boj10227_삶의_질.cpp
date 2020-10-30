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

const int SZ = 1 << 24;
const int MAX = 3e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, h, w, med, a[MAX][MAX], ps[MAX][MAX];

bool check(int p) {
    int r = -1, c = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == p) r = i, c = j;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (a[i][j] <= p ? 1 : 0);
        }
    }
    for (int i = 0; i + h <= n; i++)
        for (int j = 0; j + w <= m; j++)
            if (ps[i + h][j + w] - ps[i + h][j] - ps[i][j + w] + ps[i][j] >= med)
                return true;
    return false;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &m, &h, &w);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", a[i] + j);
    med = (h * w + 1) / 2;
    int lo = 1, hi = n * m;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }
    printf("%d\n", lo);

    close();
    return 0;
}
