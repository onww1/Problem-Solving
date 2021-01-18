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

const int MAX = 1e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, c[MAX][MAX], f[MAX];

int _pow(int base, int exp) {
    int ret = 1;
    while (exp) {
        if (exp & 1) ret = 1LL * ret * base % MOD;
        base = 1LL * base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) c[i][i] = c[i][0] = 1;
    for (int i = 2; i < MAX; i++) for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    f[0] = f[1] = 1;
    for (int i = 2; i < MAX; i++) f[i] = 1LL * i * f[i - 1] % MOD;

    int answer = 0, r = n % 4;
    n -= r;

    for (int i = 0, sign = 1; i <= n; i++, sign *= -1) {
        answer = (answer + 1LL * c[n][i] * f[n - i] % MOD * sign + 1LL * MOD * MOD) % MOD;
    }

    for (int i = 1; i <= r; i++)
        answer = 1LL * answer * (n + r - i + 1) % MOD;
    answer = 1LL * answer * _pow(f[r], MOD - 2) % MOD;
    
    printf("%d\n", answer);

    close();
    return 0;
}
