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

int n, a[10005], dp[10005], in[10005];
vector <int> edges[10005];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    queue <int> Q;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", a + i, in + i);
        if (in[i] == 0) Q.push(i);
        for (int j = 0, v; j < in[i]; ++j) {
            scanf("%d", &v);
            edges[v].push_back(i);
        }
    }

    int mx = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        dp[cur] += a[cur];
        mx = max(mx, dp[cur]);
        for (int next : edges[cur]) {
            if (--in[next] == 0) Q.push(next);
            dp[next] = max(dp[next], dp[cur]);
        }
    }

    printf("%d\n", mx);
    close();
    return 0;
}