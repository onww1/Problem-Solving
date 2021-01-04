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

int n, k, mn, a[8], t[8], push[8];
vector<int> p[8];

void solve(int idx, int sum) {
    if (idx == k) {
        memcpy(t, a, sizeof(a));
        for (int i = 0; i < k; i++) {
            if (!push[i]) continue;
            for (int num: p[i])
                t[num] += push[i] * (i + 1);
        }
        int val = t[0] % 5;
        for (int i = 1; i < n; i++) {
            if (val != t[i] % 5) {
                val = -1;
                break;
            }
        }
        if (val != -1) mn = sum;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (mn <= sum + i) break;
        push[idx] = i;
        solve(idx + 1, sum + i);
    }
}

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0, len; i < k; i++) {
        scanf("%d", &len);
        p[i].resize(len);
        for (int &c: p[i]) {
            scanf("%d", &c);
            c--;
        }
    }
    mn = INF;
    solve(0, 0);
    printf("%d\n", mn == INF ? -1 : mn);

    close();
    return 0;
}
