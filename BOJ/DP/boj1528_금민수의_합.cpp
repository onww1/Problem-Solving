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

int n, d[2] = {4, 7};
pii dp[MAX];
vector<int> v, ans;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = {0, 0};
    
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < 2; ++i) {
            int next = cur * 10 + d[i];
            if (next <= n) {
                v.push_back(next);
                q.push(next);
            }
        }
    }

    for (int i = (int)v.size() - 1; i >= 0; --i) 
        for (int j = 0; j <= n - v[i]; ++j) 
            if (dp[j].X != INF) {
                if (dp[j + v[i]].X > dp[j].X + 1)
                    dp[j + v[i]] = {dp[j].X + 1, v[i]};
                else if (dp[j + v[i]].X == dp[j].X + 1)
                    dp[j + v[i]].Y = min(dp[j + v[i]].Y, v[i]);
            }
                
    if (dp[n].X == INF) puts("-1");
    else {
        while (n > 0) {
            ans.push_back(dp[n].Y);
            n -= dp[n].Y;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
        puts("");
    }

    close();
    return 0;
}
