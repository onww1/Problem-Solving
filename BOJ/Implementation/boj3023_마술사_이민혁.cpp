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

const int MAX = 50;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

char MAP[2 * MAX][2 * MAX + 1];
int R, C, A, B;

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf(" %s", MAP[i]);
        for (int j = 0; j < C; ++j) sprintf(MAP[i] + C + j, "%c", MAP[i][C - j - 1]);
        MAP[i][2 * C] = 0;
        sprintf(MAP[2 * R - 1 - i], "%s", MAP[i]);
    }
    scanf("%d %d", &A, &B);
    MAP[A - 1][B - 1] = (MAP[A - 1][B - 1] == '#' ? '.' : '#');

    for (int i = 0; i < 2 * R; ++i) printf("%s\n", MAP[i]);
    return 0;
}