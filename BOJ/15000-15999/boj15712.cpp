#include <cstdio>
using namespace std;
typedef long long ll;

ll get_pow(ll base, ll exp, ll mod) {
  ll ret = 1LL;
  while (exp) {
    if (exp % 2) {
      ret *= base;
      ret %= mod;
    }
    base *= base;
    base %= mod;
    exp /= 2LL;
  }
  return ret;
}

ll solve(ll r, ll n, ll mod) {
  if (n == 1LL) return 1LL;
  ll ret = 0LL, half;
  if (n % 2) ret += get_pow(r, n-1, mod);
  half = solve(r, n/2LL, mod);
  ret = (ret + (get_pow(r, n/2LL, mod) * half % mod)) % mod;
  ret = (ret + half) % mod;
  return ret;
}

int main(int argc, char *argv[]) {
  ll a, r, n, mod;
  scanf("%lld %lld %lld %lld", &a, &r, &n, &mod);
  return !printf("%lld\n", r == 1LL ? a * n % mod : a * solve(r, n, mod) % mod);
}