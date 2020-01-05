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

int n, p, e, x[25], y[25], a[25];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &p, &e);
    if (p > n) return !printf("-1\n");
    for (int i = 0; i < n; ++i) scanf("%d %d", x + i, y + i);
    for (int i = 0; i < p; ++i) a[n - 1 - i] = 1;

    bool found = false;
    do {
        int mn = 0, mx = 0; 
        for (int i = 0; i < n; ++i) if (a[i]) mn += x[i], mx += y[i];
        if (mn <= e && e <= mx) {
            int diff = e - mn;
            for (int i = 0; i < n; ++i) {
                if (a[i]) {
                    int val = min(diff, y[i] - x[i]);
                    diff -= val;
                    printf("%d ", x[i] + val);
                }
                else printf("%d ", 0);
            }
            puts("");
            found = true;
            break;
        }
    } while (next_permutation(a, a + n));

    if (!found) puts("-1");

    close();
    return 0;
}
