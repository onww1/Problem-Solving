#include <cstdio>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
ll a, b, c, d, s;
int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  a = 1LL, b = 2LL, c = 7LL, d = 22LL;
  for (i = 0; i < n; ++i) {
    a = b, b = c, c = d;
    d = (3LL * c + b - a + MOD) % MOD;
  }
  return !printf("%lld\n", a);
}
