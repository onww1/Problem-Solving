#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
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
typedef pair<int, pii> piii;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
}

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int T, N, L;
char in[10];

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", in);
        for (N = L = 0; in[L]; ++L);
        for (int i = 0; i < L; ++i) N = N * 10 + in[i] + in[L - i - 1] - 2 * '0';
        for (L = 0; N; N /= 10) { in[L++] = N % 10; }
        for (int i = 0; i < L / 2; ++i) if (in[i] != in[L - 1 - i]) N = 1;
        puts(N ? "NO" : "YES");
    }

    return 0;
}