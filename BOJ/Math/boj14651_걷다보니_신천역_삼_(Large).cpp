#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 9;

ll pow(ll base, ll exp) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2LL) ret = ret * base % MOD;
    base = base * base % MOD;
    exp /= 2LL;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  return !printf("%lld\n", n == 1? 0 : 2LL * pow(3, n - 2) % MOD);
}
