#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e3;

struct matrix { 
  ll a[2][2];
  matrix(ll w, ll x, ll y, ll z) {
    a[0][0] = w; a[0][1] = x;
    a[1][0] = y; a[1][1] = z;
  }
  matrix operator* (const matrix &other) {
    ll na[2][2] = {0};
    for (int i = 0; i < 2; ++i) 
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) 
          na[i][j] += (this->a[i][k] * other.a[k][j]);
        na[i][j] %= MOD;
      }
    return matrix(na[0][0], na[0][1], na[1][0], na[1][1]);
  }
};

matrix mat_pow(matrix base, ll exp) {
  matrix ret(1, 0, 0, 1);
  while (exp) {
    if (exp % 2LL) ret = ret * base;
    base = base * base;
    exp /= 2LL;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int t, n;
  matrix base(3, 5, 1, 3);
  scanf("%d", &t);
  for (int test_case = 1; test_case <= t; ++test_case) {
    scanf("%d", &n);
    matrix mat = mat_pow(base, n);
    ll ans = (2 * mat.a[0][0] + 999) % 1000;
    printf("Case #%d: %03lld\n", test_case, ans);
  }
  return 0;
}

