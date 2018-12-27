#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;

map<ll, ll> pow_map;
map<ll, ll>::iterator it;

ll pow(ll base, ll exp) {
  if (exp == 0LL) return 1LL;
  else if (exp == 1LL) return base;

  ll half, res;
  if (exp % 2) {
    it = pow_map.find((exp - 1)/2);
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = pow(base, (exp - 1)/2);
    }
    res = base * (half * half % MOD) % MOD;
  } else {
    it = pow_map.find(exp/2);
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = pow(base, exp/2);
    }
    res = half * half % MOD;
  } 
  pow_map[exp] = res;
  return res;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << 1 << '\n';
  } else {
    ll res = 1LL;
    k = n - k < k ? n - k : k;
    ll fac = 1;
    for (ll i = 2; i <= n; ++i) 
      fac = fac * i % MOD;
    res *= fac;
    ll inv = pow(fac, MOD-2);
    for (ll i = n; i > k; --i) {
      inv = inv * i % MOD;
      if (i == n - k + 1) res = res * inv % MOD;
    }
    res = res * inv % MOD;
    cout << res << '\n';
  } 

  return 0;
}