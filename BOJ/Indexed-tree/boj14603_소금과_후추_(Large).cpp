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

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, m, k, w, a[301][301], b[301][301], tree[2 * SZ];

void update(int node, int val) {
    node += SZ;
    while (node) {
        tree[node] += val;
        node >>= 1;
    }
}

int kth(int k) {
    int node = 1;
    while (node < SZ) {
        if (k > tree[node * 2]) {
            k -= tree[node * 2];
            node = node * 2 + 1;
        }
        else node = node * 2;
    }
    return node - SZ;
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            scanf("%d", a[i] + j);

    int median = (w * w + 1) / 2;
    for (int i = 1; i <= w; ++i)
        for (int j = 1; j <= w; ++j)
            update(a[i][j], 1);
    b[1][1] = kth(median);

    for (int i = 1, j; i <= n - w + 1; ++i) {
        if (i % 2) {
            for (j = 2; j <= m - w + 1; ++j) {
                for (int k = 0; k < w; ++k) {
                    update(a[i + k][j + w - 1], 1);
                    update(a[i + k][j - 1], -1);   
                }
                b[i][j] = kth(median);
            }
            --j;
        }
        else {
            for (j = m - w; j > 0; --j) {
                for (int k = 0; k < w; ++k) {
                    update(a[i + k][j], 1);
                    update(a[i + k][j + w], -1);   
                }
                b[i][j] = kth(median);
            }
            ++j;
        }
        if (i < n - w + 1) {
            for (int k = 0; k < w; ++k) {
                update(a[i + w][j + k], 1);
                update(a[i][j + k], -1);
            }
            b[i + 1][j] = kth(median);
        }
    }

    for (int i = 1; i <= n - w + 1; ++i) {
        for (int j = 1; j <= m - w + 1; ++j) {
            printf("%d ", b[i][j]);
        }
        puts("");
    }

    close();
    return 0;
}