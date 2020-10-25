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

int istat[11], stat[11], mask, ans, cnt;
char in[15];

void toggle(int r, int c) {
    if (r > 0) stat[r - 1] ^= (1 << c);
    if (c - 1 < 0) stat[r] ^= (7 >> (1 - c));
    else stat[r] ^= (7 << (c - 1));
    stat[r] &= mask;
    if (r < 10) stat[r + 1] ^= (1 << c);
}

void init() {
    for (int i = 1; i <= 10; i++) stat[i] = istat[i];
    cnt = 0;
}

int main(int argc, char *argv[]) {
    open();

    for (int i = 1; i <= 10; i++) {
        scanf(" %s", in);
        for (int j = 0; j < 10; j++) 
            if (in[j] == 'O') 
                istat[i] |= (1 << j);
    }
    mask = (1 << 10) - 1; ans = INF;

    int lim = 1 << 10;
    for (int i = 0; i < lim; i++) {
        init();
        stat[0] = i;
        for (int j = 1; j <= 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (stat[j - 1] & (1 << k)) {
                    cnt++;
                    toggle(j, k);
                }
            }
        }
        if (!stat[10]) ans = min(ans, cnt);
    }
    
    printf("%d\n", ans == INF ? -1 : ans);

    close();
    return 0;
}
