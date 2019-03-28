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

int N, C[5], X, Y;

int main(int argc, char *argv[]) {
    open();
  
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &X, &Y);
        if (X == 0 || Y == 0) C[0]++;
        else if (X > 0 && Y > 0) C[1]++;
        else if (X < 0 && Y > 0) C[2]++;
        else if (X < 0 && Y < 0) C[3]++;
        else if (X > 0 && Y < 0) C[4]++;
    }

    for (int i = 1; i <= 4; ++i) printf("Q%d: %d\n", i, C[i]);
    printf("AXIS: %d\n", C[0]);

    return 0;
}