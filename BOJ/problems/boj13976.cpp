#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

struct matrix {
  ll mat[2][2];
  matrix() { mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0; }
  matrix(int a11, int a12, int a21, int a22) {
    mat[0][0] = a11; mat[0][1] = a12;
    mat[1][0] = a21; mat[1][1] = a22;
  }
};

matrix mat_mul(matrix a, matrix b) {
  matrix ret;
  for (int i = 0; i < 2; ++i) 
    for (int j = 0; j < 2; ++j) 
      for (int k = 0; k < 2; ++k) 
        ret.mat[i][j] += (a.mat[i][k] * b.mat[k][j] + MOD * MOD) % MOD;
  return ret;
}

matrix mat_pow(matrix base, ll exp) {
  matrix ret(1, 0, 0, 1);
  while (exp) {
    if (exp % 2LL) ret = mat_mul(ret, base);
    base = mat_mul(base, base);
    exp /= 2LL;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  ll n, ans = 0LL;
  scanf("%lld", &n);
  if (n % 2LL == 0) {
    matrix base(4, MOD - 1, 1, 0);
    matrix res = mat_pow(base, n / 2LL - 1LL);
    ans = (res.mat[0][0] * 3LL + res.mat[0][1] * 1LL + MOD * MOD) % MOD;
  }
  return !printf("%lld\n", ans);
}
