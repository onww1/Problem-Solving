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
const int MOD = 1e9;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, t[1001], q[1001];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    t[2] = t[3] = 1;
    for (int i = 4; i <= n; ++i) {
        for (int j = 1; j <= i - 2; ++j)
            t[i] = (t[i] + 1LL * t[j + 1] * t[i - j]) % MOD;
    }
    q[2] = q[4] = 1;
    for (int i = 6; i <= n; ++i) {
        for (int j = 1; j <= i - 2; j += 2) {
            for (int k = 1; j + k <= i - 2; k += 2) {
                q[i] = (q[i] + 1LL * q[j + 1] * q[k + 1] % MOD * q[i - j - k]) % MOD;
            }
        }
    }
    t[2] = q[2] = 0;
    printf("%d\n%d\n", t[n], q[n]);

    close();
    return 0;
}
