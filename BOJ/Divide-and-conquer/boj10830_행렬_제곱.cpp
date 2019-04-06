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
const int MOD = 1000;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

struct matrix {
  int a[5][5], size = 0;
  matrix() { 
    this->size = 0;
    for (int i = 0; i < 5; ++i) 
      for (int j = 0; j < 5; ++j) 
        a[i][j] = 0;
  }
  matrix(int s) {
    this->size = s;
    for (int i = 0; i < s; ++i) 
      for (int j = 0; j < s; ++j) 
        a[i][j] = 0;
  }
  matrix(int s, int *mat[]) {
    this->size = s;
    for (int i = 0; i < s; ++i) 
      for (int j = 0; j < s; ++j)
        a[i][j] = mat[i][j];
  }
};

matrix mul_mat(matrix a, matrix b) {
  matrix ret = matrix(a.size);
  for (int i = 0; i < a.size; ++i)
      for (int j = 0; j < a.size; ++j)
        for (int k = 0; k < a.size; ++k)
          ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
  return ret;
}

void printMatrix(matrix &mat) {
  for (int i = 0; i < mat.size; ++i) {
    for (int j = 0; j < mat.size; ++j) printf("%d ", mat.a[i][j]);
    puts("");
  }
}

matrix _pow(matrix base, ll exp) {
  matrix ret(base.size);
  for (int i = 0; i < base.size; ++i) ret.a[i][i] = 1;
  while (exp) {
    if (exp % 2LL) ret = mul_mat(ret, base);
    base = mul_mat(base, base);
    exp /= 2LL;
  }
  return ret;
}

ll N, B;
int main(int argc, char *argv[]) {
  open();
  
  scanf("%lld %lld", &N, &B);
  matrix mat(N);
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
    scanf("%d", &mat.a[i][j]);

  matrix ans = _pow(mat, B);
  printMatrix(ans);
  return 0;
}