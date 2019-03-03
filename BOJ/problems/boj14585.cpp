#define NON_SUBMIT

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

const int MAX = 300;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, M, DP[MAX + 1][MAX + 1];

int main(int argc, char *argv[]) {
  open();
  
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		DP[x][y] = (M - x - y > 0 ? M - x - y : 0);
	}

	for (int i = 1; i <= MAX; ++i) DP[i][0] += DP[i - 1][0];
	for (int j = 1; j <= MAX; ++j) DP[0][j] += DP[0][j - 1];
	for (int i = 1; i <= MAX; ++i) {
		for (int j = 1; j <= MAX; ++j) {
			DP[i][j] += max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	printf("%d\n", DP[MAX][MAX]);
  return 0;
}