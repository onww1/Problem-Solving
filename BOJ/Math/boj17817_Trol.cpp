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

int q;
ll l, r;

ll digit_sum(ll num) {
    while (num >= 10) {
        ll p = num, sum = 0;
        while (p) {
            sum += p % 10LL;
            p /= 10LL;
        }
        num = sum;
    }
    return num;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &q);
    while (q--) {
        scanf("%lld %lld", &l, &r);
        ll lval = digit_sum(l);
        ll rval = digit_sum(r);
        ll len = r - l + 1 - (10 - lval) - rval;
        if (len < 0) printf("%lld\n", (rval - lval + 1) * (lval + rval) / 2LL);
        else printf("%lld\n", (10 - lval) * (lval + 9) / 2LL + rval * (rval + 1) / 2LL + len * 5LL);
    }

    close();
    return 0;
}
