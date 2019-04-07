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

const int MAX = 5000;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

vector <int> point[MAX + 1];
ll N, ans = 0;
int main(int argc, char *argv[]) {
  open();

  scanf("%lld", &N);
  for (int i = 0; i < N; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    point[y].push_back(x);
  }

  for (int i = 1; i <= MAX; ++i) {
    sort(point[i].begin(), point[i].end());
    for (int j = 0; j < point[i].size(); ++j) {
      if (j == 0) ans += (point[i][1] - point[i][0]);
      else if (j == point[i].size() - 1) ans += (point[i][point[i].size() - 1] - point[i][point[i].size() - 2]);
      else ans += min(point[i][j] - point[i][j - 1], point[i][j + 1] - point[i][j]);
    }
  }

  printf("%lld\n", ans);
  return 0;
}