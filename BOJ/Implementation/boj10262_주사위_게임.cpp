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

ll a[2], b[2], c[2], d[2];
ll g[201], e[201], G, E;

int main(int argc, char *argv[]) {
    open();

    scanf("%lld %lld %lld %lld", a, b, a + 1, b + 1);
    scanf("%lld %lld %lld %lld", c, d, c + 1, d + 1);

    for (int i = a[0]; i <= b[0]; ++i)
    	for (int j = a[1]; j <= b[1]; ++j)
    		g[i + j]++;

    for (int i = c[0]; i <= d[0]; ++i)
    	for (int j = c[1]; j <= d[1]; ++j)
    		e[i + j]++;

    ll gmn = a[0] + a[1], gmx = b[0] + b[1];
    ll emn = c[0] + c[1], emx = d[0] + d[1];

    for (int i = emn; i <= 200; ++i) e[i] += e[i - 1];

    for (int i = gmn; i <= gmx; ++i) {
    	G += g[i] * e[i - 1];
    	E += g[i] * (e[emx] - e[i]);
    }

    if (G > E) puts("Gunnar");
	else if (G < E) puts("Emma");
	else puts("Tie");

    close();
    return 0;
}