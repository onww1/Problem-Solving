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

const int MAX = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, k, Q, m, a[MAX], s[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &k, &Q, &m);
    for (int i = 0, st; i < k; i++) {
        scanf("%d", &st);
        s[st] = 1;
    }
    queue<int> q;
    for (int i = 0, st; i < Q; i++) {
        scanf("%d", &st);
        if (!s[st]) {
            a[st] = 1;
            q.push(st);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 2 * cur; i <= n + 2; i += cur) 
            if (!s[i] && !a[i]) {
                a[i] = 1;
                q.push(i);
            }
    }

    for (int i = 4; i <= n + 2; i++) a[i] += a[i - 1];
    for (int i = 0, lo, hi; i < m; i++) {
        scanf("%d %d", &lo, &hi);
        printf("%d\n", hi - lo + 1 - a[hi] + a[lo - 1]);
    }

    close();
    return 0;
}
