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

int main(int argc, char *argv[]) {
    open();

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pii> items(n);
    vector<int> k(m);
    int mxK = 0;

    for (pii &item : items) scanf("%d %d", &item.X, &item.Y);
    for (int &kv : k) {
        scanf("%d", &kv);
        mxK = max(mxK, kv);
    }

    vector<int> dp(mxK + 1, -1);
    dp[0] = 0;

    int mxV = 0;
    for (pii &item : items) {
        for (int i = mxV; i >= 0; i--) {
            if (i + item.X > mxK) continue;
            if (dp[i] == -1) continue;
            dp[i + item.X] = max(dp[i + item.X], dp[i] + item.Y);
            mxV = max(mxV, i + item.X);
        }
    }
    for (int i = 1; i <= mxK; i++) dp[i] = max(dp[i], dp[i - 1]);

    int answer = 0;
    pii cur = {-1, 1};
    for (int i = 1; i <= k.size(); i++) {
        int kv = k[i - 1];
        if (1LL * dp[kv] * cur.Y > 1LL * kv * cur.X) {
            answer = i;
            cur = pii(dp[kv], kv);
        }
    }
    
    printf("%d\n", answer);

    close();
    return 0;
}