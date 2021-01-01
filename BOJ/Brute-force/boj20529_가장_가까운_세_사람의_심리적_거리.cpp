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

int t, n, cnt[1 << 4];
char in[5];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            scanf(" %s", in);
            int value = 0;
            for (int j = 0; j < 4; j++) {
                if (in[j] == 'E' || in[j] == 'S' || in[j] == 'T' || in[j] == 'J') {
                    value |= (1 << j);
                }
            }
            cnt[value]++;
        }

        int ans = INF;
        for (int i = 0; i < 16; i++) {
            if (cnt[i] >= 3) {
                ans = 0;
                break;
            }
        }

        if (ans == INF) {
            for (int i = 0; i < 16; i++) {
                if (cnt[i] < 1) continue;
                for (int j = i; j < 16; j++) {
                    if (i == j && cnt[i] < 2) continue; 
                    if (cnt[j] < 1) continue;
                    for (int k = j; k < 16; k++) {
                        if (i == j && j == k) continue;
                        if (j == k && cnt[j] < 2) continue;
                        if (cnt[k] < 1) continue;
                        ans = min(ans, __builtin_popcount(i ^ j) + __builtin_popcount(i ^ k) + __builtin_popcount(j ^ k));
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    close();
    return 0;
}
