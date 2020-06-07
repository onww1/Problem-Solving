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

int ccw(pll a, pll b, pll c) {
    ll val = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    return val > 0 ? 1 : val < 0 ? -1 : 0;
}

bool isCross(pll p11, pll p12, pll p21, pll p22) {
    ll xmn1 = min(p11.X, p12.X), xmx1 = max(p11.X, p12.X);
    ll ymn1 = min(p11.Y, p12.Y), ymx1 = max(p11.Y, p12.Y);
    ll xmn2 = min(p21.X, p22.X), xmx2 = max(p21.X, p22.X);
    ll ymn2 = min(p21.Y, p22.Y), ymx2 = max(p21.Y, p22.Y);
    if (xmn1 > xmx2 || xmn2 > xmx1 || ymn1 > ymx2 || ymn2 > ymx1) return false;

    ll aa = ccw(p11, p12, p21) * ccw(p11, p12, p22);
    ll bb = ccw(p21, p22, p11) * ccw(p21, p22, p12);
    return aa <= 0 && bb <= 0;
}

int main(int argc, char *argv[]) {
    open();

    pll p[4];
    for (int i = 0; i < 4; ++i)
        scanf("%lld %lld", &p[i].X, &p[i].Y);
    printf("%d\n", isCross(p[0], p[1], p[2], p[3]) ? 1 : 0);

    close();
    return 0;
}
