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

int main(int argc, char *argv[]) {
    open();

    char a[11]{}, b[11]{};
    scanf(" %s %s", a, b);
    int alen = strlen(a), blen = strlen(b);
    reverse(a, a + alen);
    reverse(b, b + blen);

    char ansa[11]{}, ansb[11]{};
    int al = 0, bl = 0;

    int i = 0;
    for (; i < alen && i < blen; ++i) {
        if (a[i] < b[i]) ansb[bl++] = b[i];
        else if (a[i] > b[i]) ansa[al++] = a[i];
        else ansa[al++] = a[i], ansb[bl++] = b[i];
    }
    for (; i < alen; ++i) {
        ansa[al++] = a[i];
    }
    for (; i < blen; ++i) {
        ansb[bl++] = b[i];
    }

    while (al > 1 && ansa[al - 1] == '0') ansa[--al] = 0;
    while (bl > 1 && ansb[bl - 1] == '0') ansb[--bl] = 0;

    reverse(ansa, ansa + al);
    reverse(ansb, ansb + bl);

    if (al == 0) puts("YODA");
    else printf("%s\n", ansa);

    if (bl == 0) puts("YODA");
    else printf("%s\n", ansb);

    close();
    return 0;
}
