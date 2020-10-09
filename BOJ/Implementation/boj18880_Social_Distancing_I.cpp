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

int n;
char in[MAX + 1];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %s", &n, in + 1);
    int ans = INF, l = -1, r = -1, pp = -1;
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == '1') {
            if (l == -1) l = i;
            r = i;
            if (pp != -1) {
                ans = min(ans, i - pp);
                pq.push(i - pp);
            }
            pp = i;
        }
    }
    if (l == -1) return !printf("%d\n", n - 1);
    int mx = 0;
    if (l > 2) mx = max(mx, (l - 1) / 2);
    if (r + 1 < n) mx = max(mx, (n - r) / 2);
    if (l > 1 && r < n) mx = max(mx, min(l - 1, n - r));
    int p = -1, c = -1;
    if (!pq.empty()) {
        c = pq.top(); pq.pop();
        if (c > 2) mx = max(mx, c / 3);
        if (c > 1) {
            if (l > 1) mx = max(mx, min(c / 2, l - 1));
            if (r < n) mx = max(mx, min(c / 2, n - r));
        }
    }
    if (!pq.empty()) {
        p = pq.top(); pq.pop();
        if (p > 1) mx = max(mx, min(p / 2, c / 2));
    }
    ans = min(ans, mx);
    printf("%d\n", ans);

    close();
    return 0;
}
