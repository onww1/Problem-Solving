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

int n, q, c[105], stat[105];
char s[105];
piii p[255];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %s", &n, &q, s + 1);
    for (int i = 1; i <= n; ++i) s[i] -= '0';
    for (int i = 0; i < q; ++i) scanf("%d %d %d", &p[i].X, &p[i].Y.X, &p[i].Y.Y);
    sort(p, p + q);

    int cnt = 0, lo = q, hi = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 0) continue;
        int llo = -1, lhi = -1;
        for (int k = 0; k <= q; ++k) {
            memset(c, 0, sizeof(c));
            memset(stat, 0, sizeof(stat));
            stat[i] = 1;
            for (int j = 0; j < q; ++j) {
                if (stat[p[j].Y.X]) c[p[j].Y.X]++;
                if (stat[p[j].Y.Y]) c[p[j].Y.Y]++;
                if (c[p[j].Y.X] <= k && stat[p[j].Y.X]) stat[p[j].Y.Y] = 1;
                if (c[p[j].Y.Y] <= k && stat[p[j].Y.Y]) stat[p[j].Y.X] = 1;
            }
            bool eq = true;
            for (int j = 1; j <= n; ++j)
                if (s[j] != stat[j]) {
                    eq = false;
                    break;
                }
            if (eq) {
                if (llo == -1) llo = k;
                lhi = k;
            }
        }
        if (llo != -1) {
            cnt++;
            lo = min(lo, llo);
            hi = max(hi, lhi);
        }
    }
    if (hi == q) printf("%d %d %s\n", cnt, lo, "Infinity");
    else printf("%d %d %d\n", cnt, lo, hi);

    close();
    return 0;
}
