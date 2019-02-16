#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll _gcd(ll a, ll b) { return b ? _gcd(b, a % b) : a; }
ll _lcm(ll a, ll b) { return a / _gcd(a, b) * b; }

struct rational {
  ll numerator, denominator;
  rational() { numerator = 0, denominator = 1; }
  rational(ll nu) { numerator = nu, denominator = 1; }
  rational(ll nu, ll de) { 
    ll GCD = _gcd(abs(nu), de);
    numerator = nu / GCD;
    denominator = de / GCD; 
  }

  rational operator+ (const rational &other) {
    ll LCM = _lcm(this->denominator, other.denominator);
    ll nu = this->numerator * LCM / this->denominator + other.numerator * LCM / other.denominator;
    return rational(nu, LCM);
  }
  rational operator- (const rational &other) {
    ll LCM = _lcm(this->denominator, other.denominator);
    ll nu = this->numerator * LCM / this->denominator - other.numerator * LCM / other.denominator;
    return rational(nu, LCM);
  }
  rational operator* (const rational &other) {
    return rational(this->numerator * other.numerator, this->denominator * other.denominator);
  }
  rational operator/ (const rational &other) {
    return rational(this->numerator * other.denominator, this->denominator * other.numerator);
  }
};

pii a[51];
int main(int argc, char *argv[]) {
  int n, i, s, e;
  scanf("%d", &n);
  for (i = 0; i <= n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
  scanf("%d %d", &s, &e);

  rational sh, eh; 
  for (i = 0; i < n; ++i) {
    if (s == a[i].first) sh = rational(a[i].second);
    else if (a[i].first < s && s < a[i+1].first) 
      sh = rational((a[i+1].second - a[i].second) * (s - a[i].first), a[i+1].first - a[i].first) + rational(a[i].second);
    
    if (e == a[i].first) eh = rational(a[i].second);
    else if (a[i].first < e && e < a[i+1].first) 
      eh = rational((a[i+1].second - a[i].second) * (e - a[i].first), a[i+1].first - a[i].first) + rational(a[i].second);
  }
  if (e == a[n].first) eh = rational(a[n].second);

  rational res = (eh - sh) / rational(e - s);
  if (res.denominator == 1) return !printf("%lld\n", abs(res.numerator));
  return !printf("%lld/%lld\n", abs(res.numerator), res.denominator);
}

