#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007LL
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int main(int argc, char *argv[]) {
  vector<ll> fun;
  ll n, i;

  scanf("%lld", &n);
  fun.push_back(n * (n+1) / 2);
  fun.push_back(1);
  for (i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      fun.push_back((n / i) + (n / i) * (n - i) / 2);
      if (i * i != n) {
        fun.push_back(i + i * (n - (n / i)) / 2);
      }
    }
  }

  sort(fun.begin(), fun.end());
  for (auto &it : fun) {
    printf("%lld ", it);
  }
  printf("\n");
  return 0;
}

ll get_pow(ll base, ll exp) {
  ll ret = 1;
  while (exp > 0) {
    if (exp % 2) {
      ret *= base;
      ret %= MOD;
    }
    base *= base;
    base %= MOD;
    exp /= 2;
  }
  return ret;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }


