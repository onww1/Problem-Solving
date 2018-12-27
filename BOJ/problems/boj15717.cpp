#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;

typedef long long ll;
map<ll, ll> pow_map;
map<ll, ll>::iterator it;

ll pow(ll base, ll exp) {
  if (exp == 0) return 1LL;
  else if (exp == 1) return base;

  if (exp % 2) {
    it = pow_map.find((exp - 1)/2);
    ll half;
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = pow(base, (exp - 1) / 2);
    }
    return (base * ((half * half) % MOD)) % MOD;
  } else {
    it = pow_map.find(exp/2);
    ll half;
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = pow(base, exp / 2);
    }
    return (half * half) % MOD;
  }
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N;
  cin >> N;
  if (N == 0) cout << 1 << '\n';
  else {
    cout << pow(2LL, N-1) << '\n';
  }
  return 0;
}