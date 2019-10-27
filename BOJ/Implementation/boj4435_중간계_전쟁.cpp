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

int t, a, b, asum, bsum, as[] = {1, 2, 3, 3, 4, 10}, bs[] = {1, 2, 2, 2, 3, 5, 10};

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
    	asum = bsum = 0;
    	for (int i = 0; i < 6; ++i) {
    		scanf("%d", &a);
    		asum += a * as[i];
    	}
    	for (int i = 0; i < 7; ++i) {
    		scanf("%d", &b);
    		bsum += b * bs[i];
    	}
    	if (asum < bsum) printf("Battle %d: Evil eradicates all trace of Good\n", tc);
    	else if (asum > bsum) printf("Battle %d: Good triumphs over Evil\n", tc);
    	else printf("Battle %d: No victor on this battle field\n", tc);
    }

    close();
    return 0;
}
