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

int n, a[MAX], b[MAX];
ll dp[MAX];
deque<pll> lines;

ll solve(int x) {
    while (lines.size() > 1 && lines[0].X * x + lines[0].Y > lines[1].X * x + lines[1].Y) 
        lines.pop_front();
    return lines[0].X * x + lines[0].Y;
}

void insert(ll m, ll c) {
    int sz = lines.size() - 1;
    while (lines.size() > 1 && (ldb)(lines[sz].Y - lines[sz - 1].Y) / (lines[sz - 1].X - lines[sz].X) > (ldb)(c - lines[sz].Y) / (lines[sz].X - m)) {
        lines.pop_back();
        sz = lines.size() - 1;
    }
    lines.push_back({m, c});
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    lines.push_back({b[1], 0});
    for (int i = 2; i <= n; ++i) {
        dp[i] = solve(a[i]);
        insert(b[i], dp[i]);
    }
    printf("%lld\n", dp[n]);

    close();
    return 0;
}
