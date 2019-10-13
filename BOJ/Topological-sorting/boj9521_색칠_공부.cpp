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

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, k, f[MAX], in[MAX], dp[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", f + i);
        in[f[i]]++;
    }

    dp[1] = k; 
    dp[2] = 1LL * k * (k - 1) % MOD;
    dp[3] = 1LL * k * (k - 1) % MOD * (k - 2) % MOD;
    for (int i = 4; i <= n; ++i)
        dp[i] = (1LL * dp[i - 1] * (k - 2) % MOD + 1LL * dp[i - 2] * (k - 1) % MOD) % MOD;

    queue <int> q;
    for (int i = 1; i <= n; ++i) if (!in[i]) q.push(i);

    ll ans = 1LL;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans = ans * (k - 1) % MOD;
        if (--in[f[cur]] == 0) q.push(f[cur]);
    }

    for (int i = 1; i <= n; ++i) 
        if (in[i]) {
            int cnt = 0, pos = i;
            while (in[pos]) {
                in[pos]--; cnt++;
                pos = f[pos];
            }
            ans = ans * dp[cnt] % MOD;
        }

    printf("%lld\n", ans);

    close();
    return 0;
}