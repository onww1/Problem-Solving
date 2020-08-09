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

int t, n, dp[101][2];
int len[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> reff[8];
char ans[101];

int main(int argc, char *argv[]) {
    open();

    for (int i = 0; i < 10; ++i) reff[len[i]].push_back(i);
    for (int i = 1; i <= 100; ++i) dp[i][0] = INF;
    for (int i = 2; i <= 100; ++i) {
        for (int j = 2; j <= 7; ++j) {
            if (i - j >= 0) {
                dp[i][0] = min(dp[i][0], dp[i - j][0] + 1);
                dp[i][1] = max(dp[i][1], dp[i - j][1] + 1);
            }
        }
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int idx = 0, p = n;
        while (p) {
            int mn = INF, len = 0;
            for (int i = 7; i >= 2; --i) {
                if (p - i < 0) continue;
                if (dp[p][0] == dp[p - i][0] + 1) {
                    int val = i == 6 && p == n ? reff[i][1] : reff[i][0];
                    if (val < mn) {
                        mn = val;
                        len = i;
                    } 
                }
            }
            ans[idx++] = mn + '0';
            p -= len;
        }
        ans[idx] = 0;
        printf("%s ", ans);

        idx = 0, p = n;
        while (p) {
            int mx = 0, len = 0;
            for (int i = 7; i >= 2; --i) {
                if (p - i < 0) continue;
                if (dp[p][1] == dp[p - i][1] + 1) {
                    int val = reff[i].back();
                    if (val > mx) {
                        mx = val;
                        len = i;
                    }
                }
            }
            ans[idx++] = mx + '0';
            p -= len;
        }
        ans[idx] = 0;
        printf("%s\n", ans);
    }

    close();
    return 0;
}
