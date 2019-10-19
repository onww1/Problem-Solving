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

ll _gcd(ll a, ll b) { return b ? _gcd(b, a % b) : a; }
ll _lcm(ll a, ll b) { return a / _gcd(a, b) * b; }

ll n, k, a[15];

int main(int argc, char *argv[]) {
    open();

    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < k; ++i) scanf("%lld", a + i);

    ll ans = 0, lim = 1 << k;
	for (int i = 1; i < lim; ++i) {
		int cnt = 0; ll LCM = 1;
		for (int j = 0; j < k; ++j) 
			if (i & (1 << j)) {
				cnt++;
				LCM = _lcm(LCM, a[j]);
				if (LCM > n) break;
			}
		ll num = n / LCM;
		if (cnt % 2) ans += num;
		else ans -= num;
	}
	printf("%lld\n", n - ans);

    close();
    return 0;
}