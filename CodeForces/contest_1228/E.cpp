#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#define INF 987654321
#define MOD 998244353
using namespace std;

typedef long long ll;
map<ll, ll> pow_map;
map<ll, ll>::iterator it;

ll my_pow(ll base, ll exp) {
  if (exp == 0) return 1LL;
  if (exp == 1) return base;

  ll res, half;
  if (exp % 2LL) {
    it = pow_map.find(exp/2LL);
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = my_pow(base, exp/2LL);
    }
    res = base * (half * half % MOD) % MOD;
  } else {
    it = pow_map.find(exp/2);
    if (it != pow_map.end()) {
      half = it->second;
    } else {
      half = my_pow(base, exp/2LL);
    }
    res = half * half % MOD;
  }
  pow_map[exp] = res;
  return res;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll p, r, s;
  cin >> p >> s >> r;
  
  

  return 0;
}
