#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<ll,ll> pll;

const int MAX = 1e5;
const int INF = 0x7f7f7f7f;

vector <pll> factor;

ll _count(ll n, ll b) {
  ll cnt = 0;
  while (n) {
    cnt += n / b;
    n /= b;
  }
  return cnt;
}

int main(int argc, char *argv[]) {
  ll n, b;
  scanf("%lld %lld", &n, &b);
  for (ll i = 2; i * i <= b; ++i) {
    if (b % i == 0) {
      int cnt = 0;
      while (b % i == 0) {
        ++cnt;
        b /= i;
      }
      factor.push_back({i, cnt});
    }
  }
  if (b > 1) factor.push_back({b, 1});

  ll mn = 2e18;
  for (pll f : factor) {
    mn = min(mn, _count(n, f.first) / f.second);
  }
  return !printf("%lld\n", mn);
}