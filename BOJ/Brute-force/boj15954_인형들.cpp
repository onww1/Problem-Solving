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

const int MAX = 1e5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int N, K;
ll sq[501], a[501];
ldb mn = 1000000.0;
int main(int argc, char *argv[]) {
  open();
  
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", a + i);
    sq[i] = a[i] * a[i];
    a[i] += a[i - 1];
    sq[i] += sq[i - 1];
  }

  for (int i = 0; i <= N - K; ++i) {
    for (int j = i + K; j <= N; ++j) {
      ll nu = (sq[j] - sq[i]) * (j - i) - (a[j] - a[i]) * (a[j] - a[i]);
      ll de = (ll)(j - i) * (j - i);
      mn = min(mn, (ldb)sqrt((ldb)nu / de));
    }
  }

  printf("%.12Lf\n", mn);
  return 0;
}

// V = E(X^2) - (E(X))^2