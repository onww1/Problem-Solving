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

ll square(ll a) { return a * a; }

ll n, a, b, c, d;

int main(int argc, char *argv[]) {
    open();

    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        ll ans = square(a + d) + square(b) + square(c) + 7 * min({a + d, b, c});
        ans = max(ans, square(a) + square(b + d) + square(c) + 7 * min({a, b + d, c}));
        ans = max(ans, square(a) + square(b) + square(c + d) + 7 * min({a, b, c + d}));
        ll sum = a + b + c, mx = max({a, b, c}), mn = min({a, b, c});
        a = mn, b = sum - mx - mn, c = mx;
        d -= (b - a); a = b;
        if (d <= 0) a += d;
        else {
            d -= (c - b) * 2;
            a = b = c;
            if (d <= 0) {
                ll v = d / 2;
                a += v;
                b += (d - v);
            }            
            else {
                ll v = d / 3;
                a += v + (d % 3 > 0);
                b += v + (d % 3 > 1);
                c += v;
            }
        }
        ans = max(ans, square(a) + square(b) + square(c) + 7 * min({a, b, c}));
        printf("%lld\n", ans);
    }

    close();
    return 0;
}