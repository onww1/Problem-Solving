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

int N, MAP[128][128], C[2];

int solve(int r, int c, int size) {
    if (size == 1) return MAP[r][c];

    int lu = solve(r, c, size / 2);
    int ld = solve(r + size / 2, c, size / 2);
    int ru = solve(r, c + size / 2, size / 2);
    int rd = solve(r + size / 2, c + size / 2, size / 2);

    if (lu == ld && ld == ru && ru == rd) return lu;
    if (lu != -1) C[lu] += 1;
    if (ld != -1) C[ld] += 1;
    if (ru != -1) C[ru] += 1;
    if (rd != -1) C[rd] += 1;
    return -1;
}

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &MAP[i][j]);
    int val = solve(0, 0, N);
    if (val != -1) C[val] += 1;
    printf("%d\n%d\n", C[0], C[1]);
    return 0;
}