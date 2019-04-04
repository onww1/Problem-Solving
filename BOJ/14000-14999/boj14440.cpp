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

const int MAX = 100000;
const int MOD = 100;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct matrix {
  int a[2][2];
  matrix() { 
    for (int i = 0; i < 2; ++i) 
      for (int j = 0; j < 2; ++j) 
        a[i][j] = 0;
  }
  matrix(int a11, int a12, int a21, int a22) {
    a[0][0] = a11, a[0][1] = a12;
    a[1][0] = a21, a[1][1] = a22;
  }
};

matrix mul_mat(matrix a, matrix b) {
  matrix ret;
  for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
  return ret;
}

matrix _pow(matrix base, ll exp) {
  matrix ret(1, 0, 0, 1);
  while (exp) {
    if (exp % 2LL) ret = mul_mat(ret, base);
    base = mul_mat(base, base);
    exp /= 2LL;
  }
  return ret;
}

int x, y, a0, a1, n;
int main(int argc, char *argv[]) {
  open();
  
  scanf("%d %d %d %d %d", &x, &y, &a0, &a1, &n);
  matrix base(x, y, 1, 0);
  matrix res = _pow(base, n);
  printf("%02d\n", (res.a[1][0] * a1 + res.a[1][1] * a0) % MOD);
  return 0;
}