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

int T, n, p[10005], u, v;

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1, pp, cc; i < n; ++i) {
            scanf("%d %d", &pp, &cc);
            p[cc] = pp;
        }

        scanf("%d %d", &u, &v);
        int du = 0, dv = 0, node = u;
        while (node) {
            du++;
            node = p[node];
        }
        node = v;
        while (node) {
            dv++;
            node = p[node];
        }

        if (du < dv) { swap(du, dv); swap(u, v); }
        while (du > dv) {
            du--;
            u = p[u];
        }
        while (u != v) {
            u = p[u];
            v = p[v];
        }
        printf("%d\n", u);
        for (int i = 1; i <= n; ++i) p[i] = 0;
    }

    close();
    return 0;
}