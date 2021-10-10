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

const int MAX = 3e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, k, h, t, cost[MAX];
char in[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %s", &n, &k, in);
    for (int i = 0; i < n; i++) {
        if (in[i] == 'H') h++;
        else t++;
    }
    memset(cost, -1, sizeof(cost));
    
    queue<int> q;
    q.push(h);
    cost[h] = 0;

    while (!q.empty()) {
        int curH = q.front(); q.pop();
        for (int i = 0; i <= k; i++) {
            if (i > curH || k - i > n - curH) continue;
            int dh = curH + k - 2 * i;
            if (cost[dh] != -1) continue;
            cost[dh] = cost[curH] + 1;
            q.push(dh);
        }
    }

    printf("%d\n", cost[0]);

    close();
    return 0;
}