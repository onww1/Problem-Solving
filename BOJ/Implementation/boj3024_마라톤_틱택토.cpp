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

int N;
char MAP[30][31];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);
    char winner = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (MAP[i][j] == '.') continue;

            if (j + 2 < N && MAP[i][j] == MAP[i][j + 1] && MAP[i][j] == MAP[i][j + 2]) winner = MAP[i][j];
            else if (i + 2 < N && MAP[i][j] == MAP[i + 1][j] && MAP[i][j] == MAP[i + 2][j]) winner = MAP[i][j];
            else if (i + 2 < N && j + 2 < N && MAP[i][j] == MAP[i + 1][j + 1] && MAP[i][j] == MAP[i + 2][j + 2]) winner = MAP[i][j];
            else if (i + 2 < N && j - 2 >= 0 && MAP[i][j] == MAP[i + 1][j - 1] && MAP[i][j] == MAP[i + 2][j - 2]) winner = MAP[i][j];
        }
        if (winner) break;
    }
  
    if (winner) printf("%c\n", winner);
    else puts("ongoing");
    return 0;
}